
int val;
void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A0);
  Serial.println(val);
  delay(1000);
}
