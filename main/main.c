#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define GPIO 2

void app_main(void)
{
    volatile uint32_t* gpio_out_w1ts_reg = (volatile uint32_t*) 0x3FF44008;
    volatile uint32_t* gpio_out_w1tc_reg = (volatile uint32_t*) 0x3FF4400C;
    volatile uint32_t* gpio_enable_reg = (volatile uint32_t*) 0x3FF44020;

    // Set the mode for GPIO5 to output
    *gpio_enable_reg |= (1 << GPIO);

    while(1) {
        // Set the level for GPIO5 to HIGH
        *gpio_out_w1ts_reg = (1 << GPIO);

        // Delay
        vTaskDelay(pdMS_TO_TICKS(500));

        // Set the level for GPIO5 to LO
        *gpio_out_w1tc_reg = (1 << GPIO);

        // Delay
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
