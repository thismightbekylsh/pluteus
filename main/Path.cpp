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

void Turn90(char dir, int d, int THRESHOLD)
{
  Back(90,90,90,90);
  delay(d);

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

void Turn180(int THRESHOLD)
{
  Right(100,100,100,100);
  delay(1000);

  int SeIR3;

  
  while(true)
  {
    if(analogRead(SIR3) > THRESHOLD) break;
  }
}

void SeguirLinha()
{
  NoLight();

  int SeIR1 = analogRead(SIR1);
  int SeIR2 = analogRead(SIR2);
  int SeIR3 = analogRead(SIR3);
  int SeIR4 = analogRead(SIR4);

  const int THRESHOLD = 450;

  if(SeIR2 >= THRESHOLD)
  {
    Left(110,70,110,70);
  }
  else if (SeIR3 >= THRESHOLD)
  {
    Right(70,110,70,110);
  }
  else if (SeIR4 >= THRESHOLD)
  {
    Right(70,110,70,110);
  }
  else if (SeIR1 >= THRESHOLD)
  {
    Left(120,70,120,70);
  }
  else {
    Go(70,70,70,70);
  }
}