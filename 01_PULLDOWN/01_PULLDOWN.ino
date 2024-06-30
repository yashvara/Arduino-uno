int button=0;
int LED=12;
 void setup()
 {
  pinMode(4, INPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
 }

void loop()
{
  button=digitalRead(4);
 
  if(button == HIGH)
  {
    digitalWrite(12, HIGH);
    Serial.println("Button is ON");
  }
  else
  {   
    digitalWrite(12, LOW);
    Serial.println("Button is OFF");
    delay(15); // Delay a lil bit to make the simulation performance good  
  }
  
}
