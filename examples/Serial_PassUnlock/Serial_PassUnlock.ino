
String pass = "1984";
char str_array[4];
int counter = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if ( Serial.available() ){
    char digit = Serial.read();

    if ( digit  == pass[counter] ){
      counter++;
      Serial.print("Digit ");Serial.print(digit);Serial.print(" in position ");Serial.print( counter );Serial.println( " is correct!!" );
    }else{
      counter = 0;
      Serial.print("Digit ");Serial.print(digit);
      Serial.println(" Failed. Try again");
    }
    
    if (counter == 4 ){
      Serial.println("Pass Unlocked");
    }
  }
}
