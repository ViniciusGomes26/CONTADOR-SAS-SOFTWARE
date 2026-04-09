![Linguagem C](https://img.shields.io/badge/Language-C-blue.svg)
![Framework ESP-IDF](https://img.shields.io/badge/Framework-ESP--IDF-orange.svg)
![RTOS FreeRTOS](https://img.shields.io/badge/RTOS-FreeRTOS-green.svg)
 
 - Contador Regressivo com Display de 7 Segmentos (ESP32):
    Projeto de um contador regressivo, para uma somativa, sobre a construção de semáforo High-Tech, no qual o contador, apresenta a contagem regressiva, juntamente com o semáforo, usando dois Displays de 7 segmentos em multiplexação, desenvolvido para o microcontrolador ESP32 utilizando o ESP-IDF e o sistema operacional de tempo real FreeRTOS. 

 - O sistema utiliza a técnica de multiplexação para controlar dois dígitos independentes gastando menos pinos do microcontrolador. O código é dividido em duas tarefas principais (tasks):
    Task Display: Responsável por designar os números de maneira rápida entre as dezenas e unidades (multiplexação).
    Task Contador: Responsável pela lógica de decremento do tempo a cada 1 segundo.
    
 - Linguagem: C
   
    - Framework: ESP-IDF;
    - RTOS: FreeRTOS; 
    - Hardware: ESP32 e Display 7 Segmentos (Catodo Comum)

 - Configuração de Pinos: 

           Segmento	 |  GPIO
                     |
             A       |  21
             B       |  19
             C       |  4
             D       |  5
             E       |  18
             F       |  22
             G       |  23

 - Pinos de Controle (Seleção do Dígito):


          Dígito    |  GPIO
                    |
         Dezenas    |  14
         Unidades   |  27
                    |
                    |

 - Desenvolvido por:
   
     VINÍCIUS BATISTA GOMES
   
             
           
