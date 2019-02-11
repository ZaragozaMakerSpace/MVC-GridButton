#include <URTouch.h>

#define T_CLK 7
#define T_CS 3
#define T_DIN 4
#define T_D0UT 5
#define T_IRQ 6

#define TOUCH_ORIENTATION  LANDSCAPE

URTouch  TS( T_CLK, T_CS, T_DIN, T_D0UT, T_IRQ );

uint32_t x, y;
/*uint32_t cx, cy;
uint32_t rx[8], ry[8];
uint32_t clx, crx, cty, cby;
float px, py;
int dispx, dispy, text_y_center;
uint32_t calx, caly, cals;
char buf[13];
*/
void setup() {
  Serial.begin(9600);
  Serial.print("Touchscreen TFT ");
  TS.InitTouch(TOUCH_ORIENTATION);
  TS.setPrecision(PREC_MEDIUM);
}

void loop() {
  if (TS.dataAvailable()) {
      TS.read();
      x=TS.getX();
      y=TS.getY();
      Serial.print("X: ");Serial.print(x);Serial.print("\tY: ");Serial.print(y);
    }
}

/*void readCoordinates()
{
  int iter = 5000;
  int failcount = 0;
  int cnt = 0;
  uint32_t tx=0;
  uint32_t ty=0;
  boolean OK = false;
  
  while (OK == false)
  {
    //myGLCD.setColor(255, 255, 255);
    //myGLCD.print("*  PRESS  *", CENTER, text_y_center);
    while (TS.dataAvailable() == false) {}
    //myGLCD.print("*  HOLD!  *", CENTER, text_y_center);
    while ((TS.dataAvailable() == true) && (cnt<iter) && (failcount<10000))
    {
      TS.calibrateRead();
      if (!((TS.TP_X==65535) || (TS.TP_Y==65535)))
      {
        tx += TS.TP_X;
        ty += TS.TP_Y;
        cnt++;
      }
      else
        failcount++;
    }
    if (cnt>=iter)
    {
      OK = true;
    }
    else
    {
      tx = 0;
      ty = 0;
      cnt = 0;
    }
    if (failcount>=10000)
      //fail();
  }

  cx = tx / iter;
  cy = ty / iter;
}*/

void waitForTouch()
{
  while (TS.dataAvailable() == true) {}
  while (TS.dataAvailable() == false) {}
  while (TS.dataAvailable() == true) {}
}
