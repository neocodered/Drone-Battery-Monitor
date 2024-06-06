void motor_stop(){
  ledcWrite(0, 0);
  ledcWrite(1, 0);
  ledcWrite(2, 0);
  ledcWrite(3, 0);
}

void motor_setup(){
  const int m4 = 0;
  const int m3 = 5;
  const int m2 = 10;
  const int m1 = 18;
  const int freq = 1000;
  const int resolution = 10;
  ledcSetup(0, freq, resolution);
  ledcSetup(1, freq, resolution);
  ledcSetup(2, freq, resolution);
  ledcSetup(3, freq, resolution);
  ledcAttachPin(m1, 0);
  ledcAttachPin(m2, 1);
  ledcAttachPin(m3, 2);
  ledcAttachPin(m4, 3);
  motor_stop();
  delay(10);
}


void motor_slow(){
  ledcWrite(0, 50);
  ledcWrite(1, 50);
  ledcWrite(2, 50);
  ledcWrite(3, 50);
}

void motor_start_sequence(){
  for (int i = 0; i<3; i++){
    motor_slow();
    delay(50);
    motor_stop();
    delay(500);
  }
}

void motor_speed(int speed_m1, int speed_m2, int speed_m3, int speed_m4){
  //Speed varies between 0 to pow(2,resolution) - 1
  //That means 0 to 1023
  ledcWrite(0, speed_m1);
  ledcWrite(1, speed_m2);
  ledcWrite(2, speed_m3);
  ledcWrite(3, speed_m4);
}