#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>

#include <json-c/json_object.h>

#include <libinput.h>
#include <libudev.h>

static int open_restricted(const char *path, int flags, void *user_data)
{
	int fd = open(path, flags);
	return fd < 0 ? -errno : fd;
}

static void close_restricted(int fd, void *user_data)
{
	close(fd);
}

const static struct libinput_interface interface = {
	.open_restricted = open_restricted,
	.close_restricted = close_restricted,
};

int main()
{
	struct libinput *li;
	struct libinput_event *event;
	struct udev *udev;

	udev = udev_new();

	li = libinput_udev_create_context(&interface, 0, udev);
	libinput_udev_assign_seat(li, "seat0");
	libinput_dispatch(li);

	while ((event = libinput_get_event(li)) != 0) {

		libinput_event_destroy(event);
		libinput_dispatch(li);
	}

	libinput_unref(li);
	udev_unref(udev);

	return 0;
}
