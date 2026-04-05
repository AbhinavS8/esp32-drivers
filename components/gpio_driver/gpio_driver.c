#include "gpio_driver.h"

#define GPIO_OUT_W1TS_REG 0x3FF44008
#define GPIO_OUT_W1TC_REG 0x3FF4400C
#define GPIO_ENABLE_REG   0x3FF44020

#define REG32(addr) (*(volatile uint32_t *)(addr))

void gpio_output_ena(uint8_t pin)
{
    REG32(GPIO_ENABLE_REG) |= (1 << pin);
}

void gpio_set(uint8_t pin)
{
    REG32(GPIO_OUT_W1TS_REG) = (1 << pin);
}

void gpio_clear(uint8_t pin)
{
    REG32(GPIO_OUT_W1TC_REG) = (1 << pin);
}