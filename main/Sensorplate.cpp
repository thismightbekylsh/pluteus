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

float WhiteValue(int sensor)
{
  GreenL();
  float white = 0;

  for(int i = 0; i < 3; i++)
  {
    white += analogRead(sensor);
  }

  white /= 3;

  NoLight();
  return white;
}

int GreenTest(float THRESHOLD1, float THRESHOLD2)
{
  float green1 = 0;
  float green2 = 0;

  for(int i = 0; i < 3; i++)
  {
    GreenL();
    delay(200);
    green1 += analogRead(LDR1);
    green2 += analogRead(LDR2);
    delay(200);
    NoLight();
    delay(200);
  }

  NoLight();

  if(green1 >= THRESHOLD1 && green2 < THRESHOLD2) return 1;
  else if(green1 < THRESHOLD1 && green2 >= THRESHOLD2) return 2;
  else if(green1 >= THRESHOLD1 && green2 >= THRESHOLD2) return 3;
  else return 4;
}