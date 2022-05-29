#include "stdint.h"

#ifdef __cplusplus
extern "C"
{
#endif
    /**
     * @brief Initialize the system's clock and other peripherals that are mandatory for running. This does not include peripherals like GPIO, I2C, SPI etc.
     *
     */
    void system_init();

    /**
     * @brief Returns the tick count since bootup in milliseconds
     * 
     * @return uint32_t tick count [ms]
     */
    uint32_t system_get_tick();

#ifdef __cplusplus
}
#endif