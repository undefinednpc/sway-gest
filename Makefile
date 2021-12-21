CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wextra `pkg-config --cflags --libs libudev libinput json-c`

sway-gest: main.c
	$(CC) -o sway-gest main.c $(CFLAGS)

clean:
	rm -f sway-gest

install:
	sudo cp sway-gest /usr/local/bin/sway-gest

uninstall:
	sudo rm -f /usr/local/bin/sway-gest
