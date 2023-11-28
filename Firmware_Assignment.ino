#include<stdint.h>

long count = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  int x = analogRead(A0);

  if (x < 30)
  {
   count++;
   if(count == 100000){
     digitalWrite(LED_BUILTIN,HIGH);
   }
   else if(count == 200000){
     count = 0;
     digitalWrite(LED_BUILTIN,LOW);
   }
  }
  else 
  {
   count++;
   if(count == 200000){
     digitalWrite(LED_BUILTIN,HIGH);
   }
   else if(count == 400000){
     count = 0;
     digitalWrite(LED_BUILTIN,LOW);
   }
  }
}
