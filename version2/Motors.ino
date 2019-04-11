void motordefine() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);


   ///Servo Define
   servoBuyuk.attach(39);
  servoKucuk.attach(41);
  
}
  

void motorhiz(int solhiz, int saghiz) {
  if (solhiz > 0) {
    digitalWrite(M1, HIGH);

  }
  else {
    digitalWrite(M1, LOW);
  //  solhiz=0-solhiz;
  }
  if (saghiz > 0) {
    digitalWrite(M2, HIGH);

  }
  else {
    digitalWrite(M2, LOW);
   // saghiz=0-saghiz;
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
  delay(20);
  
  motorhiz(0, 0);
}



void turnLeft() {
  motorhiz(-200, 70);
  delay(400);
  while (1) {
    qtrread();
    if (sensorvalues[3] == 0) {
      if (sensorvalues[2] == 0)
        break;
    }
  }
  motorhiz(50, -180);
  delay(50);
  motorhiz(0, 0);
}

void turnRight() {
  motorhiz(50, -180);
  delay(500);
  while (1) {
    qtrread();
    if (sensorvalues[4] == 0) {
      if (sensorvalues[5] == 0)
        break;
    }
  }
  motorhiz(-200, 70);
  delay(50);
  motorhiz(0, 0);
}
void turnRightForFirst() {
  motorhiz(0, -90);
  delay(500);
  while (1) {
    qtrread();
    if (sensorvalues[4] == 0) {
      if (sensorvalues[5] == 0)
        break;
    }
  }
  motorhiz(0, 90);
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
  delay(100); //ayarlanabilir kısım
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
   
  servoTurn(servoBuyuk, 150);//kolun asagı inmesi için
  servoTurn(servoKucuk, 85);//cismi al
  delay(500);
  servoTurn(servoBuyuk, 5);//kol yukarı cık
  delay(500);
  servoTurn(servoKucuk, 70);//cismi bırak
  delay(500);
  servoTurn(servoBuyuk, 90);//kol orta konuma gel
  servoTurn(servoKucuk, 50);//gripper açık konuma gel
  delay(500);
    
  
  
}


void turnServoForDrop(){
   servoTurn(servoKucuk, 60);//gripper açık konuma gel
   servoTurn(servoBuyuk, 5);//kol yukarı cık
   delay(500);
   servoTurn(servoKucuk, 85);//cismi al
   delay(500);
   servoTurn(servoBuyuk, 150);//kolun asagı inmesi için
   servoTurn(servoKucuk, 65);//cismi bırak
    delay(500);
   servoTurn(servoBuyuk, 90);//kol orta konuma gel
   servoTurn(servoKucuk, 60);//gripper açık konuma gel
   delay(500);
   
   
  
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
