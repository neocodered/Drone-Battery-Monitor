#include "motor.h" // Include the motor control functions

float run_voltage;
float stop_voltage;

float voltage(int x){
  return -0.048 + 0.00315*x + 0.01;
}

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud rate
  motor_setup();      // Setup the motor
}

void loop() {

  if (voltage(analogRead(1)) > 3.7){
    for (int k = 0; k<1000; k += 50){
      motor_speed(k, k, k, k);
      delay(1000);
      run_voltage = voltage(analogRead(1));
      motor_stop();
      delay(1000);
      if (k==0){
        stop_voltage = voltage(analogRead(1));
      }
      Serial.print(k);
      Serial.print(",");
      Serial.print(run_voltage);
      Serial.print(",");
      Serial.println(stop_voltage);
    }
    for (int k = 1000; k>0; k -= 50){
      motor_speed(k, k, k, k);
      delay(1000);
      run_voltage = voltage(analogRead(1));
      motor_stop();
      delay(1000);
      if (k==0){
        stop_voltage = voltage(analogRead(1));
      }
      Serial.print(k);
      Serial.print(",");
      Serial.print(run_voltage);
      Serial.print(",");
      Serial.println(stop_voltage);
    }
  }
  else{
    motor_stop();
  }

  motor_speed(200, 0, 0, 0);
  Serial.println(voltage(analogRead(1)));
  delay(5000);
  motor_stop()
  delay(5000)
  motor_speed(200, 200, 0, 0);
  delay(5000);
  motor_stop()
  delay(5000)
}


