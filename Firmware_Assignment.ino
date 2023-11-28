#include<stdint.h>

long count = 0;                       //defining a count variabe for counting

void setup()
{
  pinMode(A0, INPUT);                 //Set A0 pin as INPUT
  pinMode(LED_BUILTIN, OUTPUT);       //Set Built-in LED pin as OUTPUT
}

void loop()
{
  int x = analogRead(A0);             //Read the temperature data from analog pin A0

  if (x < 30)                         //Check the data < threshold value(30 degree celcius)
  {
   /////////// BLINK LED with a delay of 250ms if temperature < 30 //////////
   count++;                           //Increment Count by 1
   if(count == 100000){               //Check if count value reaches to 100000
     digitalWrite(LED_BUILTIN,HIGH);  //Turn LED ON by writing HIGH
   }
   else if(count == 200000){          //Check if count value reaches to 200000
     count = 0;                       //Reset Count to 0
     digitalWrite(LED_BUILTIN,LOW);   //Turn OFF LED by writing LOW
   }
  }
  else 
  {
   /////////// BLINK LED with a delay of 500ms if temperature > 30 //////////
   count++;                           //Increment Count by 1
   if(count == 200000){               //Check if count value reaches to 200000
     digitalWrite(LED_BUILTIN,HIGH);  //Turn LED ON by writing HIGH
   }
   else if(count == 400000){           //Check if count value reaches to 400000
     count = 0;                        //Reset Count to 0
     digitalWrite(LED_BUILTIN,LOW);    //Turn OFF LED by writing LOW
   }
  }
}
