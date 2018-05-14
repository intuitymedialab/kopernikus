# Kopernikus Documentation

*an experimental prototyping platform to test and evaluate the vision of home robotics*

Developed at Intuity Media Lab GmbH in Stuttgart, Germany.

![Kopernikus Total](http://aaiirr.net/content/projects/kopernikuswide.jpg "Kopernikus Total")


## 🔬 What this is about

Robots will become an integral part of our daily lives. Artificial Intelligence changes the way we interact with technology fundamentally and what once used to be a tool sonn will become a companion. As a transdisciplinary team, equipped with diverse expertise, we we realized that only practical experiments will help us gain true insights. We’ve learned that we need to build tools for each other, to make one benefit from another’s skill.

In the last year we've been working on prototypes, made of accessible technologies, to explore the potential of behavioural interfaces.

-----

This is one of the results of this project:

**Kopernikus**, an experimental prototyping platform to test and evaluate the vision of home robotics.

-----

Kopernikus is **mobile**. He can make **sounds**.He can **project** visuals onto the wall. He can **see**. He can **hear**. And he is connected to the **web**.

He is built of low priced electronic components, that can easily be found online. All the structural parts can be either 3D-printed or machined with accessible tools.
We decided to open source our plans to enable other people (be it students, scientists oder designers) to work with the tools we have built on our way.


## 📓 A little backstory

While designing and building this robot we got in contact with an AI research team from another city. We got to know each other and decided it would be great to work together - so we built the robot mainly for them. In order to be able to debug hardware and software problems more easily (without the need to always travel to each others location) we decided to build two identical robots. NASA does a similar thing - they have an exact replica of the ships they send into space down at earth so they can (more or less) easily develop solutions to upcoming problems.

That's why we decided to call this prototype *DYLAN* - derived from D.I.L.N. which is short for 'do it like NASA'.

## 💪 What you will be able to do

We wanted to create a platform that allows us to iterate fast. That's why we decided that we needed some "breakpoints" at which different people could start working without having to wait for the others.

For example we implemented a radio control so we could drive around with the robot without having to code certain movement patterns. No component is dependent on the other and so you can configure it to your likings/needs.

Fully loaded, DYLAN offers the following hardware capabilities:

* 3D imaging
* mobile projection mapping (up to a certain extent)
* 3 channel audio input (good for locating sound sources)
* audio playback
* mobile, untethered use for about an hour(...ish - depends on your use)

## 🎒 What you will need

**Quick disclaimer:** *One of our main goals was to build DYLAN as both low-budget and easy-to-use as possible. At some points compromises had to be made in order to a) stay in a reasonable budget or b) make it easy to assemble and use. We are open to suggestions in any way!*

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

In order to get everything together we went with a round base plate (in size similar to vacuum cleaning robots) with some mounting holes in a grid and 3D printed parts made from PLA on an Ultimaker (which means, you can basically print them on any basic FDM printer).

Both part groups were designed with quite broad tolerances so you shouldn't have that big of a problem to make it all fit together nicely.

The shielding for the projector out of acrylic glass is optional - its mainly meant to protect the projector from dust and physical damage. We will upload a 3D file without the mounts for it later.

## Getting started

For getting started head over to the specific readmes on [Software](Software/README.md) and [Hardware](Hardware/README.md).

## License

This project is released under the MIT License - you are free to do whatever you want with it - as long as you don't plan on subdueing humanity or any other crazy stuff, we're fine with it.

You are not legally bound to it, but it would be nice if you credit this project when creating something with it - and please **tell us**! We would love to see what you create!

If you should encounter any bugs or problems with the current build, open an issue here on Github.