#include "uart_driver.h"

// UART_CONF0_REG
// UART_CLKDIV_REG
// UART_STATUS_REG
// UART_FIFO_REG

// typedef struct {
//     uint32_t baud_rate;
//     uint8_t data_bits;
//     uint8_t stop_bits;
//     uint8_t parity;
// } uart_config_t;

//using UART 0 for now
#define UART_CONF0_REG 0x3FF40020
#define UART_CLKDIV_REG 0x3FF40014
#define UART_STATUS_REG 0x3FF4001C
#define UART_FIFO_REG 0x3FF40000
#define UART_SCLK 80000000

#define REG32(addr) (*(volatile uint32_t *)(addr))

void uart_ena(uart_config_t *config) {
    //set the clock divider (two parts, ignore fractional for now)
    // baud rate = UART serial clock / clock divider
    
    REG32(UART_CLKDIV_REG) = UART_SCLK / config->baud_rate;
    
}