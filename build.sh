
# make the .build directory if it doesn't already exist
if [ -d ".build" ]; then
    rm -rf .build/*
else
    mkdir .build
fi

# generate Cython binaries first for development
# purposes
# gcc -Os -I /usr/include/python3.6 example.c -lpython3.6 -o .build/devscripts/example
mkdir .build/devscripts
mkdir .build/devscripts/c
mkdir .build/devscripts/bin

for pysrc in devscripts/*.py
do
    cython --embed -o .build/devscripts/c/$(basename ${pysrc%.*}).c $pysrc 
done

# this handles the C sources
if [ -d "Makefile" ]; then
    make
fi