# sway-gest [WIP - Not in usable state yet]
**Utility to enable workspace switching with touchpad gestures in Sway.**

Touchpad gestures are supposed to be included in Sway 1.7 (pull request [here](https://github.com/swaywm/sway/pull/4952)).

I thought this could be fun project anyways, to practice C. I will probably archive it once gestures are official.

## Building
You will need those packages (modify the names accordingly to your distribution, I'm on Void)
* `pkg-config`
* `libudev-devel`
* `libinput-devel`
* `json-c-devel`

Then just:
```
git clone https://github.com/undefinednpc/sway-gest
cd sway-gest
chmod +x build.sh
./build.sh
```
Move the generated binary from bin to whatever location you want.
You can then add `exec sway-gest` to the Sway config. (Again, once it's usable.)
