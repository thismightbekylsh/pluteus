#include "Sensorplate.h"
#include "Motor.h"
#include "Led.h"
#include <Arduino.h>

#define SIR1 A0
#define SIR2 A1
#define SIR3 A2
#define SIR4 A3
 
#define LDR1 A4
#define LDR2 A5

const int THRESHOLD = 450;

bool LineTest()
{
  Go(100,100,100,100);
  delay(500);
  Stop();

  if(analogRead(SIR1) >= THRESHOLD || analogRead(SIR2) >= THRESHOLD || analogRead(SIR3) >= THRESHOLD || analogRead(SIR4) >= THRESHOLD)
  {
    Back(90,90,90,90);
    delay(400);
    Stop();
    return true;
  }

  else
  {
    Back(90,90,90,90);
    delay(400);
    Stop();
  }

  return false;
}

void Turn90(char dir, int d)
{
  Stop();
  delay(500);

  Go(90,90,90,90);
  delay(d);

  Stop();
  delay(200);

  int SeIR2;
  int SeIR3;

  while(true)
  {
    if(dir == 'l') Left(90,90,90,90);
    else if(dir == 'r') Right(90,90,90,90);

    SeIR2 = analogRead(SIR2);
    SeIR3 = analogRead(SIR3);

    if(SeIR2 >= THRESHOLD || SeIR3 >= THRESHOLD) break;
  }
}

void Turn180()
{
  Right(100,100,100,100);
  delay(1000);

  int SeIR3;

  while(true)
  {
    SeIR3 = analogRead(SIR3);

    if(SeIR3 > THRESHOLD) break;
  }
}

void SeguirLinha()
{
  NoLight();

  int SeIR1 = analogRead(SIR1);
  int SeIR2 = analogRead(SIR2);
  int SeIR3 = analogRead(SIR3);
  int SeIR4 = analogRead(SIR4);

  /*if(SeIR1 >= THRESHOLD && SeIR2 >= THRESHOLD)
  {
    Turn90('l', 300);
  }
  else if(SeIR3 >= THRESHOLD && SeIR4 >= THRESHOLD)
  {
    Turn90('r', 300);
  }
  else*/if(SeIR2 >= THRESHOLD)
  {
    Left(105,150,105,135);
  }
  else if (SeIR3 >= THRESHOLD)
  {
   Right(135,120,135,105);
   }
  else if (SeIR4 >= THRESHOLD)
  {
   Right(135,120,135,105); 
  }
  else if (SeIR1 >= THRESHOLD)
  {
    Left(105,150,105,135);
  }
  else {
    Go(90,120,90,90);
  }
}