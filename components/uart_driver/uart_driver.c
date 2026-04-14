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
    // set the clock divider (two parts, ignore fractional for now)
    // baud rate = UART serial clock / clock divider
    
    REG32(UART_CLKDIV_REG) = UART_SCLK / config->baud_rate;
    
    // now setting parity, data bit, etc.
    // part of CONF0, bits 0-5
    // 
    // UART_STOP_BIT_NUM   1: 1 bit, 2: 1.5 bits, 3: 2 bits  (R/W)
    // UART_BIT_NUM        0: 5 bits, 1: 6 bits, 2: 7 bits, 3: 8 bits. (R/W)

    uint32_t reg = REG32(UART_CONF0_REG);

    // clear regis first
    reg &= ~(0x3 << 2); // no of bits
    reg &= ~(0x3 << 4); // stop bit
    reg &= ~(1 << 1); // disable parity

    // setting values
    reg |= (3 << 2);
    reg |= (1 << 4);

    REG32(UART_CONF0_REG) = reg;
}

void uart_write_byte(uint8_t data) {
    // check if buffer is full
    // if not, write to FIFO buffer

    // ESP32 UART FIFO size = 128 bytes
    // shift right 16 to reach the UART_TXFIFO_CNT register

    while ((REG32(UART_STATUS_REG) >> 16 & 0xFF) == 0x80) {
        //if buffer has 128 bytes, wait
    }

    // data register, so no need to clear each time, just directly put in byte
    // directly pushed to queue
    
    REG32(UART_FIFO_REG) = data;
}