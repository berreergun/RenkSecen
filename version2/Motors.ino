
void motorhiz(int solhiz, int saghiz) {
  if (solhiz > 0) {
    motorsol.run(FORWARD);
  }
  else {
    motorsol.run(BACKWARD);

  }
  if (saghiz > 0) {
    motorsag.run(FORWARD);

  }
  else {
    motorsag.run(BACKWARD);
  }
  motorsol.setSpeed(abs(solhiz));
  motorsag.setSpeed(abs(saghiz));

}

void stopMotors() {
  motorhiz(-ilkmotorsolhiz,-ilkmotorsaghiz);
  delay(50);
  motorhiz(0,0);
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
