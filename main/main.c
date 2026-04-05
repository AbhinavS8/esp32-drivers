#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "gpio_driver.h"

#define LED_PIN 2

void app_main(void)
{
    gpio_output_ena(LED_PIN);

    while (1)
    {
        gpio_set(LED_PIN);
        vTaskDelay(pdMS_TO_TICKS(2000));

        gpio_clear(LED_PIN);
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}