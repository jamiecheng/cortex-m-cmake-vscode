#include "delay.h"

void delay(uint32_t ms)
{
    for (uint32_t i = 0; i < ms; i++)
    {
        __WFI();
    }
}