#!/bin/sh

# Make the lib and includes
make clean; make all-rel; make lib

# Copy over the lib
cp ./build/libdynamic.a /usr/lib/

# Make the dynamic folder if it doen't exist
# If it does exist, remove its current content
if [[ ! -d "/usr/include/dynamic" ]]; then
	mkdir "/usr/include/dynamic"
else
	rm -r /usr/include/dynamic/*
fi

# Copy over the includes
cp -r ./build/inc/src/* /usr/include/dynamic/

# Clean up the write protected build files
make clean; make all-dbg; make lib

# Copy over the debug lib
cp ./build/libdynamic.a /usr/lib/libdynamic-dbg.a

# Clean up the write protected build files
make clean
