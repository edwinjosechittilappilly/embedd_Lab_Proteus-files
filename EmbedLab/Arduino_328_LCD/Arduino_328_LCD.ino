#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // sets the interfacing pins
int num = 0;
int bs1 = 0;
int bs2 = 0;
int bs3 = 0;
int bs4 = 0;
int lbs1 = 0;
int lbs2 = 0;
int lbs3 = 0;
int lbs4 = 0;
void setup()
{
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lcd.begin(16, 2);  // initializes the 16x2 LCD
}

void loop()
{
  //delay(20);
  lcd.setCursor(0, 0);          //sets the cursor at row 0 column 0
  lcd.print("COUNTER Program"); // prints 16x2 LCD MODULE
  lcd.setCursor(2, 1); //sets the cursor at row 1 column 2
  bs1 = digitalRead(8);
  bs2 = digitalRead(9);
  bs3 = digitalRead(0);
  bs4 = digitalRead(1);
  if (bs1 != lbs1 && bs1 == HIGH)
  {
    num = num + 1;
    lcd.setCursor(2, 1);
    lcd.print(num);   // prints HELLO WORLD
  }
  if (bs2 != lbs2 && bs2 == HIGH)
  {
    num = num + 10;
    lcd.setCursor(2, 1);
    lcd.print(num);     // prints HELLO WORLD
  }
  if (bs3 != lbs3 && bs3 == HIGH)
  {
    int numc = num;
    int count =millis();
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("COUNTER RUNNING>>>>>");
    lcd.setCursor(2, 1);
    lcd.print(num);
    while (numc >0)
    {
      if((millis()-count)>999){
   lcd.setCursor(2, 1);
   lcd.print("       ");
   count = millis();
   numc = numc - 1;
   lcd.setCursor(2, 1);
   lcd.print(numc);
   //delay(1000); 
      }
      lbs4 = bs4;
      bs4=digitalRead(1);
      if(bs4==HIGH && lbs4!=bs4)
   break;
    }
    lcd.setCursor(2, 1);
    lcd.print("       ");
    num=0;
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("RESET");
    lcd.setCursor(2, 1);
    lcd.print(num);
    delay(1000);
  }
  lbs1 = bs1;
  lbs2 = bs2;
  lbs3 = bs3;
  lbs4 = bs4;

}
//8,9 pin
