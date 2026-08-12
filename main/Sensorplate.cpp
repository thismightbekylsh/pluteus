#include "Sensorplate.h"
#include <Arduino.h>

#define SIR1 A0
#define SIR2 A1
#define SIR3 A2
#define SIR4 A3
 
#define LDR1 A4
#define LDR2 A5

void SensorsCheck()
{
  Serial.print("IR1: | ");
  Serial.print(analogRead(SIR1));
  Serial.print(" | IR2: | ");
  Serial.print(analogRead(SIR2));
  Serial.print(" | IR3: | ");
  Serial.print(analogRead(SIR3));
  Serial.print(" | IR4: | ");
  Serial.print(analogRead(SIR4));
  Serial.print(" | LDR1: | ");
  Serial.print(analogRead(LDR1));
  Serial.print(" | LDR2: | ");
  Serial.println(analogRead(LDR2));
}

