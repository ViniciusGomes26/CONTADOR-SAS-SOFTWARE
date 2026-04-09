![Linguagem C](https://img.shields.io/badge/Language-C-blue.svg)
![Framework ESP-IDF](https://img.shields.io/badge/Framework-ESP--IDF-orange.svg)
![RTOS FreeRTOS](https://img.shields.io/badge/RTOS-FreeRTOS-green.svg)
 
 - Contador Regressivo com Display de 7 Segmentos (ESP32):
  Projeto de um contador regressivo para uma atividade somativa sobre a construção de um semáforo High-Tech. O sistema apresenta a contagem regressiva integrada ao funcionamento do semáforo, utilizando dois displays de segmentos em multiplexação. Desenvolvido para o microcontrolador ESP32, utiliza o framework ESP-IDF e o sistema operacional de tempo real FreeRTOS.

 - Funcionamento:
   O sistema utiliza a técnica de multiplexação para controlar dois dígitos independentes, otimizando o uso dos pinos do microcontrolador. O código é dividido em duas tarefas principais (tasks):
   
    - Task Display: Responsável por alternar rapidamente a exibição entre as dezenas e unidades.
    - Task Contador: Responsável pela lógica de decremento do tempo em intervalos de 1 segundo.
    
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
   
             
           
