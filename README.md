
# ESP32 - LCD1602 Driver

An HD44780-based LCD1602 driver for ESP32 using a PCF8574 I2C expander, written in plain C for ESP-IDF.

Lets you use the LCD1602 over I2C without needing to make your own driver.

## Overview

This driver:

- Uses ESP-IDF’s I2C API (`driver/i2c.h`)
- Works with PCF8574 I2C port expander modules
- Written in C (no C++)
- Includes a port scanner to help you discover the I2C address of your LCD module

Future plans:
- Support for other LCD sizes (e.g. 20×4)
- Optional scrolling/text convenience functions

Currently only tested on the ESP32 Wrover. Future plans include allowing use of different LCD sizes

## Examples

The `examples/` directory contains:

- `example_use.c` — “Hello World” usage example showing:
  - I²C master initialization
  - LCD initialization
  - writing two lines of text

- `port_scanner.c` — scans the I²C bus and logs any detected I²C devices, including LCD modules.
  Useful when you don’t know if your module is `0x27`, `0x3F`, etc.

- Make sure you set the correct SDA and SCL pins and I2C PORT for your setup.

Quick usage:
```C
i2c_master_init();
lcd_init(I2C_NUM_0, 0x27, true);
lcd_write("Hello", "World");
```

## Requirements

This component is designed for ESP32 using ESP-IDF.

**Tested boards:**
- ESP32-WROVER-B (NRND module)

Other ESP32 modules should work as long as:
- SDA/SCL lines are connected correctly
- PCF8574 module has I²C pull-ups

External level shifting is not required for typical 3.3V setups.
