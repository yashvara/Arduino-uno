//Smoke sensor
#define MQ2pin (0)
float sensorValue; //variable to store sensor value

//IRa
int statusSensor; // IR sensor value.

//Bluetooth sensor
char data = 0; 

int fan = 8;
int ledPin = 12;              

int IRSensor = 8;               
 
void setup() {

// smoke sensor
// delay(20000); // allow the MQ-2 to warm up

// IR
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  
  pinMode (ledPin, OUTPUT); // Led pin OUTPUT

  //Bluetooth
  pinMode(fan, OUTPUT); // bluetooth
  
  Serial.begin(9600); 


}

void loop()
{
 //Smoke sensor
 sensorValue = analogRead(MQ2pin); // read analog input pin 0
 Serial.print("\nSmoke Value: \n");
 Serial.print(sensorValue);

 if(sensorValue >= 450)
 {
   Serial.print("\n DANGER: High amount of smoke detected! \n");
   digitalWrite(12, HIGH);  

 }
 else
 {
   digitalWrite(12, LOW);   
 }

  // IR 
  int statusSensor = digitalRead (IRSensor);
  
  if (statusSensor == 1)
  {
    digitalWrite(13, LOW); // LED LOW
  }
  
  else
  {
    digitalWrite(13, HIGH); // LED High
  }

  // Bluetooh
  if(Serial.available() > 0)  // Send data only when you receive data:
  {
    data = Serial.read();      //Read the incoming data and store it into variable data
    Serial.print(data);        //Print Value inside data in Serial monitor
    Serial.print("\n");        //New line 
    if(data == '1')         //Checks whether value of data is equal to 1 
    {
      Serial.print("\n FAN ON");
      digitalWrite(fan, HIGH);  //If value is 1 then LED turns ON
    }
    else if(data == '0')      //Checks whether value of data is equal to 0
    {
      Serial.print("\n FAN OFF");
      digitalWrite(fan, LOW);   //If value is 0 then LED turns OFF
    }
  }   
  delay(2000);
}
