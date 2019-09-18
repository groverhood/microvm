
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <m86def.h>

struct mas_args_t {
    const char *fsrc;
    const char *fdest;

    int help;
    int verbose;
};

#define strtok_r __strtok_r

typedef struct mas_error mas_error_t;

static int argparse(int argc, char *argv[], struct mas_args_t *restrict args);

static void help(void);

static int errc(void);

static mas_error_t* gerr(int which);

static int assemble(const char *fsrc, char **dest, size_t *written, int verbose);

int main(int argc, char *argv[]) {
    const char *invocation = argv[0];
    struct mas_args_t args;

    argparse(argc, argv, &args);

    if (args.help) {
        help();
    }

    if (args.fsrc) {
        char *buf;
        size_t nbytes;

        int err = assemble(args.fsrc, &buf, &nbytes, args.verbose);

        FILE *fp = fopen(args.fdest, "w+");
        fwrite(buf, sizeof(uint8_t), nbytes, fp);
        fflush(fp);
        fclose(fp);
    }
    
    return 0;
}

static int argparse(int argc, char *argv[], struct mas_args_t *restrict args) {
    args->fsrc = NULL;
    args->fdest = NULL;
    args->verbose = 0;
    args->help = 0;

    int success = 1;

    while (argc) {
        char *arg = *argv++;
        argc--;

        if (!strcmp(arg, "-h") || !strcmp(arg, "--help")) {
            args->help = 1;
        } else if (!strcmp(arg, "-o") || !strcmp(arg, "--out")) {
            argc--;
            char *fdest = *argv++;
            args->fdest = fdest;
        } else if (!strcmp(arg, "-v") || !strcmp(arg, "--verbose")) {
            args->verbose = 1;
        } else {
            args->fsrc = arg;
        }
    }

    return success;
}

static void help(void) {
    puts("Usage: mas [options] file\n"
         "Options\n"
         "\t-h, --help\t\t\tDisplay this information.\n"
         "\t-o, --out\t\t\tSpecify an output file, a.mbn by default.\n"
         "\t-v, --verbose\t\t\tPrint debug output.");
}

#define MAS_MAX_ERRORC 16

static struct mas_error {
    size_t line, col;
    const char *what;
    int why;
} errors[MAS_MAX_ERRORC];

static int error_count = 0;

static int errc(void) {
    return error_count;
}

static mas_error_t* gerr(int which) {
    mas_error_t *result = (which >= error_count) ? NULL : (errors + which);
    return result;
}

static int assemble_line(char *line, int verbose, FILE *out);

static int assemble(const char *fsrc, char **dest, size_t *written, int verbose) {
    struct stat fsrc_st;
    char *fct = NULL;
    int err = 0;

    if (!stat(fsrc, &fsrc_st)) {
        if (verbose) {
            printf("Loading input file %s...\n", fsrc);
        }

        fct = malloc(fsrc_st.st_size);
        FILE *fp = fopen(fsrc, "r");
        fread(fct, 1, fsrc_st.st_size, fp);
        fclose(fp);
    }

    if (fct) {
        FILE *sstream = open_memstream(dest, written);
        char *line_context;
        char *line = strtok_r(fct, "\n", &line_context);
        size_t line_nm = 0;

        while (line) {
            err = err || assemble_line(line, verbose, sstream);

            if (error_count == MAS_MAX_ERRORC) {
                puts("Too many errors detected, terminating assembly.");
                break;
            }

            line_nm++;
            line = strtok_r(NULL, "\n", &line_context);
        }

        fflush(sstream);
        fclose(sstream);
        free(fct);
    }
}

static int assemble_line(char *line, int verbose, FILE *out) {
    char *context;
    char *tok = strtok_r(line, " \t", &context);

    if (!strcmp(tok, "halt")) {
        putc(M86_INSTR_HALT, out);
    }
}