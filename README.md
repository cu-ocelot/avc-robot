## avc-robot

**An autonomous robot design for Sparkfun's [Autonomous Vehicle Competition](https://avc.sparkfun.com/)**

----

### High-level system design

The robot is built with the following ingredients:

- RC racing chassis (Ackerman steering)
- IMU and GPS for localization
- Encoder and state-space motor representation for speed control
- Basic sensors for object avoidance/failure detection (to be determined)
- [Beaglebone Black](https://beagleboard.org/black) with [Robot Operating System](http://www.ros.org/) for guidance/localization
- [TI MSP432](http://www.ti.com/tool/msp-exp432p401r) for motor control

As the AVC course for 2016 is still unknown, we are building a robot that can accomplish the following generic tasks:

- Navigate a course via GPS waypoints
- Avoid obstacles (barrels/boxes/other robots) and adjust course
- Stay safe and in one piece when flipped/stuck/damaged
- Successfully fuse GPS and IMU data for better localization

See the [proposed block diagram](docs/diagrams/proposed_block_diagram.pdf) for a graphical explanation.

### Components

We are using a [BeagleBone Black](https://www.sparkfun.com/products/12857) as the main processor for the robot. For debugging, the BBB is connected to WiFi via an [Edimax adapter](https://www.sparkfun.com/products/13677), and can display debug data via a [SparkFun serial LCD](https://www.sparkfun.com/products/9067) (this requires a dedicated UART on the BBB). The MSP432 LaunchPad controlling the motor will be connected via SPI, communicating via a custom protocol.

For GPS, we will be using [SparkFun's Venus GPS](https://www.sparkfun.com/products/11058) with a [LS20031](https://www.sparkfun.com/products/8975) as a backup. Either GPS unit communicates with the GPS via NMEA 0183 data over TTL serial; one of the UARTs on the BeagleBone will be used to receive the GPS data.

IMU to be determined.

Object avoidance scheme to be determined.

The motor control feedback is provided by [this rotary encoder](https://www.sparkfun.com/products/10932). Motor controller to be decided.

To avoid noise/EMI problems, the motor controller and steering servo will be optically isolated from the rest of the logic. Additionally, the logic and motors will use separate batteries. This allows us to hot-swap motor batteries without bringing down the BBB and associated circuit. Additionally, in the event of a failure, the motor supplies can be disabled, leaving the robot immobile without indiscriminately halting the BBB.

### Tasks

- ROS install/build/config on BBB
- UARTs 1 and 2 on the BBB need to be enabled and usable (we need at least 2 or 3 serial ports)
- GPS comms with BBB via UART
- GPS polling/parsing. ROS should have library for this
- IMU comms with BBB via <?>
- IMU polling/parsing/processing. ROS might have a library for this
- Bidirectional SPI comms between BBB and MSP432

### Resources
**Datasheets, links, tutorials, etc**

[BBB design files on GitHub](https://github.com/beagleboard/BeagleBone-Black)  
[TI Sitara AM3358 product page](http://www.ti.com/product/AM3358/technicaldocuments)  
[TI Sitara AM335x datasheet](http://www.ti.com/lit/ds/symlink/am3358.pdf)  
[TI MSP432P401R LaunchPad product page](http://www.ti.com/tool/msp-exp432p401r)  
[TI MSP432P401x MCU datasheet](http://www.ti.com/lit/ds/slas826b/slas826b.pdf)  

### Tools

_What software should I be using for &lt;stuff&gt;?_

This document and other `*.md` files are written in [Markdown](https://daringfireball.net/projects/markdown/), a markup language that compiles to XHTML/HTML. On OS X, [Mou](http://25.io/mou/) is an elegant Markdown editor. For Windows and Linux, [Haroopad](http://pad.haroopress.com/) is a decent cross-platform Markdown editor.

Looking for code editor? [Atom](https://atom.io/) is a nice (free) text editor with git integration and many nice packages (plugins) available, with packages that enable Markdown editing, C/C++ linting, and much more. [Sublime](https://www.sublimetext.com/) is also great.

Need a VCS client? [Sourcetree](https://www.sourcetreeapp.com/) is a full-featured source control client that works with both [Git](https://git-scm.com/) and [Mercurial](https://www.mercurial-scm.org/). For a simpler Git-only client, [GitHub Desktop](https://desktop.github.com/) is very easy to use. Both these clients run on OS X and Windows. On Linux, you've got a CLI, use it!

Need to create schematics and/or PCB designs? The CU Ocelot team has acccess to [Altium Designer](http://www.altium.com/altium-designer/overview), a full-featured EDA suite. If you want a free and open-source tool (Altium is neither), use [Kicad](http://kicad-pcb.org/).
