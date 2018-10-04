# arduino-lcd-i2c-display

DFRobot I2C LCD display with Liquid Crystal based on platformio

## Installation
`brew install platformio` -- install platformio

## Dependencies
`LiquidCrystal_I2C`

## Build and compilation
`pio run` -- build everything
`pio run --target upload` -- build and upload to arduino

## Hardware:
Arduino UNO
YwRobot arduino lcm1602 iic v1

## Additional info
Everything works by COM protocol, tested on `atmega328p`
Project is based on [platfromio](http://docs.platformio.org/en/latest/)
YwRobot arduino lcm1602 iic v1 [tutorial](http://henrysbench.capnfatz.com/henrys-bench/arduino-displays/ywrobot-lcm1602-iic-v1-lcd-arduino-tutorial/)