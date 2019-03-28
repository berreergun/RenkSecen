void motordefine() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);


   ///Servo Define
   servoBuyuk.attach(9);
  servoKucuk.attach(8);
  
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
  motorhiz(-50, 65);
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
  motorhiz(50, -65);
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
     
    if(currentBlock - blockNumber<0){
      currentBlock = (currentBlock - blockNumber) +8;
    }else{
      currentBlock = (currentBlock - blockNumber) % 8;
    }
  }
  else if (directionn == LEFT) {
    digitalWrite(dirPin, LOW);
    currentBlock = (currentBlock+ blockNumber) %8 ;
  }

  for (int x = 0; x < 25 * blockNumber; x++) {
    digitalWrite(stepPin, HIGH);
    delay(10);
    digitalWrite(stepPin, LOW);
    delay(10);
  }
  delay(1000); //ayarlanabilir kısım
}

void findBlock() {
  int currentRoom = renkbul();
  if (currentRoom != -1) {
    Serial.print("Current room   : ");
    Serial.println(currentRoom );
    Serial.print("Current block   : ");
    Serial.println(currentBlock );
    int roundNumber = currentBlock - currentRoom;
    Serial.print("round number   : ");
    Serial.println(roundNumber );
    if (roundNumber < -4) goStep(roundNumber + 8, RIGHT);
    else if (roundNumber > 4) goStep(abs(roundNumber - 8), LEFT);
    else {
      if (roundNumber > 0) goStep(roundNumber, RIGHT);
      else if (roundNumber < 0) goStep(abs(roundNumber), LEFT);
    }
  }
}

void turnServo(){
  
   servoTurn(servoBuyuk, 150);
  servoTurn(servoKucuk, 160);
  servoTurn(servoBuyuk, 8);
  delay(1000);
  servoTurn(servoKucuk, 140);
  servoTurn(servoBuyuk, 80);
  servoTurn(servoKucuk, 105);
  delay(3000);
  
  
}


void servoTurn(Servo Servos, int targetDegree) {

  int currentDegree = Servos.read();
  byte turnSpeed = 10; //increase for slower turn

  //Checking turn direction with looking targetDegree is greater or not
  if (currentDegree < targetDegree) {
    for (int i = currentDegree; i <= targetDegree; i++) {
      Servos.write(i);
      delay(turnSpeed);
    }
  } else {
    for (int i = currentDegree; i >= targetDegree; i--) {
      Servos.write(i);
      delay(turnSpeed);
    }
  }

}
