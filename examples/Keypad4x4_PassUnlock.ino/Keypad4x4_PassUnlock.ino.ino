#include "Keypad.h"

String pass = "1984";
char str_array[4];
int counter = 0;

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {4,5,6,7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A3, A2, A1, A0};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  Serial.println("Keypad Panel");
  
}

void loop() {
  char key = keypad.getKey();

  if (key) {
      
      if ( key  == pass[counter] ){
        counter++;
        Serial.print("Digit ");Serial.print(key);Serial.print(" in position ");Serial.print( counter );Serial.println( " is correct!!" );
      }else{
        counter = 0;
        Serial.print("Digit ");Serial.print(key);
        Serial.println(" Failed. Try again");
      }
      
      if (counter == 4 ){
        Serial.println("Pass Unlocked");
      }
    
  }
    
}
