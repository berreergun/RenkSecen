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
      if (sensorvalues[2] == 0)
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
    if (sensorvalues[2] == 0) {
      if (sensorvalues[3] == 0)
        break;
    }
  }
  motorhiz(-50, 50);
  delay(50);
  motorhiz(0, 0);
}

void goStep(int blockNumber , int directionn) {
  if (directionn == RIGHT) {
    digitalWrite(dirPin, HIGH);
    currentBlock = (currentBlock - blockNumber) % 8;
  }
  else if (directionn == LEFT) {
    digitalWrite(dirPin, LOW);
    currentBlock += blockNumber;
  }

  for (int x = 0; x < 25 * blockNumber; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(3500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(3500);
  }
  delay(1000); //ayarlanabilir kısım
}

void findBlock() {
  int currentRoom = renkbul();
  int roundNumber = currentBlock - currentRoom;
  if (roundNumber < -4) goStep(roundNumber + 8, RIGHT);
  else if (roundNumber > 4) goStep(roundNumber - 8, LEFT);
  else{
    if(roundNumber>0) goStep(roundNumber,RIGHT);
    else if(roundNumber<0) goStep(roundNumber,LEFT);
  }
}
