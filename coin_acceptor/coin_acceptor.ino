/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
float wallet = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial3.begin(9600, SERIAL_8N1); // SERIAL_8N1 can be omitted
}

// the loop routine runs over and over again forever:
void loop() {

  if(Serial3.available() == 5){
    byte b1 = Serial3.read();
    byte b2 = Serial3.read();
    byte b3 = Serial3.read();
    byte b4 = Serial3.read();
    byte b5 = Serial3.read();
    
    if(b5 != 0){
      // For debugging
      /*Serial.print(b1, HEX);
      Serial.print(" ");
      Serial.print(b2, HEX);
      Serial.print(" ");
      Serial.print(b3, HEX);
      Serial.print(" ");
      Serial.print(b4, HEX);
      Serial.print(" ");
      Serial.print(b5, HEX);
      Serial.print(" / ");
      Serial.println(b5, DEC);*/
  
      if(b5 == 0x96) Serial.println("error this shit is too small...i dont eat this stuff");
      else if(b5 == 0x92){
        Serial.println("someone pushed the big white button! now i haz no money in ma wallet");
        wallet = 0;
      }
      else if (b5 >= 0x80 && b5 <= 0x8F){
        float value = (b4-0xF0)*10 + (b3-0xE0) + (b2-0xD0)*0.1 + (b1-0xC0)*0.01;
        wallet += value;
        Serial.print("there is: ");
        Serial.print(wallet);
        Serial.println(" euroz in ma wallet");
      }
    }
  }
}



