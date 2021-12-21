CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wextra `pkg-config --cflags --libs libudev libinput json-c`

sway-gest: main.c
	$(CC) -o sway_gest main.c $(CFLAGS)

clean:
	rm -f sway_gest
