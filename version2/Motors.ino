void motordefine() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}
void motorhiz(int solhiz, int saghiz) {
  if (solhiz > 0) {
    digitalWrite(M1, HIGH);

  }
  else {
    digitalWrite(M1, LOW);

  }
  if (saghiz > 0) {
    digitalWrite(M2, HIGH);

  }
  else {
    digitalWrite(M2, LOW);
  }
  analogWrite(E1, solhiz);   //PWM Speed Control
  analogWrite(E2, saghiz);   //PWM Speed Control

}

void stopMotors() {
  motorhiz(-ilkmotorsolhiz, -ilkmotorsaghiz);
  delay(20);
  motorhiz(0, 0);
}
void stopMotorsToBack() {
  motorhiz(ilkmotorsolhiz, ilkmotorsaghiz);
  delay(30);
  motorhiz(0, 0);
}



void turnLeft() {
  motorhiz(-50, 50);
  delay(400);
  while (1) {
    qtrread();
    if (sensorvalues[3] == 0) {
      if(sensorvalues[2] == 0)
      break;
    }
  }
  motorhiz(50, -50);
  delay(50);
  motorhiz(0, 0);
}

void turnRight() {
  motorhiz(50, -50);
  delay(400);
  while (1) {
    qtrread();
    if(sensorvalues[2] == 0) {
       if(sensorvalues[3] == 0)
      break;
    }
  }
  motorhiz(-50, 50);
  delay(50);
  motorhiz(0, 0);
}
