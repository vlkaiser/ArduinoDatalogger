/********************************************************* 
  1.44" TFT LCD Module
  ********************************************************/
 #include <Adafruit_ST7735.h>      // TFT

// Display
#define TFT_CS         5    // Chip Select
#define TFT_RST       -1    // Connect to Arduino RESET pin
#define TFT_DC         8    // 

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);