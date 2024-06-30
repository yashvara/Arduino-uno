char data = 0;                //Variable for storing received data
void setup() 
{
Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
pinMode(13, OUTPUT);        //Sets digital pin 13 as output pin
pinMode(8, OUTPUT);          // for fan 
}
void loop()
{
  //digitalWrite(13, HIGH);
  if(Serial.available() > 0)  // Send data only when you receive data:
  {
  data = Serial.read();      //Read the incoming data and store it into variable data
  Serial.print(data);        //Print Value inside data in Serial monitor
  Serial.print("\n");        //New line 
  if(data == '1')            //Checks whether value of data is equal to 1 
  {
    digitalWrite(13, HIGH);    //If value is 1 then LED turns ON
    digitalWrite(8, HIGH);     // FAN on
    tone(13,1000);

  }
  else if(data == '0')       //Checks whether value of data is equal to 0
  {
    digitalWrite(13, LOW);   //If value is 0 then LED turns OFF
    digitalWrite(8, LOW);    // FAN OFF
    noTone(13);
  }  
  }                          

}
