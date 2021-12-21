#/bin/sh

if [ -d "bin/" ]; then
	gcc -o sway-gest main.c `pkg-config --cflags --libs libinput libudev`
	mv sway-gest bin/
	echo "Binary was generated to bin/"
else
	gcc -o sway-gest main.c `pkg-config --cflags --libs libinput libudev`
	mkdir bin
	echo "Created bin folder"
	mv sway-gest bin/
	echo "Binary was generated to bin/"
fi
