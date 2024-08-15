/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PIN_B = 5;
const int BTN_PIN_R = 28;
const int bobina1 = 18;
const int bobina2 = 19;
const int bobina3 = 20;
const int bobina4 = 21;

int main() {
    stdio_init_all();
    gpio_init(LED_PIN_B);
    gpio_set_dir(LED_PIN_B, GPIO_OUT);
    gpio_init(BTN_PIN_R);
    gpio_set_dir(BTN_PIN_R, GPIO_IN);
    gpio_pull_up(BTN_PIN_R);
    gpio_init(bobina1);
    gpio_set_dir(bobina1, GPIO_OUT);
    gpio_init(bobina2);
    gpio_set_dir(bobina2, GPIO_OUT);
    gpio_init(bobina3);
    gpio_set_dir(bobina3, GPIO_OUT);
    gpio_init(bobina4);
    gpio_set_dir(bobina4, GPIO_OUT);

    while (true) {
    if(!gpio_get(BTN_PIN_R)){
      gpio_put(LED_PIN_B, 1); 
      for(int i = 0; i < 512; i++){
        gpio_put(bobina1, 1);
        sleep_ms(10);
        gpio_put(bobina1, 0);
        gpio_put(bobina2, 1);
        sleep_ms(10);
        gpio_put(bobina2, 0);
        gpio_put(bobina3, 1);
        sleep_ms(10);
        gpio_put(bobina3, 0);
        gpio_put(bobina4, 1);
        sleep_ms(10);
        gpio_put(bobina4, 0);
        sleep_ms(10);
            }
        gpio_put(LED_PIN_B, 0);
      }
      
      
    }
}
