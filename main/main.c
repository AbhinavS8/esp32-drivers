#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "gpio_driver.h"
#include "uart_driver.h"
#define LED_PIN 2

void app_main(void)
{
    gpio_output_ena(LED_PIN);

    uart_config_t config = {
        .baud_rate = 115200,
        .data_bits = 8,
        .stop_bits = 1,
        .parity = 0
    };

    uart_ena(&config);

    while (1)
    {
        gpio_set(LED_PIN);
        vTaskDelay(pdMS_TO_TICKS(2000));
        
        uart_write_byte('a');
        
        gpio_clear(LED_PIN);
        vTaskDelay(pdMS_TO_TICKS(2000));


    }

}