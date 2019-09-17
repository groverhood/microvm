
#include <m86def.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct mas_args_t {
    const char *fsrc;
    const char *fdest;

    int help;
    int verbose;
};

typedef int mas_error_t;

static int argparse(int argc, char *argv[], struct mas_args_t *restrict args);

static void help(void);

static mas_error_t assemble(const char *fsrc, uint8_t **dest, size_t *written, int verbose);

int main(int argc, char *argv[]) {
    const char *invocation = argv[0];
    struct mas_args_t args;

    argparse(argc, argv, &args);

    if (args.help) {
        help();
    }

    uint8_t *buf;
    size_t nbytes;

    mas_error_t errn = assemble(args.fsrc, &buf, &nbytes, args.verbose);

    FILE *fp = fopen(args.fdest, "w+");
    fwrite(buf, sizeof(uint8_t), nbytes, fp);
    fflush(fp);
    fclose(fp);
    
    return 0;
}

static int argparse(int argc, char *argv[], struct mas_args_t *restrict args) {

}

static void help(void) {

}

#define GO_INITVAL 0

static mas_error_t assemble(const char *fsrc, uint8_t **dest, size_t *written, int verbose) {
    struct stat fsrc_st;
    char *fct = NULL;

    if(!stat(fsrc, &fsrc_st)) {
        fct = malloc(fsrc_st.st_size);
        FILE *fp = fopen(fsrc, "r");
        fread(fct, 1, fsrc_st.st_size, fp);
        fclose(fp);
    }

    if (fct) {
        int go = GO_INITVAL;
        while (go) {

        }
    }
}