#include "Motor.h"
#include <Arduino.h>

#define ENA_F 2
#define ENB_F 3
#define ENA_B 4
#define ENB_B 5

#define IN1_B 22
#define IN2_B 23
#define IN3_B 24
#define IN4_B 25

#define IN1_F 26
#define IN2_F 27
#define IN3_F 28
#define IN4_F 29

void Go(int sp1, int sp2, int sp3, int sp4)
{
  analogWrite(ENA_F, sp1);
  analogWrite(ENB_F, sp2);
  analogWrite(ENA_B, sp3);
  analogWrite(ENB_B, sp4);

  digitalWrite(IN1_F, HIGH); 
  digitalWrite(IN2_F, LOW);
  digitalWrite(IN3_F, LOW);
  digitalWrite(IN4_F, HIGH);

  digitalWrite(IN1_B, LOW); // XX Xx
  digitalWrite(IN2_B, HIGH); // XX Xx
  digitalWrite(IN3_B, LOW); // XX xX
  digitalWrite(IN4_B, HIGH); // XX xX
}

void Back(int sp1, int sp2, int sp3, int sp4)
{
  analogWrite(ENA_F, sp1);
  analogWrite(ENB_F, sp2);
  analogWrite(ENA_B, sp3);
  analogWrite(ENB_B, sp4);

  digitalWrite(IN1_F, LOW);
  digitalWrite(IN2_F, HIGH);
  digitalWrite(IN3_F, HIGH);
  digitalWrite(IN4_F, LOW);

  digitalWrite(IN1_B, HIGH);
  digitalWrite(IN2_B, LOW);
  digitalWrite(IN3_B, HIGH);
  digitalWrite(IN4_B, LOW);
}

void Right(int sp1, int sp2, int sp3, int sp4)
{
  analogWrite(ENA_F, sp1);
  analogWrite(ENB_F, sp2);
  analogWrite(ENA_B, sp3);
  analogWrite(ENB_B, sp4);

  digitalWrite(IN1_F, HIGH);
  digitalWrite(IN2_F, LOW);
  digitalWrite(IN3_F, HIGH);
  digitalWrite(IN4_F, LOW);

  digitalWrite(IN1_B, HIGH);
  digitalWrite(IN2_B, LOW);
  digitalWrite(IN3_B, LOW);
  digitalWrite(IN4_B, HIGH);
}

void Left(int sp1, int sp2, int sp3, int sp4)
{
  analogWrite(ENA_F, sp1);
  analogWrite(ENB_F, sp2);
  analogWrite(ENA_B, sp3);
  analogWrite(ENB_B, sp4);

  digitalWrite(IN1_F, LOW);
  digitalWrite(IN2_F, HIGH);
  digitalWrite(IN3_F, LOW);
  digitalWrite(IN4_F, HIGH);

  digitalWrite(IN1_B, LOW);
  digitalWrite(IN2_B, HIGH);
  digitalWrite(IN3_B, HIGH);
  digitalWrite(IN4_B, LOW);
}

void Stop()
{
  analogWrite(ENA_F, 0);
  analogWrite(ENB_F, 0);
  analogWrite(ENA_B, 0);
  analogWrite(ENB_B, 0);

  digitalWrite(IN1_F, LOW);
  digitalWrite(IN2_F, LOW);
  digitalWrite(IN3_F, LOW);
  digitalWrite(IN4_F, LOW);

  digitalWrite(IN1_B, LOW);
  digitalWrite(IN2_B, LOW);
  digitalWrite(IN3_B, LOW);
  digitalWrite(IN4_B, LOW);
}