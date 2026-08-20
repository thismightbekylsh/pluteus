#include "Motor.h"
#include "Sensorplate.h"
#include "Path.h"
#include "Led.h"

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

#define SIR1 A0
#define SIR2 A1
#define SIR3 A2
#define SIR4 A3
 
#define LDR1 A4
#define LDR2 A5

#define LED_B1 36
#define LED_B2 37

#define LED_G1 38
#define LED_G2 35

#define LED_R1 34
#define LED_R2 39

float THRESHOLD_W_LDR1;
float THRESHOLD_W_LDR2;

void setup() {
  // put your setup code here, to run once:
  pinMode(ENA_F, OUTPUT);
  pinMode(ENB_F, OUTPUT);
  pinMode(ENA_B, OUTPUT);
  pinMode(ENB_B, OUTPUT);

  pinMode(IN1_F, OUTPUT);
  pinMode(IN2_F, OUTPUT);
  pinMode(IN3_F, OUTPUT);
  pinMode(IN4_F, OUTPUT);

  pinMode(IN1_B, OUTPUT);
  pinMode(IN2_B, OUTPUT);
  pinMode(IN3_B, OUTPUT);
  pinMode(IN4_B, OUTPUT);
  
  pinMode(LED_B1, OUTPUT);
  pinMode(LED_B2, OUTPUT);
  pinMode(LED_G1, OUTPUT);
  pinMode(LED_G2, OUTPUT);
  pinMode(LED_R1, OUTPUT);
  pinMode(LED_R2, OUTPUT);

  THRESHOLD_W_LDR1 = WhiteValue(LDR1);
  THRESHOLD_W_LDR2 = WhiteValue(LDR2);
  THRESHOLD_W_LDR1 += 100;
  THRESHOLD_W_LDR2 += 60;

  Serial.begin(9600);
}

const int THRESHOLD = 450;

void loop() {
 SeguirLinha();
}