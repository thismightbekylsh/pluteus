#include "Motor.h"

void Go(int speed)
{
  analogWrite(ENA_F, speed);
  analogWrite(ENB_F, speed);
  analogWrite(ENA_B, speed);
  analogWrite(ENB_B, speed);

  digitalWrite(IN1_F, LOW);
  digitalWrite(IN2_F, HIGH);
  digitalWrite(IN3_F, LOW);
  digitalWrite(IN4_F, HIGH);

  digitalWrite(IN1_B, HIGH);
  digitalWrite(IN2_B, LOW);
  digitalWrite(IN3_B, HIGH);
  digitalWrite(IN4_B, LOW);
}

void Back(int speed)
{
  analogWrite(ENA_F, speed);
  analogWrite(ENB_F, speed);
  analogWrite(ENA_B, speed);
  analogWrite(ENB_B, speed);

  digitalWrite(IN1_F, HIGH);
  digitalWrite(IN2_F, LOW);
  digitalWrite(IN3_F, HIGH);
  digitalWrite(IN4_F, LOW);

  digitalWrite(IN1_B, LOW);
  digitalWrite(IN2_B, HIGH);
  digitalWrite(IN3_B, LOW);
  digitalWrite(IN4_B, HIGH);
}

void Right(int speed)
{
  analogWrite(ENA_F, speed);
  analogWrite(ENB_F, speed);
  analogWrite(ENA_B, speed);
  analogWrite(ENB_B, speed);

  digitalWrite(IN1_F, LOW);
  digitalWrite(IN2_F, HIGH);
  digitalWrite(IN3_F, HIGH);
  digitalWrite(IN4_F, LOW);

  digitalWrite(IN1_B, HIGH);
  digitalWrite(IN2_B, LOW);
  digitalWrite(IN3_B, LOW);
  digitalWrite(IN4_B, HIGH);
}

void Left(int speed)
{
  analogWrite(ENA_F, speed);
  analogWrite(ENB_F, speed);
  analogWrite(ENA_B, speed);
  analogWrite(ENB_B, speed);

  digitalWrite(IN1_F, HIGH);
  digitalWrite(IN2_F, LOW);
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