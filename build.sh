#/bin/sh

gcc -o sway-gest main.c `pkg-config --cflags --libs libinput libudev`
