#include "motor.h"

float x = 0;
float y = 0;
int a = 0;
float v_x = 0;
float v_y = 0;

float voltage(float x){
  // return -0.048 + 0.00315*x + 0.01;
  return 0.00488*x;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1,INPUT);
  motor_setup();
  motor_speed(200,0,0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = analogRead(A0);
  
  y = 0.9937*y + 0.006263*x; // differene equation to filter the voltage readings
  // a++;

  v_x = voltage(x);
  v_y = voltage(y);
  
  Serial.print(v_x);
  Serial.print(" ");
  Serial.println(v_y);
}
