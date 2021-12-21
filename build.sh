#!/bin/bash

FLAGS= -std=c99 -pedantic -Werror -Wextra -I/usr/include/json-c -linput -ludev -ljson-c
echo $FLAGS

install() {
	cp bin/sway_gest /usr/local/bin/sway_gest
	echo "sway-gest was installed"
}

build() {
	if [ -d "bin/" ]; then
		gcc -o sway-gest main.c $(FLAGS)
		mv sway-gest bin/
		echo "Binary was generated to bin/"
	else
		gcc -o sway-gest main.c $(FLAGS)
		mkdir bin
		echo "Created bin folder"
		mv sway-gest bin/
		echo "Binary was generated to bin/"
	fi
}

if [ "$1" = "build" ]; then
	build
	exit 0
elif [ "$1" = "install" ]; then
	install
	exit 0
else
	echo "Usage: ./build.sh build or ./build.sh install"
fi
