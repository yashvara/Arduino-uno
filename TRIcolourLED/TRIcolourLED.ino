void setup() 
{
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(5, INPUT);
}

void loop()
{ if(digitalRead(5) == HIGH )

  { digitalWrite(10,HIGH);
  delay(500);
  digitalWrite(10,LOW);
  delay(500);
  digitalWrite(11,HIGH);
  delay(500);
  digitalWrite(11,LOW);
  delay(500);
  digitalWrite(12,HIGH);
  delay(500);
  digitalWrite(12,LOW);
  delay(500);
  }
}
