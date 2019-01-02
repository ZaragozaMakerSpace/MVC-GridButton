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

class TXTButton: public Adafruit_GFX_Button{
  public:
    uint16_t _x, _y, _w, _h;
    uint8_t _marginx, _marginy, _txtsize;
    uint16_t _c, _c_txt, _c_border;
    char* _msg;
    String _str;

    TXTButton::TXTButton(void):Adafruit_GFX_Button(),_marginx(10), _marginy(5), _c( 0xFFFF ), _c_txt( 0x0000 ), _c_border( 0xFFFF ), _txtsize( 4 ) {};
    
    TXTButton( char* msg, uint16_t x, uint16_t y, uint16_t c = 0xFFFF , uint16_t txtc = 0x0000,uint16_t borderc = 0xFFFF, uint8_t textsize = 4,  uint8_t mgx = 10, uint8_t mgy = 10  )
      :Adafruit_GFX_Button( ),_str( msg ), _x( x ), _y( y ),_marginx(mgx), _marginy(mgy), _c( c ), _c_txt( txtc ), _c_border( borderc ), _txtsize( textsize )  {
      _msg = msg;
    }

    TXTButton( String msg, uint16_t x, uint16_t y,  uint16_t c = 0xFFFF , uint16_t txtc = 0x0000, uint16_t borderc = 0xFFFF, uint8_t textsize = 4,  uint8_t mgx = 10, uint8_t mgy = 5  )
      :Adafruit_GFX_Button( ),_str( msg ), _x( x ), _y( y ),_marginx(mgx), _marginy(mgy), _c( c ), _c_txt( txtc ), _c_border( borderc ), _txtsize( textsize )  {
      
    }

    void init (Adafruit_GFX& _tft ){
      
      uint16_t msg_w = _str.length()*_txtsize*5+ (_str.length()-1)*_txtsize;
      uint16_t msg_h = _txtsize*8;
      
      //Tamanio real del boton
      uint16_t btn_w = msg_w+2*_marginx;
      uint16_t btn_h = msg_h+2*_marginy;
      // Center of Button
      
      uint16_t btn_x = _x ;
      uint16_t btn_y = _y ;
      
      char buf[ 10 ];
      _str.toCharArray( buf, _str.length()+1 );
      
      initButton( &_tft ,btn_x, btn_y, btn_w, btn_h, _c_border , _c, _c_txt, buf, _txtsize);
    }

    void setStr( char* msg ){
      _str = msg;
    };
    
    void setStr( String  str ){
      _str = str;
    };
    
    void setTextSize( uint16_t  size ){
      _txtsize = size;
    };
    
    void setMarginSize(  uint16_t  mx,uint16_t my ){
      _marginx =mx;
      _marginy =my;
    };

    void setXY( uint16_t  x,uint16_t y ){
      setX(x);
      setY(y);
    };

    void setX( uint16_t  x ){
      _x =x;
    };

    void setY( uint16_t  y ){
      _y =y;
    };
    
    void setColor( uint16_t  c, uint16_t ctxt, uint16_t cBorder ){
      setFillColor(c);
      setTextColor( ctxt );
      setBorderColor (cBorder);
    };
    
    void setTextColor( uint16_t  c ){
      _c_txt = c;
    };
    
    void setBorderColor( uint16_t  c ){
      _c_border = c;
    };
    void setFillColor( uint16_t  c ){
      _c = c;
    };
    
    void draw(bool inv = true){
      drawButton(inv);
    }
    
    void clear(Adafruit_GFX& _tft, uint16_t  c ){
      setColor( c, c, c );
      //initButton( &_tft ,btn_x, btn_y, btn_w, btn_h, _c_border , _c, _c_txt, buf, _txtsize);
      init ( _tft );
      drawButton(true);
    }
};

bool evt_change = true;

uint16_t w=320;
uint16_t h=240;

String title ="ZGZMakerSpace";
TXTButton topBtn( title, w/2,h/4 ,BLUE,  YELLOW, GREEN, 3);
TXTButton leftBtn ( "ZMS", w/3,h/2 ,GREEN,  YELLOW, BLACK, 2);
TXTButton rightBtn  ( "100", 2*w/3, h/2 ,BLACK, WHITE, BLUE, 4);

void setup() {
  Serial.begin(9600);
  tft.begin();  // Begin ILI9341
  tft.setRotation(3);
  tft.fillScreen( WHITE );
  w = tft.width() ;
  h = tft.height() ;

  topBtn.init( tft );
  topBtn.draw();
  
  leftBtn.init( tft );
  leftBtn.draw();

  rightBtn.init( tft );
  rightBtn.draw();
}

void loop() {
  
  if( millis() > 5000 && evt_change){
    evt_change = false;
    //Cambiar el boton derecho a su inverso
    rightBtn.draw( false );
    //Borrar el boton anterior
    topBtn.clear( tft, WHITE );

    //Modificar las propiedades del boton y dibujar el nuevo
    title ="Hi Maker!"; 
    topBtn.setStr( title );
    topBtn.setTextSize( 2 );
    topBtn.setColor( BLACK, CYAN, BLUE );
    topBtn.setMarginSize(20,20);
    topBtn.init( tft );
    topBtn.draw();
  }
  
}
