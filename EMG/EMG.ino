#include <Servo.h>
#define THRESHOLD 250
#define EMG_PIN 0
#define SERVO_PIN 0
#define SERVO_PIN 3

Servo SERVO_1;

void setup() 
{
   Serial.begin(115200);
  //set sevo motor of digital pin 3
  SERVO_1.attach(SERVO_PIN);
}

void loop() {

  int value = analogRead(EMG_PIN);

  if(value > THRESHOLD){
    SERVO_1.write(170);
  }

  else{
    SERVO_1.write(10);
  }

  Serial.println(value);
}
 
