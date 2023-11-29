#include<stdint.h>

#define Threshold_temperatue 30                       //defining threshold temperature value as 30°C 

long count = 0;                                       //defining a count variabe for counting

void setup()
{
  pinMode(A0, INPUT);                                 //Set A0 pin as INPUT
  pinMode(LED_BUILTIN, OUTPUT);                       //Set Built-in LED pin as OUTPUT
}

void loop()
{
  int data = analogRead(A0);                          //Read the temperature data from analog pin A0
  float voltage = (data / 1023.0) * 5.0;              // Convert analog value to voltage (0 to 5V)
  float temperatureCelsius = (voltage - 0.5) * 100.0; // Convert voltage to degrees Celsius using LM35 formula
  
  //////////////Conditional loop/////////////////
  if (temperatureCelsius < Threshold_temperature)     //Check the temperatureCelsius < threshold value
  {
    /////////// BLINK LED with a delay of 250ms if temperature < 30 //////////
    digitalWrite(LED_BUILTIN, HIGH);                  // Turn LED ON by writing HIGH (Sending 5v to pin 13)
    delay_ms(250);                                    //Delay of 500 milliseconds
    digitalWrite(LED_BUILTIN, LOW);                   //Turn OFF LED by writing LOW
    delay_ms(250);                                    //Delay of 500 milliseconds
  }
  else 
  {
   /////////// BLINK LED with a delay of 500ms if temperature > 30 //////////
   digitalWrite(LED_BUILTIN, HIGH);                   // Turn LED ON by writing HIGH (Sending 5v to pin 13)
    delay_ms(500);                                    //Delay of 500 milliseconds
    digitalWrite(LED_BUILTIN, LOW);                   //Turn OFF LED by writing LOW
    delay_ms(500);   //Delay of 500 milliseconds
   }
  }
}

/////////////////Delay Function in milliseconds////////////////

void delay_ms(unsigned long ms)                      //Function for delay in milliseconds 
{
    for (unsigned long i = 0; i < ms; i++) {
        for (volatile uint32_t j = 0; j < 400; j++); // loop to generate 1 millisecond delay
    }
}
