# Kopernikus Software Documentation

*an experimental prototyping platform to test and evaluate the vision of home robotics*

Developed at Intuity Media Lab GmbH in Stuttgart, Germany.

## Overview

There are two software packages needed
1) Arduino
2) UpBoard

## 🤖 Arduino Code

The Arduino is used for everything hardware related. This includes:
* Controlling the motors and reading their encoder values
* Receiving RC commands
* Controlling the servo
* Talking to the UpBoard via a serial protocol

### Libraries

We rely on some libraries that you will need to install prior to flashing the Arduino:
* ServoTimer2
* CommandHandler
-> 
* EnableInterrupt
-> [GitHub Repo](https://github.com/GreyGnome/EnableInterrupt)
* AltSoftSerial

They are all available through the Libary Manager included in the Arduino IDE.

### Flashing the Arduino

Getting the Arduino ready should be pretty straight-forward:

1) Download the [Arduino IDE](https://www.arduino.cc/en/Main/Software)
2) Download our files
3) Install the necessary libraries
4) Choose the appropriate board settings
5) Upload 🚀


## 💻 UpBoard

The UpBoard is a x86 based single board computer, so we are able to run a fully-fledged Ubuntu distro on it and thus write code in all kinds of environments.

For camera input we 

### Setup

Getting the UpBoard set up properly might be a bit finicky or at least different when you come from a background mainly working with Raspberry Pis. Some packages and kernel versions are not compatible with the latest Ubuntu so better stick with [Ubuntu 16.04 (Xenial Xerus)](http://releases.ubuntu.com/16.04/).

Also make sure you [install the kernel updates](https://wiki.up-community.org/Ubuntu#Install_Ubuntu_kernel_for_UP_from_PPA) for the board afterwards!


### Software packages

#### Ubuntu Software Packages

These packages can be install via APT using the following commands:

```
sudo apt-get install "package name"

// so something like this:

sudo apt-get install git
```
* git, gitk, git-gui (Git)
* mplayer (Media Player)
* audacity (Audacity for recording sound)
* default-jre (Java)

The main software responsible for decision making is written in Clojure. Head over to the specific readMe for further documentation.

#### Camera

The camera supports ROS as the main interface. Therefore we use ROS to connect the camera to Clojure. It would be possible also to run the serial connection to the base over ROS, but since ROS is such a pain, it seems better to use it only when necessary.

