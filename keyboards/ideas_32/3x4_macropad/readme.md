# 3x4_macropad

![3x4_macropad](imgur.com image replace me!)

A 3x4 macropad with encoder and 128x64 oled support. Uses the WeAct Studio RP2040 Core Board (WeAct Studio Pi Pico) as the microcontroller. 
* Keyboard Maintainer: [Kean Li](https://github.com/ideas32)
* Hardware Supported: WeAct RP2040 Coreboard (WeAct Pi Pico)
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make 3x4_macropad:default

Flashing example for this keyboard:

    make 3x4_macropad:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top-left key and plug in the keyboard
* **Physical reset button**: Press the button on the Pi Pico labeled "BOOTSEL" while plugging the keyboard in
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
