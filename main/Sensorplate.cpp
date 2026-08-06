#include "Sensorplate.h"
#include <Arduino.h>

#define SIR1 A0
#define SIR2 A1
#define SIR3 A2
#define SIR4 A3
 enum Cor {vermelho, prata, verde};
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

int SeeGreen() {
  float SeLDR1 = 0;
  float SeLDR2 = 0;
  int THRESHOLD_1 = 220;
  int THRESHOLD_2 = 150;
  for(int i = 0; i < 3; i++) {
    GreenL();
    int this_try1 = analogRead(LDR1);
    int this_try2 = analogRead(LDR2);
    SeLDR1 = SeLDR1 + this_try1;
    SeLDR2 = SeLDR2 + this_try2;
    delay(200);
    NoLight();
    delay(100);
      Serial.print(SeLDR1);
  Serial.print(" ");
  Serial.print(SeLDR2);
  Serial.print("\n");
  }
  NoLight();
  SeLDR1 = SeLDR1 / 3;
  SeLDR2 = SeLDR2 / 3;
  if (SeLDR1 < THRESHOLD_1 && SeLDR2 < THRESHOLD_2)
    return 0;
  else if (SeLDR1 >= THRESHOLD_1 && SeLDR2 < THRESHOLD_2)
    return 1;
  else if (SeLDR1 < THRESHOLD_1 && SeLDR2 >= THRESHOLD_2)
    return 2;
  else if (SeLDR1 >= THRESHOLD_1 && SeLDR2 >= THRESHOLD_2)
    return 3;
  else
    return 4;
}

void GreenTest() {
  int green_pos = SeeGreen();
  switch(green_pos) {
    case 0:
      digitalWrite(LED_R1, HIGH);
      digitalWrite(LED_R2, HIGH);
      break;
    case 1:
      digitalWrite(LED_R1, LOW);
      digitalWrite(LED_R2, HIGH);
      break;
    case 2:
      digitalWrite(LED_R1, HIGH);
      digitalWrite(LED_R2, LOW);
      break;
    case 3:
      digitalWrite(LED_R1, LOW);
      digitalWrite(LED_R2, LOW);
      break;
    case 4:
      digitalWrite(LED_B1, LOW);
      digitalWrite(LED_B2, LOW);
      break;
  }
  delay(1000);
}
