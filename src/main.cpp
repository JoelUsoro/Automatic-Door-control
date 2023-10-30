#include <Arduino.h>
#include <Servo.h> 
Servo s1;
int val = 0 ;
void setup()
{
    Serial.begin(9600); // sensor buart rate
    s1.attach(3);
    pinMode(13,INPUT);   
    pinMode(12,OUTPUT);  // led green pin
    pinMode(11,OUTPUT);  // led red pin
}
void loop() 
{
  val = digitalRead(13);  // IR sensor output pin connected
  Serial.println(val);   // see the value in serial mpnitor in Arduino IDE
  delay(1);
  
  if(val == 1 )
  {
    digitalWrite(12,HIGH);  // LED ON
    digitalWrite(11,LOW);   // LED OFF
    s1.write(90);
    delay(2000);
  
  }
  else
  {
    digitalWrite(12,LOW);   // LED OFF
    digitalWrite(11,HIGH);  // LED ON
    s1.write(0);
   
  }
  }