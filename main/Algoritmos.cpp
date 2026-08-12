/*#include "Sensorplate.h"
#include "Motor.h"
#include <Arduino.h>

void SeguirLinha()
{
  NoLight();

  int SeIR1 = analogRead(SIR1);
  int SeIR2 = analogRead(SIR2);
  int SeIR3 = analogRead(SIR3);
  int SeIR4 = analogRead(SIR4);

  const int THRESHOLD = 450;

  if(SeIR1 >= THRESHOLD && SeIR2 >= THRESHOLD && SeIR3 != THRESHOLD && SeIR4 != THRESHOLD)
  {
    Stop();
    delay(500);
    Left(110,100,110,100);
    delay(600);
    Go(50,50,50,50);
    delay(600);
  }
  else if(SeIR4 >= THRESHOLD && SeIR3 >= THRESHOLD && SeIR1 != THRESHOLD && SeIR2 != THRESHOLD)
  {
    Stop();
    delay(500);
    Right(100,110,100,110);
    delay(600);
    Go(50,50,50,50);
    delay(600);
  }
  else if (Tspeed % 10 == 0)
  {
    Stop();
    Tspeed = 1;
  }
  else if(SeIR2 >= THRESHOLD)
  {
    Left(110,70,110,70);
    Tspeed++;
  }
  else if (SeIR3 >= THRESHOLD)
  {
    Right(70,110,70,110);
    Tspeed++;
  }
  else if (SeIR4 >= THRESHOLD)
  {
    Right(70,110,70,110);
    Tspeed++;
  }
  else if (SeIR1 >= THRESHOLD)
  {
    Left(120,70,120,70);
    Tspeed++;
  }
  else {
    Go(70,70,70,70); //talvez aumentar a velocidade para que ele não fique parando
    Tspeed++;
  }
} */