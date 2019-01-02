#include <SPI.h>

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define ROSE  0xF81F
#define WHITE   0xFFFF

#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 8
#define TFT_CS 9

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

Adafruit_GFX_Button topBtn;
Adafruit_GFX_Button leftBtn;
Adafruit_GFX_Button rightBtn;

uint16_t w,h;

void setup() {
  Serial.begin(9600);
  tft.begin();  // Begin ILI9341
  tft.setRotation(3);
  tft.fillScreen ( WHITE );
  
  w = tft.width() ;
  h = tft.height() ;

  topBtn.initButton( &tft, w/2,h/4, w ,50,BLUE,  YELLOW, GREEN,"ZGZMakerSpace", 3);
  topBtn.drawButton();
  
  leftBtn.initButton( &tft, w/3,h/2,100,50,GREEN,  YELLOW, BLACK,"ZMS", 2);
  leftBtn.drawButton();

  rightBtn.initButton( &tft, 2*w/3,h/2,50,50,RED, WHITE, BLUE,"100", 4);
  rightBtn.drawButton();
}

void loop() {
  // put your main code here, to run repeatedly:

}
