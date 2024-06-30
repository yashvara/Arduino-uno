#include <SoftwareSerial.h> // here we are including the library

//Create software serial object to communicate with SIM900

SoftwareSerial mySerial(7, 8); // initializing it with the Arduino pins to which Tx and Rx of SIM900 shield is connected

void setup()
{
 
  Serial.begin(9600);  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor) with baud rate of 9600
  
  mySerial.begin(9600);  //Begin serial communication with Arduino and SIM900

  Serial.println("Initializing...");  // printing 
  delay(1000);  // for delay

  mySerial.println("AT"); //Handshaking with SIM900
  updateSerial();
  mySerial.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
  updateSerial();
  mySerial.println("AT+CCID"); //Read SIM information to confirm whether the SIM is plugged
  updateSerial();
  mySerial.println("AT+CREG?"); //Check whether it has registered in the network
  updateSerial();
}

void loop()
{
  updateSerial(); // we have called the function here
}

void updateSerial()  // made this because it will waits for any inputs from the serial monitor and send it to the SIM900 shield
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
