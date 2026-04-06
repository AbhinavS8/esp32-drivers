#ifndef ESP32_UART_DRIVER_H
#define ESP32_UART_DRIVER_H

#include <stdint.h>

typedef struct {
    uint32_t baud_rate;
    uint8_t data_bits;
    uint8_t stop_bits;
    uint8_t parity;
} uart_config_t;

void uart_ena(uart_config_t *config);
void uart_write_byte(uint8_t data);
void uart_write_string(const char *str);

// UART_CONF0_REG
// UART_CLKDIV_REG
// UART_STATUS_REG
// UART_FIFO_REG
#endif