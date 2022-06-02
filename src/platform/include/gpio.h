/*
 * Created on Thu Jun 02 2022
 *
 * The MIT License (MIT)
 * Copyright (c) 2022 Jamie Cheng
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef GPIO_H
#define GPIO_H

#include "stdint.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum
    {
        GPIO_MODE_PULL_UP,
        GPIO_MODE_PULL_DOWN,
        GPIO_MODE_NO_PULL
    } gpio_mode;
    
    /**
     * @brief Configure a gpio pin as input. Some mcu's use a letter to index a port. 
     * In that case just use the count of that letter.
     *
     * @param port port index
     * @param pin pin index
     * @param mode pull up or pull down
     */
    void gpio_config_input(uint8_t port, uint8_t pin, gpio_mode mode);

    /**
     * @brief Configure a gpio pin as output. Some mcu's use a letter to index a port. 
     * In that case just use the count of that letter.
     * 
     * @param port port index
     * @param pin pin index
     * @param mode pull up or pull down
     */
    void gpio_config_output(uint8_t port, uint8_t pin, gpio_mode mode);

    /**
     * @brief Sets the logic output level of the pin. Configure the gpio using gpio_config_output() first.
     * 
     * @param port port index
     * @param pin pin index
     * @param val logic output level
     */
    void gpio_write(uint8_t port, uint8_t pin, uint8_t val);

    /**
     * @brief Reads the value of the gpio pin.
     * 
     * @param port port index
     * @param pin pin index
     * 
     * @return uint8_t the current logic level of the input
     */
    uint8_t gpio_read(uint8_t port, uint8_t pin);

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
