#include "Sensorplate.h"
#include <Arduino.h>

#define SIR1 A0
#define SIR2 A1
#define SIR3 A2
#define SIR4 A3
 
#define LDR1 A4
#define LDR2 A5

#define LED_R1 34
#define LED_G2 37
#define LED_B1 35
#define LED_B2 38
#define LED_G1 36
#define LED_R2 39

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

void GreenL()
{
  digitalWrite(LED_G1, LOW);
  digitalWrite(LED_G2, LOW);

  digitalWrite(LED_B1, HIGH);
  digitalWrite(LED_B2, HIGH);
  digitalWrite(LED_R1, HIGH);
  digitalWrite(LED_R2, HIGH);
}

void RedL()
{
  digitalWrite(LED_R1, LOW);
  digitalWrite(LED_R2, LOW);

  digitalWrite(LED_B1, HIGH);
  digitalWrite(LED_B2, HIGH);
  digitalWrite(LED_G1, HIGH);
  digitalWrite(LED_G2, HIGH);
}

void BlueL()
{
  digitalWrite(LED_B1, LOW);
  digitalWrite(LED_B2, LOW);

  digitalWrite(LED_G1, HIGH);
  digitalWrite(LED_G2, HIGH);
  digitalWrite(LED_R1, HIGH);
  digitalWrite(LED_R2, HIGH);
}

void NoLight()
{
  digitalWrite(LED_B1, HIGH);
  digitalWrite(LED_B2, HIGH);
  digitalWrite(LED_G1, HIGH);
  digitalWrite(LED_G2, HIGH);
  digitalWrite(LED_R1, HIGH);
  digitalWrite(LED_R2, HIGH);
}

int isGreen()
{
  Stop();
  int ldr1 = analogRead(LDR1);
  int ldr2 = analogRead(LDR2);

  GreenL();
  delay(200);

  if(ldr1 < 120 && ldr2 < 120)
  {
    return 1;
  }
  else if(ldr1 < 120 && ldr2 >= 120)
  {
    return 2;
  }
  else if(ldr1 >= 120 && ldr2 < 120)
  {
    return 3;
  }
  return 4;
}

int isRed()
{
  Stop();
  int ldr1 = analogRead(LDR1);
  int ldr2 = analogRead(LDR2);

  RedL();
  delay(200);

  if(ldr1 < 120 && ldr2 < 120)
  {
    return 1;
  }
  else if(ldr1 < 120 && ldr2 >= 120)
  {
    return 2;
  }
  else if(ldr1 >= 120 && ldr2 < 120)
  {
    return 3;
  }
  return 4;
}

int isBlue()
{
  Stop();
  int ldr1 = analogRead(LDR1);
  int ldr2 = analogRead(LDR2);

  BlueL();
  delay(200);

  if(ldr1 < 120 && ldr2 < 120)
  {
    return 1;
  }
  else if(ldr1 < 120 && ldr2 >= 120)
  {
    return 2;
  }
  else if(ldr1 >= 120 && ldr2 < 120)
  {
    return 3;
  }
  return 4;
}