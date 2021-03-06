#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <sys/socket.h>

#include <json-c/json_object.h>

#include <libinput.h>
#include <libudev.h>

#define FALSE 0
#define TRUE 1

typedef enum { RIGHT, LEFT } Direction;

static int open_restricted(const char *path, int flags, void *user_data)
{
	int fd = open(path, flags);
	return fd < 0 ? -errno : fd;
}

static void close_restricted(int fd, void *user_data)
{
	close(fd);
}

static const struct libinput_interface interface = {
	.open_restricted = open_restricted,
	.close_restricted = close_restricted,
};

Direction get_gesture_direction(struct libinput_event_gesture *event) 
{
	if(libinput_event_gesture_get_dx(event) > 0) {
		return RIGHT;
	}
	else {
		return LEFT;
	}
}

static void sway_workspace_left()
{
	assert(!"Not Implemented");
}

static void sway_workspace_right()
{
	assert(!"Not Implemented");	
}

int main()
{
	struct libinput *li;
	struct libinput_event *event;
	struct libinput_event_gesture *gesture;
	struct udev *udev;

	int gesture_ongoing = FALSE;

	udev = udev_new();	

	li = libinput_udev_create_context(&interface, 0, udev);
	libinput_udev_assign_seat(li, "seat0");
	libinput_dispatch(li);

	while ((event = libinput_get_event(li)) != 0) {

		switch(libinput_event_get_type(event)) {
			case LIBINPUT_EVENT_GESTURE_SWIPE_BEGIN:
				gesture_ongoing = TRUE;
				gesture = libinput_event_get_gesture_event(event);
				switch(get_gesture_direction(gesture)) {
					case LEFT:
						sway_workspace_left();
						break;
					case RIGHT:
						sway_workspace_right();
						break;
				}
		}

		libinput_event_destroy(event);
		libinput_dispatch(li);
	}

	libinput_unref(li);
	udev_unref(udev);

	return 0;
}
