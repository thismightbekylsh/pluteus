#include "Motor.h"

#define ENA_F 2
#define ENB_F 3
#define ENA_B 4
#define ENB_B 5

#define IN1_F 22
#define IN2_F 23
#define IN3_F 24
#define IN4_F 25

#define IN1_B 26
#define IN2_B 27
#define IN3_B 28
#define IN4_B 29

#define IR1 A0
#define IR2 A1
#define IR3 A2
#define IR4 A3
 
 #define LDR1 A15
 #define LDR2 A14

 #define LED_B1 52
 #define LED_B2 51
 #define LED_G1 53
 #define LED_G2 48
 #define LED_R1 50
 #define LED_R2 49

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

  Serial.begin(9600);
}

void loop() {
  
  
}



