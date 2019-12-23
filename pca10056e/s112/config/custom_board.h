/**
 * Copyright (c) 2016 - 2019, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef CUSTOM_BOARD_H
#define CUSTOM_BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nrf_gpio.h"


//// LEDs definitions for PCA10056
//#define LEDS_NUMBER 4
//
//#define LED_1 NRF_GPIO_PIN_MAP(0,13)
//#define LED_2 NRF_GPIO_PIN_MAP(0,14)
//#define LED_3 NRF_GPIO_PIN_MAP(0,15)
//#define LED_4 NRF_GPIO_PIN_MAP(0,16)
//#define LED_START LED_1
//#define LED_STOP LED_4
//
//#define LEDS_ACTIVE_STATE 0
//
//#define LEDS_LIST { LED_1, LED_2, LED_3, LED_4 }
//
//#define LEDS_INV_MASK LEDS_MASK
//
//#define BSP_LED_0 13
//#define BSP_LED_1 14
//#define BSP_LED_2 15
//#define BSP_LED_3 16
//
#define BUTTONS_NUMBER 0
//
//#define BUTTON_1 11
//#define BUTTON_2 12
//#define BUTTON_3 24
//#define BUTTON_4 25
//#define BUTTON_PULL NRF_GPIO_PIN_PULLUP
//
#define BUTTONS_ACTIVE_STATE 0
//
//#define BUTTONS_LIST { BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4 }
//
//#define BSP_BUTTON_0 BUTTON_1
//#define BSP_BUTTON_1 BUTTON_2
//#define BSP_BUTTON_2 BUTTON_3
//#define BSP_BUTTON_3 BUTTON_4
//
//#define RX_PIN_NUMBER 8
//#define TX_PIN_NUMBER 6
//#define CTS_PIN_NUMBER 7
//#define RTS_PIN_NUMBER 5
//#define HWFC true
//
// I2C board mappings
#define SCL_PIN 30 // SCL signal pin
#define SDA_PIN 28 // SDA signal pin

#ifdef __cplusplus
}
#endif

#endif // custom board