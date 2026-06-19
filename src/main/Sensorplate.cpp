#include "Sensorplate.h"
#include <Arduino.h>

#define SIR1 A0
#define SIR2 A1
#define SIR3 A2
#define SIR4 A3
 
#define LDR1 A15
#define LDR2 A14
#define LED_B1 52
#define LED_B2 51
#define LED_G1 53
#define LED_G2 48
#define LED_R1 50
#define LED_R2 49

int IR1()
{
  return analogRead(SIR1);
}

int IR2()
{
  return analogRead(SIR2);
}

int IR3()
{
  return analogRead(SIR3);
}

int IR4()
{
  return analogRead(SIR4);
}