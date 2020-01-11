
A 4x12 matrix using 3 modular 4x4 matrix boards and powered by a Pro Micro.

this one is using a Pro Micro. The Pro Micro has less data pins available so only 3 boards can be connected instead of 4. There are 2 pins left over, I used one (D3) for a backlight circuit like on a Gherkin. The other data pin (D2) is left for possible use with a WS2812B strip.

Keyboard Maintainer: Custom  
Hardware Supported: Handwired using pro micro


Make example for this keyboard (after setting up your build environment):

    make handwired/hw4x12orth:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
