#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
#define AGV1 7
#define AGV2 8
#define AGV3 9
void UpdateStatus()
{
  int n = Serial.available();
    int j;
   byte data[n];
    for(j=0;j<n;j++)
   {
      data[j]=Serial.read();
   }
 
         if(digitalRead(AGV1)==LOW && digitalRead(AGV2)==LOW&& digitalRead(AGV3)==LOW)
         Serial.print('0');
         if(digitalRead(AGV1)==LOW && digitalRead(AGV2)==LOW&& digitalRead(AGV3)==HIGH)
         Serial.print('1');
         if(digitalRead(AGV1)==LOW && digitalRead(AGV2)==HIGH&& digitalRead(AGV3)==LOW)
         Serial.print('2');
         if(digitalRead(AGV1)==LOW && digitalRead(AGV2)==HIGH&& digitalRead(AGV3)==HIGH)
         Serial.print('3');
         if(digitalRead(AGV1)==HIGH && digitalRead(AGV2)==LOW&& digitalRead(AGV3)==LOW)
         Serial.print('4');
         if(digitalRead(AGV1)==HIGH && digitalRead(AGV2)==LOW&& digitalRead(AGV3)==HIGH)
         Serial.print('5');
         if(digitalRead(AGV1)==HIGH&& digitalRead(AGV2)==HIGH&& digitalRead(AGV3)==LOW)
         Serial.print('6');
         if(digitalRead(AGV1)==HIGH && digitalRead(AGV2)==HIGH&& digitalRead(AGV3)==HIGH)
         Serial.print('7');       
}


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(13,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  Serial.begin(9600);
  lcd.print("Hello");

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH);
  delay(500);
  digitalWrite(13,LOW);
  delay(500);
//  for(i=0;i<16;i++)
//  {
//   // lcd.setCursor(i,1);
//    lcd.print(j,BIN);
//    j++;
//    delay(1000);
//    lcd.clear();
//  }
//  if(Serial.available())
//  {
//    byte c = Serial.read();
//    lcd.print("??");
//  }
delay(1000);
   int length1 ;
   if(Serial.available())
   {
       int n = Serial.available();
       length1 = n;
       byte data[n];
       int count;
       for(count=0;count<n;count++)
       {
        data[count] = Serial.read();
        delay(50);
       }
       if(n==1)
       {
          UpdateStatus();
          continue;
       }
       int count1 ;
   for(count1 = 0 ;count1 < length1 ; count1 ++)
   {
    lcd.clear();
   // while(digitalRead(8) == LOW)
  //  {}
    //lcd.print(data[count1],DEC);
    if(count1==length1-1)
    delay(2000);
    switch (data[count1])
    {
      //case 0x0" : lcd.print("??"); break;
      case 0x04 : lcd.print("Turn Right"); break;
      case 0x05 : lcd.print("Turn Left"); break;
      case 0x06 : lcd.print("Go Straight"); break;
      case 0x07 : lcd.print("Hold On"); break;
      case 0x08 : lcd.print("Get Stuff"); break;
      case 0x09 : lcd.print("Ready");break;
      case 0xAA : lcd.print("Backward"); break;
      case 0x10 : lcd.print("Delivery");break;
    }
    delay(2000);
   }
    
   }
   

}
