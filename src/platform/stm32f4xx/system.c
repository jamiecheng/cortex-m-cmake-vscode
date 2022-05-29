#include "system.h"
#include "stm32f4xx_hal.h"

void system_init()
{
    HAL_Init();
}

uint32_t system_get_tick()
{
    return HAL_GetTick();
}
