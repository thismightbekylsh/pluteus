//sensorplate.h

#ifndef SENSORPLATE_H
#define SENSORPLATE_H

void SensorsCheck();
void GreenL();
void RedL();
void BlueL();
void NoLight();
float WhiteValue(int sensor);
int GreenTest(float THRESHOLD1, float THRESHOLD2);

#endif