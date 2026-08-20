#include <Arduino.h>

#define LDR1 A4
#define LDR2 A5

#define LED_B1 36
#define LED_B2 37

#define LED_G1 38
#define LED_G2 34

#define LED_R1 35
#define LED_R2 39

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