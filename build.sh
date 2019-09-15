#!/bin/bash

# make the .build directory if it doesn't already exist
if [ -d ".build" ]; then
    rm -rf build-microvm/*
else
    mkdir build-microvm
fi

# configure the devscripts to run simply by entering their
# name
python3 setup.py install --user rotate -m .egg -k 1

source ~/.bash_profile

genfproto -o inc/m86fproto.h
gendefs -o inc/m86def.h

# this handles the C sources
if [ -d "Makefile" ]; then
    make
fi