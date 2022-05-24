#ifdef __cplusplus
extern "C"
{
#endif
    /**
     * @brief Initialize the system's clock and other peripherals that are mandatory for running. This does not include peripherals like GPIO, I2C, SPI etc.
     *
     */
    void system_init();

#ifdef __cplusplus
}
#endif