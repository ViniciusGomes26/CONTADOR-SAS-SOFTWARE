#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// feito por Vinícius Gomes

#define A 21 // configuração de pinagem 
#define B 19
#define C 4
#define D 5
#define E 18
#define F 22
#define G 23
#define DP 2

#define pino_dezenas 14 // configuração de pinos para controle de GND e funcionamento individual
#define pino_unidades 27 

int valor_exibir = 20; // valor fundamental para a contagem / regressiva 

const int8_t digit[10][7] = { 
    {1,1,1,1,1,1,0}, // 0
    {0,1,1,0,0,0,0}, // 1
    {1,1,0,1,1,0,1}, // 2
    {1,1,1,1,0,0,1}, // 3
    {0,1,1,0,0,1,1}, // 4
    {1,0,1,1,0,1,1}, // 5
    {1,0,1,1,1,1,1}, // 6
    {1,1,1,0,0,0,0}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,1,1,0,1,1}  // 9
};

void controle_display(int num) {   // tarefa para controle de digitos do display 

    gpio_set_level(A, digit[num][0]);  
    gpio_set_level(B, digit[num][1]);
    gpio_set_level(C, digit[num][2]);
    gpio_set_level(D, digit[num][3]);
    gpio_set_level(E, digit[num][4]);
    gpio_set_level(F, digit[num][5]);
    gpio_set_level(G, digit[num][6]);
}

void configurar_pinos() { 
    int pinagem[] = {A, B, C, D, E, F, G, DP, pino_dezenas, pino_unidades}; // variavel para facilitar configuração dos pinos
    
    for(int i = 0; i < 10; i++) {  // laço "for" para alternar entre os numeros 0,1,2,4...
        gpio_reset_pin(pinagem[i]); // reset dos pinos como uma preucação de um possivel erro na setagem dos pinos e 
        gpio_set_direction(pinagem[i], GPIO_MODE_OUTPUT);
    }
}

void vTarefa_de_exibir_display(void *pvParameters) {
    while(1) {

      int dezenas = valor_exibir / 10;  // aparecera no display das dezenas
      int unidades = valor_exibir % 10; // aparecera no display das unidades
    
        gpio_set_level(pino_unidades, 1); 
        controle_display(dezenas);            // funcionamento do display dezenas
        gpio_set_level(pino_dezenas, 0);  
        vTaskDelay(10 / portTICK_PERIOD_MS);    

        gpio_set_level(pino_dezenas, 1);  
        controle_display(unidades);       // funcionamento do display unidades
        gpio_set_level(pino_unidades, 0); 
        vTaskDelay(10 / portTICK_PERIOD_MS); 
    }
}

void vTarefa_contador(void *pvParameters) { // tarefa de tempo
    while(1) {

        valor_exibir --;

        if (valor_exibir < 0) 
          valor_exibir = 20; 
        
        vTaskDelay(1000 / portTICK_PERIOD_MS); // precisa de um segundo para o funcionamento de ambos os displays  
      }
}

void app_main() {

    configurar_pinos();
    xTaskCreate(vTarefa_de_exibir_display, "Display", 2048, NULL, 5, NULL); // tarefa 5 para que os displays não pisquem 
    xTaskCreate(vTarefa_contador, "Contador", 2048, NULL, 1, NULL);
}