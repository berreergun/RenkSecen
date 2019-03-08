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
  delay(10);
  motorhiz(0, 0);
}

void turnLeft() {
  motorhiz(-ilkmotorsolhiz, ilkmotorsaghiz);
  delay(400);
  while (1) {
    qtrread();
    if (sensorvalues[3] == 0)  break;
  }
  motorhiz(50, -50);
  delay(50);
  motorhiz(0, 0);
}

void turnRight() {
  motorhiz(ilkmotorsolhiz, -ilkmotorsaghiz);
  delay(400);
  while (1) {
    qtrread();
    if (sensorvalues[4] == 0)  break;
  }
  motorhiz(-50, 50);
  delay(50);
  motorhiz(0, 0);
}
