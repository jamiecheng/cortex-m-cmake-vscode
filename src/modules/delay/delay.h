#ifndef DELAY_H
#define DELAY_H

#include "stdint.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Blocks the current thread for a period amount of milliseconds.
 * 
 * @param ms Delay in milliseconds
 */
void delay(uint32_t ms);

#ifdef __cplusplus
}
#endif

#endif /* DELAY_H */
