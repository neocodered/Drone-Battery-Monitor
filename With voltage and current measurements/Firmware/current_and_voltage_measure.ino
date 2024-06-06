#include "motor.h"

float f_voltage;
float f_current;

float current;
float voltage;

float final_voltage;

bool start = true;

float bat_perc;

float prev_perc = 100;

void setup() {

  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  motor_setup();

  delay(1000);

  // const float in_current = analogRead(A0);
  float in_voltage = analogRead(A1);
  in_voltage = in_voltage*0.02438;

  int a = 0;
  while (true){
    motor_speed(50,50,50,50);

    current = analogRead(A0);
    voltage = analogRead(A1);

    voltage = voltage*0.02438;
    current = current*0.23441;

    f_voltage = 0.9937*f_voltage + 0.006263*voltage;
    f_current = 0.9937*f_current + 0.006263*current;

    a++;
    delay(10);

    if (a >= 1000){
      break;
    }
  }

  motor_speed(0,0,0,0);
  const float r = (in_voltage - f_voltage)/f_current;

  f_voltage = 0;
  f_current = 0;
}

void loop() {
  
  // Getting the values from the sensors
  current = analogRead(A0);
  voltage = analogRead(A1);

  // Adjusting the values by multiplying by relevant tuning coefficients
  voltage = voltage*0.02438;
  current = current*0.23441;

  // Filtering oout the readings
  f_voltage = 0.9937*f_voltage + 0.006263*voltage;
  f_current = 0.9937*f_current + 0.006263*current;

  Serial.print("Current:");
  Serial.print(f_current);
  Serial.print("mA ");
    
  Serial.print("Voltage:");
  Serial.print(f_voltage);
  Serial.println("v");

  final_voltage = f_voltage + f_current*r;

  bat_perc = (final_voltage - 3.7)*100/4.2;

  if (prev_perc < bat_perc){
    bat_perc = prev_perc;
  }

  prev_perc = bat_perc;

  if (bat_perc<0){
    Serial.println("Low_Power");
  }

  delay(50);
}

