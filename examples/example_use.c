#include "driver/i2c.h"  // ESP-IDF I2C driver
#include "lcd1602.h"     // Your LCD driver API

// --- Board-level configuration ---
// SDA/SCL pins are *hardware specific* to your ESP32 board
#define SDA_PIN 21  // GPIO for SDA line
#define SCL_PIN 22  // GPIO for SCL line

// Typical I2C addresses for PCF8574 modules:
// 0x27 (most common), 0x3F (less common)
#define LCD_ADDR 0x27

// Initialize I2C bus as master
// I²C lines are open-drain: devices can only drive the bus LOW.
// Pull-ups are needed so the lines actually go HIGH when not driven.
static void i2c_master_init(void) {
    i2c_config_t cfg = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = SDA_PIN,
        .scl_io_num = SCL_PIN,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = 100000  // 100kHz standard I2C speed
    };

    // Apply configuration and install driver
    i2c_param_config(I2C_NUM_0, &cfg);
    i2c_driver_install(I2C_NUM_0, cfg.mode, 0, 0, 0);
}

// Example entry point for ESP-IDF
void app_main(void) {
    // 1. Initialize I2C bus
    i2c_master_init();

    // 2. Initialize LCD driver
    //    - port     : I2C_NUM_0
    //    - address  : LCD_ADDR
    //    - backlight: true (RECOMMENDED)
    lcd_init(I2C_NUM_0, LCD_ADDR, true);

    // 3. Write two lines
    lcd_write("Hello", "World");
}