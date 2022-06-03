#include "system.h"
#include "delay.h"
#include "gpio.h"

#define LED_PORT 0
#define LED_PIN 5

static void config_peripherals()
{
    system_init();

    gpio_config_output(LED_PORT, LED_PIN, GPIO_MODE_NO_PULL);
}

int main()
{
    config_peripherals();

    while (1)
    {
        gpio_write(LED_PORT, LED_PIN, 0);
        delay(500);
        gpio_write(LED_PORT, LED_PIN, 1);
        delay(500);
    }
}
