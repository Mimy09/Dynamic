#!/bin/sh

# Make the lib and includes
make clean; make all-rel; make lib

# Copy over the lib
cp ./build/libdynamic.a /usr/local/lib/

# Make the dynamic folder if it doen't exist
# If it does exist, remove its current content
if [[ ! -d "/usr/local/include/dynamic" ]]; then
	mkdir "/usr/local/include/dynamic"
else
	rm -r /usr/local/include/dynamic/*
fi

# Copy over the includes
cp -r ./build/inc/src/* /usr/local/include/dynamic/

# Clean up the write protected build files
make clean; make all-dbg; make lib

# Copy over the debug lib
cp ./build/libdynamic.a /usr/local/lib/libdynamic-dbg.a

# Clean up the write protected build files
make clean
