# Kopernikus Software Documentation

*an experimental prototyping platform to test and evaluate the vision of home robotics*

Developed at Intuity Media Lab GmbH in Stuttgart, Germany.

## Overview

Let's divide this up into ~~two~~ three parts:
1) Parts list
2) Assembly
3) Connecting everything

## 🛠 Fabrication

As mentioned before, all parts can be either 3D-printed or produced on a laser cutter / CNC mill.

### 3D printed parts

The parts were printed on an Ultimaker 3 in our office, but any FDM printer should produce similar results.
The models were created for printing them directly onto the build plate with as little support as possible to create one even reference surface.
The layer height was 0.1mm on finer objects and 0.3mm on the rough stuff.


### Machined parts

We used 5mm PVC for our base plate and the controller plate. We wouldnt recommend going a lot thinner, but 4mm should be fine too.
Using acrylic glass instead of PVC shouldn't be a problem either, we just had it laying around already.

---

⚠️ **Especially when using a laser cutter, stay away from PVC since it creates toxic fumes when cut!** ⚠️

---

## 🔌 Connect all the things!

Refer to [this](components/basic_electronic_connections.pdf?raw=true) plan on how to connect everything. Fitting all wires into the plan would probably have been to big and unnecessary - it's actually quite simple.

The pin mappings on the Arduino are:

```
Pin mappings Arduino:

RC_CH1_INPUT     - >    5
RC_CH2_INPUT     - >    6
RC_CH3_INPUT     - >    7
RC_CH4_INPUT     - >    4 
SERVO PIN        - >   11
RX               - >   10
TX               - >    9
```

### Power

Basically everything runs off a notebook powerbank that has all the charging and protection features already built in - so no working on risky LiPo battery packs is required here.

The battery pack can deliver up to 50W peak which is more than enough for our use. One issue we had from time to time though was that the battery pack has a protection built in that shuts off the power when too little current is drawn. This totally makes sense when using it for its intended purpose (which we obviously don't).

#### Adding a power resistor
At some point this problem somehow vanished, but one possible solution would be adding a **power resistor** that draws a fixed base current and thus circumvents the automatic shutdown. It also increases the power draw in general, but it's probably the simplest solution.

We still need to check what value would be a good match though. Open to suggestions.

#### Basic power scheme

We created to independent circuits so you can control which devices are powered to save some battery life.

1) Arduino, RC receiver, motors, servo
2) UpBoard and its peripherals (like the 3D camera, microphones etc.)

Ready-made devices like the speaker, the projector etc. get their juice directly from the USB and all have a power switch themselves.


#### Powering the UpBoard

The UpBoard uses a simple DC jack, but **behold**!
Usually these are used for 9V and 12V which **you should never at any time** feed into the UpBoard. 

**! The UpBoard takes 5V MAXIMUM !**

*I managed to fry one of our boards by accidentally giving it 12V from our lab bench power supply...oops, not good, believe me.*

Eventhough the powerbank has a 5V output, it can't deliver enough current for the UpBoard to boot properly. Thus we used a cheap step down buck converter, capable of delivering up to 12 A (not the small LM2596 ones), set to 5V.

We also added a decoupling capacitor across the 5V and GND rails on the board - not sure if it's necessary after all.

#### Powering the motors

This is pretty straight-forward: The motor drivers need 12V to work, so you can just connect them directly to the battery pack.

#### Powering the Arduino (and peripherals)

