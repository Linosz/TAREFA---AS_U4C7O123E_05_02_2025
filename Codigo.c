/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"


#define SERVO_PIN 22
#define PWM_FREQUENCY 50
#define CLOCK_DIVIDER 125
#define WRAP_VALUE 20000

void set_servo_pulse(uint pin, uint16_t pulse_width) {
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_gpio_level(pin, pulse_width);
    pwm_set_enabled(slice_num, true);
}

int main() {
    stdio_init_all();
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    
    pwm_set_wrap(slice_num, WRAP_VALUE);
    pwm_set_clkdiv(slice_num, CLOCK_DIVIDER);
    
    while (true) {
        // 180 graus (2400us)
        set_servo_pulse(SERVO_PIN, 2400);
        sleep_ms(5000);
        
        // 90 graus (1470us)
        set_servo_pulse(SERVO_PIN, 1470);
        sleep_ms(5000);
        
        // 0 graus (500us)
        set_servo_pulse(SERVO_PIN, 500);
        sleep_ms(5000);
        
        // Movimento suave de 0 a 180 graus
        for (uint16_t pulse = 500; pulse <= 2400; pulse += 5) {
            set_servo_pulse(SERVO_PIN, pulse);
            sleep_ms(10);
        }
        
        // Movimento suave de 180 a 0 graus
        for (uint16_t pulse = 2400; pulse >= 500; pulse -= 5) {
            set_servo_pulse(SERVO_PIN, pulse);
            sleep_ms(10);
        }
    }
}
