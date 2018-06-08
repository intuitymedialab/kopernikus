# Kopernikus Documentation

*an experimental prototyping platform to test and evaluate the vision of home robotics*

Developed at Intuity Media Lab GmbH in Stuttgart, Germany.

![Kopernikus Total](http://aaiirr.net/content/projects/kopernikuswide.jpg "Kopernikus Total")

## 🤔 Wait, what?

For a high level overview of the project, visit www.kopernikus.bot.


## 🔬 What this is about

Kopernikus is a small robot, that will cost less than EUR1000 to build. If you put it together, you will have something like a remote control car, equipped with a quad core computer, a stereo camera, audio input and output and a video projector.
You'll be able to use it as a basic setup and build your personal project on top.

## 📓 A little backstory

The vision of home robotics is ubiquitous. As a transdisciplinary team of designers, technologists and researchers, we were looking for a way to prototype the concepts we've been working on.

The question becomes: how do you design AI? How can we build behavioural interfaces?

We want future robots to navigate through our apartments savely, in a manner that is understandable and predictable for humans. We want them to deal gracefully with unexpected obstacles and be efficient and save. 

One of our key interests is Heuristic Problem Solving, which uses concepts from cognitive science to implement a decision process similar to that of humans (You can read up on HPS <a href="https://easychair.org/publications/open/z2d">here</a>, a Paper by our team member Alexandra Kirsch). Our goal is to use HPS as a general, cognitively inspired decision-making framework and use Kopernikus as a use case and testing environment to gain insights through practical experiences. 

That's why Kopernikus is an experimental prototyping platform to test and evaluate the vision of home robotics.



## 💪 What you will be able to do

Fully loaded, DYLAN offers the following hardware capabilities:

* 3D imaging
* mobile projection mapping (up to a certain extent)
* 3 channel audio input (good for locating sound sources)
* audio playback
* mobile, untethered use for about an hour(...ish - depends on your use)

## 🎒 What you will need

**Quick disclaimer:** *One of our main goals was to build Kopernikus as both low-budget and easy-to-use as possible. At some points compromises had to be made in order to a) stay in a reasonable budget or b) make it easy to assemble and use. We are open to suggestions in any way!*

All of the components can be bought online on Amazon, eBay, Banggood, Mouser etc. - prices might vary.

This is just a rough rundown of what key components were used so you get the idea. Check out the [parts list](Hardware/partsList.md) for a more detailled list with links.


#### 💻 Computing
* UpBoard
* Arduino Uno

#### 👀 Input
* RealSense R200
* USB Microphones
* RC Receiver

#### 🐸 Output
* RD02 Robotic Drive System
* Servo Motor
* Anker Soundcore
* USB soundcard
* PicoPro Projector

#### ⚡️ Power
* Laptop Powerbank

### Custom Parts

In order to hold everything together we went with a round base plate (in size similar to vacuum cleaning robots) with some mounting holes in a grid and 3D printed parts made from PLA. We used an Ultimaker 3 - which means, you can basically print them on any basic FDM printer.

Most parts were designed with quite broad tolerances so you shouldn't have that big of a problem to make it all fit together nicely.

The shielding for the projector out of acrylic glass is optional - its mainly meant to protect the projector from dust and physical damage (and because we liked the look to be honest 😎). We will upload a 3D file without the mounts for it later.

## Getting started

For getting started head over to the specific readmes on [Software](Software/README.md) and [Hardware](Hardware/README.md).

## TODO

* [x] Prepare 3D files for milling
* [ ] Create schematic
* [x] Create 3D files for milling

## License

This project is released under the MIT License - you are free to do whatever you want with it - as long as you don't plan on subdueing humanity or any other crazy stuff, we're fine with it.

You are not legally bound to it, but it would be nice if you credit this project when creating something with it - and please **tell us**! We would love to see what you create!

If you should encounter any bugs or problems with the current build, open an issue here on Github.

## ❤️ Thank you 

Just some acknowledgements to some people that (unknowingly) helped make this possible:

[Ryan Boland](https://ryanboland.com/blog) who had a great [tutorial](https://ryanboland.com/blog/reading-rc-receiver-values/) online on how to use interrupts to read PWM-signals (insted of using the **blocking** pulseIn()-method).
