int Led_Pin = ;
int duty_cycle_value = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode (Led_Pin , OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  while(duty_cycle_value<255)
  {
    analogWrite(Led_Pin, duty_cycle_value);
    delay(3000);
    duty_cycle_value++; 
  }

}
