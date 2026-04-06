#ifndef ESP32_GPIO_DRIVER_H
#define ESP32_GPIO_DRIVER_H
#include <stdint.h>

void gpio_output_ena(uint8_t pin);
void gpio_set(uint8_t pin);
void gpio_clear(uint8_t pin);

#endif