/*
 * Created on Sat Jun 04 2022
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

#ifndef UART_H
#define UART_H

#include "stdint.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum
    {
        UART_BAUD_9600,
        UART_BAUD_115200,
    } uart_baud_t;

    typedef enum
    {
        UART_WORD_SIZE_8,
        UART_WORD_SIZE_9,
    } uart_word_length_t;

    typedef enum
    {
        UART_STOP_BITS_1,
        UART_STOP_BITS_2,
    } uart_stop_bits_t;

    typedef enum
    {
        UART_PARITY_NONE,
        UART_PARITY_EVEN,
        UART_PARITY_ODD
    } uart_parity_t;

    typedef enum {
        UART_FC_NONE,
        UART_FC_RTS,
        UART_FC_CTS,
        UART_FC_RTS_CTS
    } uart_fc_t;

    typedef enum {
        UART_EVENT_TX_COMPLETE,
        UART_EVENT_RX_COMPLETE
    } uart_event_t;

    typedef struct
    {
        uart_event_t type;
        uint8_t data[128];
    } uart_event_ctx_t;

    typedef void (*uart_ev_cb_t)(uart_event_ctx_t);

    typedef struct
    {
        uint8_t port;

        /* config part */
        uart_baud_t baud;
        uart_word_length_t word_length;
        uart_stop_bits_t stop_bits;
        uart_parity_t parity;
        uart_fc_t flow_control;

        /* application handlers */
        uart_ev_cb_t ev_cb;
    } uart_instance_t;

    int uart_config(uart_instance_t *inst);

    int uart_write_sync(uart_instance_t *inst, uint8_t *buf, uint32_t len);

    int uart_read_sync(uart_instance_t *inst, uint8_t *buf, uint32_t len);

    int uart_write_async(uart_instance_t *inst, uint8_t *buf, uint32_t len);

    int uart_read_async(uart_instance_t *inst, uint8_t *buf, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif /* UART_H */
