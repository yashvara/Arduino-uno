int ledPin = 13;               
int inputPin = 2;              
int val = 0;                    
int pirState = LOW;             
 
void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(inputPin, INPUT);     
 
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(inputPin);  
  if (val == HIGH) {            
    digitalWrite(ledPin, HIGH);  
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      
      pirState = HIGH;
    }
  }
  
  else {
    digitalWrite(ledPin, LOW); 
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      
      pirState = LOW;
    }
   }
  }  
