#include <LiquidCrystal.h>
LiquidCrystal lcd (12,11,5,4,3,2) ;
int pbutton = 8;
int count = 0;
void setup() {
lcd.begin(16,2);
//lcd.setCursor(0,0);
//lcd.print ("YASH VARA");
pinMode(pbutton, INPUT);
}
void loop(){
  if (digitalRead(pbutton) == HIGH )
  {
    lcd.setCursor(0,0);
   lcd.print(count++);
   while (digitalRead(pbutton) == HIGH);

  }

  }
