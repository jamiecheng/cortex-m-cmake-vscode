#include "gpio.h"

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

#define PORT_MAP_BASE(port) (AHB1PERIPH_BASE + (port * 0x0400UL))
#define PORT_MAP(port) ((GPIO_TypeDef *)(PORT_MAP_BASE(port)))
#define PIN_MAP(pin) (1 << pin)

static void __enable_clock(uint8_t port)
{
    uint64_t addr = PORT_MAP_BASE(port);

    switch (addr)
    {
    case GPIOA_BASE:
        __HAL_RCC_GPIOA_CLK_ENABLE();
        break;
    case GPIOB_BASE:
        __HAL_RCC_GPIOB_CLK_ENABLE();
        break;
    case GPIOC_BASE:
        __HAL_RCC_GPIOC_CLK_ENABLE();
        break;
    case GPIOD_BASE:
        __HAL_RCC_GPIOD_CLK_ENABLE();
        break;
    case GPIOE_BASE:
        __HAL_RCC_GPIOE_CLK_ENABLE();
        break;
    case GPIOF_BASE:
        __HAL_RCC_GPIOF_CLK_ENABLE();
        break;
    case GPIOG_BASE:
        __HAL_RCC_GPIOG_CLK_ENABLE();
        break;
    case GPIOH_BASE:
        __HAL_RCC_GPIOH_CLK_ENABLE();
        break;
    }
}

void gpio_config_input(uint8_t port, uint8_t pin, gpio_mode mode)
{
    GPIO_InitTypeDef config_struct = {0};

    __enable_clock(port);

    config_struct.Pin = PIN_MAP(pin);
    config_struct.Mode = GPIO_MODE_INPUT;

    switch (mode)
    {
    case GPIO_MODE_PULL_UP:
        config_struct.Pull = GPIO_PULLUP;
        break;

    case GPIO_MODE_PULL_DOWN:
        config_struct.Pull = GPIO_PULLDOWN;
        break;

    default:
        config_struct.Pull = GPIO_NOPULL;
        break;
    }

    config_struct.Speed = GPIO_SPEED_FREQ_MEDIUM;

    HAL_GPIO_Init(PORT_MAP(port), &config_struct);
}

void gpio_config_output(uint8_t port, uint8_t pin, gpio_mode mode)
{
    GPIO_InitTypeDef config_struct = {0};

    __enable_clock(port);

    config_struct.Pin = PIN_MAP(pin);
    config_struct.Mode = GPIO_MODE_OUTPUT_PP;

    switch (mode)
    {
    case GPIO_MODE_PULL_UP:
        config_struct.Pull = GPIO_PULLUP;
        break;

    case GPIO_MODE_PULL_DOWN:
        config_struct.Pull = GPIO_PULLDOWN;
        break;

    default:
        config_struct.Pull = GPIO_NOPULL;
        break;
    }

    config_struct.Speed = GPIO_SPEED_FREQ_MEDIUM;

    HAL_GPIO_Init(PORT_MAP(port), &config_struct);
}

void gpio_write(uint8_t port, uint8_t pin, uint8_t val)
{
    HAL_GPIO_WritePin(PORT_MAP(port), PIN_MAP(pin), val);
}

uint8_t gpio_read(uint8_t port, uint8_t pin)
{
    return HAL_GPIO_ReadPin(PORT_MAP(port), PIN_MAP(pin));
}
