#include "SSD1306.h"

Adafruit_SSD1306 HeadsUpDisplay::display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

uint8_t HeadsUpDisplay::faceBitmap[];

const uint8_t HeadsUpDisplay::CoelaSplash[] = {
0xFF, 0xFF, 0xFF, 0xFF, 0xF1, 0xFF, 0xFF, 0x7F, 0x1F, 0xFF, 0xFF, 0x43, 0x10, 0x00, 0x0F, 0xFF,
0xFF, 0xFF, 0xFF, 0xE1, 0xCF, 0x9F, 0xFF, 0xBB, 0xF7, 0xFF, 0xFE, 0x90, 0x70, 0x00, 0x07, 0xFF,
0xFF, 0xFF, 0xFF, 0x80, 0x3F, 0xBF, 0xFF, 0x97, 0xF9, 0xFF, 0xFE, 0xF8, 0x0E, 0x00, 0x03, 0xFF,
0xFF, 0xFF, 0xFF, 0x00, 0x1F, 0xBF, 0xFF, 0xDF, 0xFE, 0xFF, 0xFF, 0xFE, 0x0C, 0x00, 0x01, 0xFF,
0xFF, 0xFF, 0xFF, 0x01, 0xCC, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0xFF, 0x04, 0x00, 0x00, 0xFF,
0xFF, 0xFF, 0xFE, 0x07, 0xF3, 0xFF, 0xFE, 0xFF, 0xFF, 0xBF, 0xF7, 0xFF, 0xC0, 0x00, 0x00, 0x7F,
0xFF, 0xFF, 0xFE, 0x0F, 0xFF, 0xFF, 0xF8, 0x3F, 0xFF, 0xDF, 0xFD, 0xFF, 0xF0, 0x00, 0x00, 0x3F,
0xFF, 0xFF, 0xFE, 0x1F, 0xFF, 0xFF, 0xF0, 0x1F, 0xFF, 0xD7, 0xFE, 0x7F, 0xF8, 0x00, 0x00, 0x1F,
0xFF, 0xFF, 0xFE, 0x1F, 0xFF, 0xFF, 0xC0, 0x0F, 0xFF, 0xEF, 0xFF, 0x9F, 0xFE, 0x00, 0x00, 0x0F,
0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0x80, 0x07, 0xFF, 0xF3, 0xE0, 0x0F, 0xFF, 0x80, 0x00, 0x07,
0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0x00, 0x03, 0xFF, 0xF3, 0xC0, 0x01, 0xFF, 0xF0, 0x00, 0x03,
0xFF, 0xFF, 0xFF, 0x7E, 0xF8, 0x7E, 0x00, 0x03, 0xFF, 0xF7, 0x80, 0x00, 0x7F, 0xFC, 0x00, 0x01,
0xFF, 0xFF, 0xFF, 0x7D, 0xF0, 0x3C, 0x00, 0x01, 0xFF, 0xF7, 0x00, 0x00, 0x07, 0xFF, 0x80, 0x00,
0xFF, 0xFF, 0xFF, 0x7F, 0xE0, 0x1E, 0x00, 0x01, 0xFF, 0xEC, 0x00, 0x00, 0x30, 0xFF, 0xF8, 0x00,
0xFF, 0xFF, 0xFE, 0xFF, 0xE0, 0x1F, 0x00, 0x01, 0xFF, 0x98, 0x00, 0x00, 0x1F, 0x03, 0xFF, 0xC1,
0xFF, 0xFF, 0xFE, 0xFF, 0xE0, 0x1F, 0x80, 0x00, 0xFE, 0x70, 0x00, 0x00, 0x07, 0xF8, 0x00, 0x1F,
0xFF, 0xFF, 0xFE, 0xFF, 0xC0, 0x1F, 0xC0, 0x00, 0xFD, 0xF0, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFE, 0xFF, 0xC0, 0x3E, 0xF0, 0x01, 0xF3, 0xE0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFE, 0xFF, 0x80, 0x38, 0x3C, 0x01, 0x8F, 0xF0, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF,
0xFF, 0xFF, 0xFE, 0xDF, 0x00, 0x78, 0x0F, 0x80, 0x67, 0xF0, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF,
0xFF, 0xFF, 0xFE, 0xFE, 0x00, 0x70, 0x01, 0xFF, 0xCF, 0xB0, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0x7C, 0x00, 0xE0, 0x00, 0x0F, 0x0F, 0x9C, 0x80, 0x00, 0x00, 0x07, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0x38, 0x03, 0xF0, 0x00, 0x06, 0x1F, 0x9E, 0x40, 0x00, 0x00, 0x03, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0x9F, 0xFE, 0x0C, 0x00, 0x0E, 0x1F, 0xDF, 0x30, 0x00, 0x00, 0x01, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xE0, 0x3F, 0x62, 0x00, 0x1C, 0x3F, 0xBF, 0x8E, 0x00, 0x00, 0x00, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xC1, 0xB1, 0x80, 0x7E, 0xFE, 0x7F, 0x83, 0xC0, 0x00, 0x00, 0x7F, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x58, 0x40, 0xFF, 0xF9, 0xFF, 0xC0, 0x78, 0x00, 0x00, 0x7F, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCE, 0x20, 0xFF, 0x87, 0xFF, 0xE0, 0xE0, 0x00, 0x00, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0x11, 0xFF, 0xBF, 0xFF, 0xF8, 0x3F, 0xFF, 0xC3, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xCF, 0xFF, 0xDF, 0xFF, 0xFE, 0x07, 0xFF, 0x07, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x76, 0x7F, 0xBF, 0xFF, 0xFF, 0x80, 0x00, 0x1F, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x94, 0x3E, 0xFF, 0xFF, 0xFF, 0xFC, 0x02, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE8, 0x3D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x78, 0xFF, 0xFF, 0xFF, 0xBF, 0xFF, 0x3F, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF9, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0x9F, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF7, 0xFF, 0xFF, 0xFC, 0x3F, 0xFF, 0xCF, 0xFF, 0xFF,
0xE0, 0x3F, 0xFF, 0xE0, 0x3F, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xF0, 0x07, 0xFF, 0xC7, 0xFF, 0xFF,
0xCF, 0x9F, 0xFF, 0xEF, 0x3F, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0xE0, 0x00, 0xBF, 0xE7, 0xFF, 0xFF,
0xD8, 0xC0, 0x30, 0x03, 0x30, 0x1F, 0xFF, 0x7F, 0xFF, 0xFF, 0xF0, 0x00, 0xFF, 0x1F, 0xFF, 0xFF,
0xD8, 0xCF, 0x87, 0xC3, 0x27, 0xCF, 0xFF, 0x7F, 0xFF, 0xFF, 0xF0, 0x00, 0x60, 0xFF, 0xFF, 0xFF,
0xD8, 0x18, 0xCC, 0x63, 0x2E, 0x6F, 0xFF, 0x7F, 0xFF, 0xFF, 0xF8, 0x02, 0x0F, 0xFF, 0xFF, 0xFF,
0xD8, 0x18, 0xCC, 0x63, 0x20, 0x6F, 0xFF, 0xBF, 0xFF, 0xFF, 0xF0, 0x0D, 0xFF, 0xFF, 0xFF, 0xFF,
0xD8, 0x18, 0xCC, 0x63, 0x30, 0x6F, 0xFF, 0xBF, 0xFF, 0xFF, 0xF8, 0x1B, 0xFF, 0xFF, 0xFF, 0xFF,
0xD8, 0x18, 0xCF, 0xE3, 0x27, 0xEF, 0xFF, 0x9F, 0xFF, 0xFE, 0x40, 0x67, 0xFF, 0xFF, 0xFF, 0xFF,
0xD8, 0xD8, 0xCC, 0x03, 0x2C, 0x6F, 0xFF, 0xDF, 0xFF, 0xFE, 0x01, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF,
0xD8, 0xD8, 0xCC, 0xE3, 0x0C, 0x6F, 0xFF, 0xED, 0xFF, 0xFF, 0xC0, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF,
0xCF, 0x8F, 0x87, 0xCF, 0xC7, 0xEF, 0xFF, 0xE5, 0xFB, 0xFF, 0x81, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xE0, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xF0, 0xFC, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xE0, 0x00, 0x00, 0x00, 0x00, 0x67, 0xFF, 0xFD, 0x1E, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xEF, 0x80, 0x00, 0x0C, 0x30, 0xF7, 0xFF, 0xFF, 0xC1, 0xFF, 0xFF, 0xFF, 0xFF, 0xE1, 0xFF, 0xFF,
0xCF, 0x80, 0x00, 0x0C, 0x30, 0xF7, 0xC0, 0x01, 0xFF, 0xFE, 0x1F, 0xFF, 0xFF, 0xED, 0xFF, 0xFF,
0xD8, 0xC0, 0x00, 0x0C, 0x30, 0xF7, 0xDF, 0xBD, 0xFF, 0xFE, 0xDF, 0xFF, 0xFF, 0xED, 0xFF, 0xFF,
0xD8, 0xCF, 0x8F, 0xC5, 0xFE, 0xF7, 0xD8, 0x0D, 0x80, 0x00, 0xC0, 0x10, 0x00, 0x01, 0x02, 0x07,
0xD8, 0x1C, 0xCC, 0x68, 0x30, 0x67, 0xD8, 0x0D, 0x3C, 0x73, 0xF7, 0xC7, 0x9F, 0x3C, 0x78, 0xF3,
0xD8, 0x00, 0xCC, 0x63, 0xB0, 0x6F, 0xD8, 0x0D, 0x66, 0xC8, 0xC6, 0x6C, 0xD9, 0x8C, 0xCD, 0x9B,
0xD8, 0x0F, 0xCC, 0x6F, 0xB0, 0x6F, 0xDF, 0x0D, 0x66, 0xC8, 0xC6, 0x6C, 0xD9, 0x8C, 0xCD, 0x83,
0xD8, 0x18, 0xCC, 0x6F, 0xB0, 0x6F, 0xD8, 0x0D, 0x7E, 0xC0, 0xC6, 0x0C, 0xD9, 0x8C, 0xC0, 0xF3,
0xD8, 0xD8, 0xCC, 0x6F, 0xB0, 0x0F, 0xD8, 0x0C, 0x60, 0xC8, 0xC6, 0xEC, 0xD9, 0x8C, 0xCC, 0x1B,
0xD8, 0xD8, 0xCC, 0x6F, 0xB0, 0x6F, 0xD8, 0x0C, 0x66, 0xC8, 0xC6, 0xEC, 0xD9, 0x8C, 0xCD, 0x9B,
0xCF, 0x8F, 0xCC, 0x6F, 0x9E, 0x6F, 0xDF, 0xBF, 0x3C, 0x72, 0x76, 0xE7, 0x99, 0xBE, 0x78, 0xF3,
0xE0, 0x20, 0x00, 0x0F, 0xC0, 0x0F, 0xC0, 0x00, 0x01, 0x07, 0x00, 0xF0, 0x00, 0x00, 0x82, 0x07,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

const uint8_t HeadsUpDisplay::PrototracerSplash[] = {
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xF8, 0x00, 0xFF, 0xFF, 0xFE, 0x03, 0xFF, 0xF0, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xF0, 0x00, 0x7F, 0xFF, 0xFE, 0x01, 0xFF, 0xF0, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xF1, 0xFC, 0x3F, 0xFF, 0xFE, 0x71, 0xFF, 0xF3, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xF1, 0xFC, 0x00, 0x00, 0x00, 0x70, 0x00, 0x03, 0x80, 0x01, 0x00, 0x20, 0x08, 0x00, 0x00, 0x7F,
0xF1, 0xC7, 0x00, 0x00, 0x00, 0x70, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F,
0xF1, 0xC7, 0x7F, 0x87, 0xE3, 0xFE, 0x3F, 0x1F, 0xF3, 0xF8, 0x3F, 0x0F, 0xC1, 0xF8, 0xFE, 0x1F,
0xF1, 0xC7, 0x7F, 0x87, 0xE3, 0xFE, 0x3F, 0x1F, 0xF3, 0xF8, 0x3F, 0x0F, 0xC1, 0xF8, 0xFE, 0x1F,
0xF1, 0xC7, 0x71, 0xCE, 0x38, 0x70, 0x71, 0xC3, 0x83, 0x8E, 0xE3, 0x9C, 0x77, 0x1C, 0xE3, 0x9F,
0xF1, 0xFC, 0x71, 0xCE, 0x38, 0x70, 0x71, 0xC3, 0x83, 0x8E, 0x03, 0x9C, 0x77, 0x1C, 0xE3, 0x9F,
0xF1, 0xFC, 0x71, 0xCE, 0x38, 0x70, 0x71, 0xC3, 0x83, 0x8E, 0x03, 0x9C, 0x77, 0x1C, 0xE3, 0x9F,
0xF1, 0xC0, 0x70, 0x0E, 0x38, 0x70, 0x71, 0xC3, 0x83, 0x80, 0x3F, 0x9C, 0x07, 0xFC, 0xE0, 0x1F,
0xF1, 0xC0, 0x70, 0x0E, 0x38, 0x70, 0x71, 0xC3, 0x83, 0x80, 0xE3, 0x9C, 0x77, 0x00, 0xE0, 0x3F,
0xF1, 0xCE, 0x71, 0x8E, 0x38, 0x70, 0x71, 0xC3, 0x83, 0x9C, 0xE3, 0x9C, 0x77, 0x00, 0xE7, 0xFF,
0xF1, 0xCE, 0x71, 0x8E, 0x38, 0x70, 0x71, 0xC3, 0x83, 0x9C, 0xE3, 0x9C, 0x77, 0x1C, 0xE7, 0xFF,
0xF1, 0xCE, 0x71, 0x87, 0xE0, 0x1E, 0x3F, 0x00, 0xF3, 0x9C, 0x3F, 0x8F, 0xC1, 0xF8, 0xE7, 0xFF,
0xF1, 0xCE, 0x71, 0xC7, 0xE0, 0x1E, 0x3F, 0x00, 0xF3, 0x9C, 0x3F, 0x8F, 0xC1, 0xF8, 0xE7, 0xFF,
0xF8, 0x0E, 0x03, 0xE0, 0x07, 0x80, 0x00, 0x1C, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF,
0xF8, 0x1F, 0x03, 0xF0, 0x07, 0x80, 0x00, 0x3C, 0x00, 0x3F, 0x00, 0x00, 0x08, 0x00, 0x0F, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x77,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x8F, 0xFB,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x02, 0x3F, 0xFB,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0xE7, 0xFE, 0x7F, 0xE6, 0x10, 0x00, 0x08, 0xFF, 0xFB,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x01, 0xE6, 0x06, 0x60, 0x6E, 0x10, 0x00, 0x11, 0xFF, 0xF7,
0xE0, 0x00, 0x00, 0x00, 0x3F, 0xC0, 0x03, 0xEE, 0x06, 0x60, 0x6C, 0x18, 0x00, 0x43, 0xC3, 0xE7,
0xEF, 0xEF, 0x42, 0x3F, 0xBF, 0xC0, 0x03, 0x6E, 0x0E, 0xE0, 0xEC, 0x38, 0x00, 0x83, 0x03, 0xEF,
0xE8, 0x21, 0xA1, 0x20, 0xBF, 0xC0, 0x06, 0xCC, 0x0C, 0xC0, 0xCC, 0x38, 0x03, 0x04, 0x07, 0x9F,
0xEB, 0xA5, 0x53, 0xAE, 0xBF, 0xC0, 0x0C, 0xCC, 0x00, 0xC0, 0xDC, 0x38, 0x04, 0x00, 0x0F, 0x1F,
0xEB, 0xA3, 0x44, 0xAE, 0xBF, 0x80, 0x18, 0xCC, 0x00, 0xC0, 0xDC, 0x38, 0x08, 0x00, 0x1F, 0xDF,
0xEB, 0xA3, 0xBF, 0x2E, 0xBF, 0x80, 0x30, 0xDC, 0x01, 0xC1, 0xD8, 0x3C, 0x10, 0x00, 0x3F, 0xFF,
0xE8, 0x25, 0x06, 0xA0, 0xBF, 0x80, 0x61, 0x98, 0xFD, 0xFF, 0xD8, 0x3C, 0x30, 0x00, 0xFF, 0xDF,
0xEF, 0xEA, 0xAA, 0xBF, 0xBF, 0x80, 0xFF, 0x98, 0x19, 0xFF, 0x18, 0x3C, 0x60, 0x01, 0xC7, 0xDF,
0xE0, 0x0C, 0xD8, 0x00, 0x3F, 0x01, 0xFF, 0x98, 0x19, 0x80, 0x38, 0x3C, 0xC0, 0x02, 0x07, 0xBF,
0xED, 0xA4, 0xAC, 0x20, 0xBF, 0x03, 0x01, 0xB8, 0x19, 0x80, 0x30, 0x1E, 0xC0, 0x00, 0x0F, 0xBF,
0xE8, 0xC2, 0x33, 0x5B, 0x3F, 0x06, 0x03, 0x38, 0x3B, 0x80, 0x30, 0x1D, 0x80, 0x00, 0x1F, 0x7F,
0xEB, 0x7C, 0xF2, 0x1A, 0x3F, 0x0C, 0x03, 0x30, 0x33, 0x80, 0x30, 0x1F, 0x80, 0x00, 0x3E, 0xFF,
0xE7, 0x08, 0x25, 0x74, 0xBF, 0x18, 0x03, 0x3F, 0xF3, 0x00, 0x7F, 0x9B, 0x80, 0x00, 0xFD, 0xFF,
0xEC, 0xFE, 0x11, 0xB0, 0xBE, 0x30, 0x03, 0x1F, 0xE3, 0x00, 0x7F, 0x9F, 0x80, 0x03, 0xFB, 0xFF,
0xE1, 0x0A, 0xFA, 0x3F, 0xBE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x80, 0x0F, 0xE7, 0xFF,
0xE5, 0x26, 0x73, 0xEA, 0xBE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xC0, 0x7F, 0xCF, 0xFF,
0xEE, 0x9A, 0x91, 0x1A, 0xBE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xBF, 0xFF,
0xEA, 0xA9, 0xC1, 0xC4, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFE, 0x7F, 0xFF,
0xEC, 0x95, 0x33, 0x0B, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xF9, 0xFF, 0xFF,
0xEC, 0x2A, 0xB9, 0x0C, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xE7, 0xFF, 0xFF,
0xED, 0x03, 0x73, 0x26, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0x9F, 0xFF, 0xFF,
0xEE, 0xF9, 0x54, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF8, 0x7F, 0xFF, 0xFF,
0xE0, 0x0E, 0xF0, 0x8C, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0xFF, 0xFF, 0xFF,
0xEF, 0xE7, 0x55, 0xAC, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xE8, 0x23, 0xCF, 0x89, 0xBF, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF,
0xEB, 0xAB, 0xD3, 0xFD, 0x38, 0x7F, 0xFF, 0xFF, 0xE7, 0xF8, 0x7F, 0xFF, 0x9F, 0xFF, 0xFF, 0xFF,
0xEB, 0xA8, 0x68, 0x40, 0xBB, 0xEC, 0xE7, 0xCC, 0xFF, 0x7B, 0xEC, 0xEF, 0x39, 0xE9, 0xFF, 0xFF,
0xEB, 0xA1, 0xD2, 0xDB, 0xB8, 0x8A, 0xD7, 0x2B, 0xE8, 0x78, 0x8A, 0x94, 0xA5, 0xA5, 0xFF, 0xFF,
0xE8, 0x29, 0x10, 0x36, 0xB3, 0xB0, 0x87, 0x49, 0xE9, 0x73, 0xB0, 0x85, 0xAD, 0x2D, 0xFF, 0xFF,
0xEF, 0xEE, 0x23, 0xA8, 0x37, 0xB3, 0xBE, 0x4C, 0xCB, 0x77, 0xB7, 0xBD, 0x2D, 0x6D, 0xFF, 0xFF,
0xE0, 0x00, 0x00, 0x00, 0x37, 0xB8, 0x8F, 0x11, 0xDB, 0x77, 0x38, 0x8C, 0x23, 0x69, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

const uint8_t HeadsUpDisplay::FaceTemplate[] = {
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xC0, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x03,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFD,
0xA3, 0x62, 0x3F, 0xFF, 0xCC, 0xC6, 0x54, 0x7F, 0xC4, 0x46, 0x44, 0x47, 0xD6, 0x45, 0x44, 0x7D,
0xAE, 0xAE, 0xFF, 0xFE, 0x55, 0x6D, 0xD6, 0xFE, 0x5D, 0xDD, 0xEF, 0x5E, 0x55, 0xDC, 0x6D, 0xFD,
0xA6, 0x2E, 0x7F, 0xFF, 0xCC, 0xED, 0x46, 0xFF, 0xCD, 0xCE, 0xEE, 0xCF, 0xD6, 0xCC, 0x6D, 0xFD,
0xAE, 0xAE, 0xFF, 0xFE, 0x55, 0x6D, 0x56, 0xFE, 0x5D, 0xDF, 0x6D, 0xDE, 0x57, 0x5D, 0x6D, 0xFD,
0xAE, 0xA2, 0x3F, 0xFF, 0xCD, 0x46, 0x56, 0xFF, 0xDC, 0x44, 0xC4, 0x47, 0xC4, 0xC5, 0x44, 0x7D,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFD,
0xD5, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAB,
0xD5, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAB,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFD,
0xA2, 0x22, 0x22, 0x3F, 0xE4, 0xCC, 0x65, 0x46, 0x44, 0x44, 0x45, 0xCF, 0xD6, 0x44, 0xC4, 0x45,
0xAE, 0xEE, 0xEF, 0x7E, 0x5D, 0x56, 0xDD, 0x6E, 0x5D, 0xDD, 0xD5, 0xD6, 0x55, 0xDD, 0x55, 0x55,
0xA6, 0x66, 0x6F, 0x7F, 0xEC, 0xCE, 0xD4, 0x6F, 0xCD, 0xCD, 0xD5, 0xCF, 0xD6, 0xCC, 0xD5, 0x45,
0xAE, 0xEE, 0xEF, 0x7E, 0x75, 0x56, 0xD5, 0x6E, 0x5D, 0xDD, 0xD5, 0xD6, 0x57, 0x5D, 0x55, 0x5D,
0xA2, 0xEE, 0x23, 0x7F, 0xCC, 0xD4, 0x65, 0x6F, 0xDC, 0x44, 0x44, 0x57, 0xC4, 0xC4, 0xC4, 0x5D,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFD,
0xC0, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x03,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xC0, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xAA, 0xA2, 0x26, 0x23, 0xD4, 0x45, 0xD5, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xAA, 0xAE, 0xEA, 0xB6, 0x46, 0xDD, 0xD5, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xA2, 0xA6, 0x66, 0xB7, 0xC6, 0xDD, 0xD5, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xAA, 0xAE, 0xEA, 0xB6, 0x56, 0xDD, 0xD5, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xAA, 0x22, 0xEA, 0xB7, 0xD4, 0x44, 0x6C, 0x7E, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xD5, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xD5, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xAA, 0xA2, 0x76, 0x2B, 0xC6, 0xC6, 0x44, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xAA, 0xAE, 0xAA, 0xEA, 0x5D, 0x55, 0xD5, 0x7E, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xA2, 0xA6, 0x6A, 0xE7, 0xCC, 0x56, 0xC5, 0x7E, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xAA, 0xAE, 0xA2, 0xEA, 0x5D, 0x57, 0x5D, 0x7E, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xAA, 0x22, 0x6A, 0x2B, 0xDD, 0x54, 0xDC, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xBF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,
0xC0, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

HeadsUpDisplay::HeadsUpDisplay(Vector2D faceMin, Vector2D faceMax) {
    this->faceMin = faceMin;
    this->faceMax = faceMax;
}

void HeadsUpDisplay::SetFaceArray(const __FlashStringHelper** faceNames) {
    this->faceNames = faceNames;
    useExternalFace = true;
}

void HeadsUpDisplay::SetFaceMin(Vector2D faceMin) {
    this->faceMin = faceMin;
}

void HeadsUpDisplay::SetFaceMax(Vector2D faceMax) {
    this->faceMax = faceMax;
}

void HeadsUpDisplay::Initialize() {
    ResetDisplayBuffer();

    Wire.setClock(100000);//for longer range transmissions
    Wire.begin();
    
    #ifdef WS35
    Wire.setSDA(19);
    Wire.setSCL(18);
    #else
    Wire.setSDA(18);
    Wire.setSCL(19);
    #endif

    Wire.beginTransmission(0x3C);
    uint8_t error = Wire.endTransmission();

    if(error == 0){// SSD1306 Found
        didBegin = display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

        // Initialize the OLED display
        if (!didBegin) {
            // Handle initialization failure here
        }

        display.setFont(&Picopixel);

        // Clear the buffer and display
        display.clearDisplay();
        display.invertDisplay(true);
        display.display();
    }
    else {
        didBegin = false;
    }

    startMillis = millis();

}

void HeadsUpDisplay::ResetI2CBus() {
    Wire.end();   // Disable the I2C hardware
    delay(10);    // Wait for the I2C bus to settle
    Wire.begin(); // Enable the I2C hardware
}

void HeadsUpDisplay::Update() {
    if (timeStep.IsReady() && didBegin){
        if (splashFinished){// Draw the bitmap to the display at the specified top-left coordinate
            UpdateFaceInformation();
        }
        else if (startMillis + splashTime > millis()){
            display.clearDisplay();
            display.drawBitmap(0, 0, CoelaSplash, SCREEN_WIDTH, SCREEN_HEIGHT, 1);
        }
        else if (startMillis + (splashTime * 2L) > millis()){
            display.clearDisplay();
            display.drawBitmap(0, 0, PrototracerSplash, SCREEN_WIDTH, SCREEN_HEIGHT, 1);
        }
        else{
            splashFinished = true;
        }

        unsigned long cmdTime = millis();
        
        display.display();

        if (millis() - cmdTime > 250) {
            // Timeout occurred
            ResetI2CBus();
        }

        ResetDisplayBuffer();
    }
}

void HeadsUpDisplay::SetEffect(Effect* effect) {
    subEffect = effect;
}

void HeadsUpDisplay::ApplyEffect(IPixelGroup* pixelGroup) {
    //Actually apply effect
    subEffect->ApplyEffect(pixelGroup);
    
    unsigned int pixelCount = pixelGroup->GetPixelCount();
    
    for (unsigned int i = 0; i < pixelCount; i++){
        Vector2D pixelLocation = pixelGroup->GetCoordinate(i);
        RGBColor color = *pixelGroup->GetColor(i);

        if(color.R > 0 || color.G > 0 || color.G > 0){
            EnableBitFaceRender(pixelLocation.X, pixelLocation.Y);
        }
    }
}

void HeadsUpDisplay::ResetDisplayBuffer() {
    // Initialize the bitmap array to zero
    memset(faceBitmap, 0, sizeof(faceBitmap));
}

void HeadsUpDisplay::EnableBitFaceRender(float xIn, float yIn) {
    uint16_t x = Mathematics::ConstrainMap(xIn, faceMax.X, faceMin.X, 0.0f, float(faceXMaxPosition - faceXMinPosition));
    uint16_t y = Mathematics::ConstrainMap(yIn, faceMax.Y, faceMin.Y, 0.0f, float(faceYMaxPosition - faceYMinPosition));

    if (x >= 0 && x < 64 && y >= 0 && y < 32) {
        int byteIndex = y * 8 + (x / 8);
        int bitIndex = 7 - (x % 8);

        faceBitmap[byteIndex] |= (1 << bitIndex);
    }
}

void HeadsUpDisplay::UpdateFaceInformation() {
    display.clearDisplay();

    display.drawBitmap(0, 0, FaceTemplate, 128, 64, 1);

    display.setTextColor(0);        // Draw white text
    display.setTextSize(1);             // Normal 1:1 pixel scale

    //ROW 1
    if (useExternalFace) CheckInvertPrintText(3, 13, 0, faceNames[Menu::GetFaceState()]);//Face
    else CheckInvertPrintText(3, 13, 0, faceArray[Menu::GetFaceState()]);
    
    CheckInvertPrintText(34, 13, 1, percentArray[Menu::GetBrightness()]);//Brightness
    CheckInvertPrintText(66, 13, 7, percentArray[Menu::GetFaceSize()]);//Face Size
    CheckInvertPrintText(98, 13, 3, onOffArray[Menu::UseMicrophone()]);//Use Microphone

    //ROW 2
    CheckInvertPrintText(3, 28, 11, effectArray[Menu::GetEffectS()]);//Effect
    CheckInvertPrintText(34, 28, 2, percentArray[Menu::GetAccentBrightness()]);//Side Brightness
    CheckInvertPrintText(66, 28, 8, colorArray[Menu::GetFaceColor()]);//Face Color
    CheckInvertPrintText(98, 28, 5, onOffArray[Menu::UseBoopSensor()]);//Use Boop

    //ROW 3
    CheckInvertPrintText(3, 45, 9, hueArray[Menu::GetHueF()]);//Hue front
    CheckInvertPrintText(34, 45, 4, percentArray[Menu::GetMicLevel()]);//Mic level

    //ROW 4
    CheckInvertPrintText(3, 60, 10, hueArray[Menu::GetHueB()]);//Hue back
    CheckInvertPrintText(34, 60, 12, percentArray[Menu::GetFanSpeed()]);//Mirror spectrum analyzer
    
    display.drawBitmap(66, 35, faceBitmap, 64, 32, 0);
}


void HeadsUpDisplay::CheckInvertPrintText(int16_t x, int16_t y, uint8_t menu, const String &str){
    int16_t x1, y1;
    uint16_t w, h;
    
    if (Menu::GetCurrentMenu() == menu && millis() % 500 > 250){
        display.getTextBounds(str, x, y, &x1, &y1, &w, &h);
        
        //display.setCursor(x, y + h);
        display.fillRect(x, y - h + 1, w, h, 0);

        display.setTextColor(1);
    }

    display.setCursor(x, y);
    display.println(str);

    display.setTextColor(0);
}

