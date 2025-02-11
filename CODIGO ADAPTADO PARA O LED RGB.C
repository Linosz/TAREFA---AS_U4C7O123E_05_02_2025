//CODIGO ADAPTADO PARA O LED RGB
 #include <stdio.h>

 #include "pico/stdlib.h"
 #include "hardware/pwm.h"
 #include "hardware/clocks.h"
 
 #define LED_R_PIN 12  // LED vermelho no GPIO 12
 #define LED_G_PIN 13  // LED verde no GPIO 13
 #define LED_B_PIN 14  // LED azul no GPIO 14
 
 #define PWM_FREQUENCY 1000  // Frequência do PWM
 #define CLOCK_DIVIDER 125   // Divisor do clock
 #define WRAP_VALUE 255      // Valor de wrap para controle de intensidade do PWM
 
 void set_led_pwm(uint pin, uint16_t duty_cycle) {
     uint slice_num = pwm_gpio_to_slice_num(pin);
     pwm_set_gpio_level(pin, duty_cycle);
     pwm_set_enabled(slice_num, true);
 }
 
 int main() {
     stdio_init_all();
 
     // Configura os pinos do LED para função PWM
     gpio_set_function(LED_R_PIN, GPIO_FUNC_PWM);
     gpio_set_function(LED_G_PIN, GPIO_FUNC_PWM);
     gpio_set_function(LED_B_PIN, GPIO_FUNC_PWM);
 
     uint slice_num_r = pwm_gpio_to_slice_num(LED_R_PIN);
     uint slice_num_g = pwm_gpio_to_slice_num(LED_G_PIN);
     uint slice_num_b = pwm_gpio_to_slice_num(LED_B_PIN);
     
     // Configura os parâmetros do PWM
     pwm_set_wrap(slice_num_r, WRAP_VALUE);
     pwm_set_wrap(slice_num_g, WRAP_VALUE);
     pwm_set_wrap(slice_num_b, WRAP_VALUE);
     
     pwm_set_clkdiv(slice_num_r, CLOCK_DIVIDER);
     pwm_set_clkdiv(slice_num_g, CLOCK_DIVIDER);
     pwm_set_clkdiv(slice_num_b, CLOCK_DIVIDER);
     
     while (true) {
         // LED vermelho aceso
         set_led_pwm(LED_R_PIN, 255);
         set_led_pwm(LED_G_PIN, 0);
         set_led_pwm(LED_B_PIN, 0);
         sleep_ms(5000);  // Espera 5 segundos
         
         // LED verde aceso
         set_led_pwm(LED_R_PIN, 0);
         set_led_pwm(LED_G_PIN, 255);
         set_led_pwm(LED_B_PIN, 0);
         sleep_ms(5000);  // Espera 5 segundos
         
         // LED azul aceso
         set_led_pwm(LED_R_PIN, 0);
         set_led_pwm(LED_G_PIN, 0);
         set_led_pwm(LED_B_PIN, 255);
         sleep_ms(5000);  // Espera 5 segundos
         
         // LED amarelo (vermelho + verde)
         set_led_pwm(LED_R_PIN, 255);
         set_led_pwm(LED_G_PIN, 255);
         set_led_pwm(LED_B_PIN, 0);
         sleep_ms(5000);  // Espera 5 segundos
         
         // LED ciano (verde + azul)
         set_led_pwm(LED_R_PIN, 0);
         set_led_pwm(LED_G_PIN, 255);
         set_led_pwm(LED_B_PIN, 255);
         sleep_ms(5000);  // Espera 5 segundos
         
         // LED magenta (vermelho + azul)
         set_led_pwm(LED_R_PIN, 255);
         set_led_pwm(LED_G_PIN, 0);
         set_led_pwm(LED_B_PIN, 255);
         sleep_ms(5000);  // Espera 5 segundos
         
         // LED branco (vermelho + verde + azul)
         set_led_pwm(LED_R_PIN, 255);
         set_led_pwm(LED_G_PIN, 255);
         set_led_pwm(LED_B_PIN, 255);
         sleep_ms(5000);  // Espera 5 segundos
     }
 }
 
