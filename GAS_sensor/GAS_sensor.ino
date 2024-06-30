#define MQ2pin (0)

float sensorValue;  //variable to store sensor value
int buzzer = 10;

void setup()
{
  Serial.begin(9600); 
  Serial.println("Gas sensor warming up!");  
  pinMode(buzzer, OUTPUT);
  delay(20000);   // allow the MQ-6 to warm up
  
}
void loop()
{
  sensorValue = analogRead(MQ2pin); // read analog input pin 0
  
  Serial.print("\nSensor Value: ");
  Serial.print(sensorValue);
  
  if(sensorValue > 900)
  {
    Serial.print(" | Smoke detected!");
//    tone(buzzer, 1000, 200);
  }
  else if(sensorValue < 300) 
  {
    Serial.print("Smoke Not detected!");
//    tone(buzzer, 0, 0);
  }

}
