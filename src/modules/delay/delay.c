#include "delay.h"
#include "system.h"

void delay(uint32_t ms)
{
    uint32_t tick_end = system_get_tick() + ms;

    while(system_get_tick() < tick_end)
    {
        system_wait_for_event();
    }
}