#ifndef OLED_CONTROL
#define OLED_CONTROL

#include <stdio.h>
#include<string.h>

//bibliotecas para display OLED
#include "pico/binary_info.h"
#include "ssd1306.h"
#include "hardware/i2c.h"

#include "hardware/timer.h"
#include "pico/time.h"


#define STEP 8//8 //passo da esfera e espaço entre os pinos
#define DESLOCAMENTO 48 //deslocamento da board
#define ESPACE_HIST 5
#define SIG_CENTRE_Y 59
#define SIG_CENTRE_X 13 

//Display OLED
#define I2C_SDA  14
#define I2C_SCL  15




// funções do OLED
void setup_OLED(); 
void oled_clear();
void oled_print(char *str,uint8_t adry);

void oled_render();




#endif