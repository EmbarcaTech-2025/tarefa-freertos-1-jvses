#include "oled_control.h"


//declaração global do OLED para usar em funções fora da main
uint8_t ssd[ssd1306_buffer_length];
// Preparar área de renderização para o display (ssd1306_width pixels por ssd1306_n_pages páginas)
struct render_area frame_area = {
    start_column : 0,
    end_column : ssd1306_width - 1,
    start_page : 0,
    end_page : ssd1306_n_pages - 1
};


void setup_OLED(){
    // Inicialização do i2c
    i2c_init(i2c1, 800 * 1000); //i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    // Processo de inicialização completo do OLED SSD1306
    ssd1306_init();
    calculate_render_area_buffer_length(&frame_area);
  }

void oled_clear(){
    memset(ssd, 0, ssd1306_buffer_length);
    // render_on_display(ssd, &frame_area);
}

void oled_print(char *str,uint8_t adry){
    char buffer[17];
    sprintf(buffer, "%s", str);
    // ssd1306_draw_string(ssd, 0, 0, buffer);
    // sprintf(buffer, "V %d", desvio);
    ssd1306_draw_string(ssd, 0, adry, buffer);
}

void oled_render(){
    render_on_display(ssd, &frame_area);
}




