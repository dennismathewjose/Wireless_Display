#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd (4, 5, 6, 7, 8, 9);
SoftwareSerial mySerial (2, 3);   //(RX, TX);

String val = "Hello";
String oldval;
String newval ="Hello";
int i = 0;
int len=0;

void setup() 
{
  // put your setup code here, to run once:
  lcd.begin(20,4);
  mySerial.begin(9600);
  //Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Wireless Display");
  lcd.setCursor(0, 1);
  lcd.print("Using Bluetooth");
  delay(3000);
  lcd.clear();
  lcd.print("Welcome!");
}

void loop() 
{
  val = mySerial.readString();
  val.trim();
  Serial.println(val);
  if(val != oldval)
  {
    newval = val;
  }
  lcd.clear();
  len=newval.length();
  if (len>40){
    lcd.print("Out of Bounds");
    }
    else{
  lcd.setCursor(i, 0);
  lcd.print(newval);
  
  i++;
 
  if(+len >= 20 )
  {
    i = 0;
  }
  val = oldval;
}
}
