#!/bin/sh

# Remove the library
if [[ -f "/usr/local/lib/libdynamic.a" ]]; then
	rm "/usr/local/lib/libdynamic.a"
fi

# Remove the include folder
if [[ -d "/usr/local/include/dynamic" ]]; then
	rm -dr "/usr/local/include/dynamic"
fi
