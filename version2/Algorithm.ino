void goUntilT() {
  while (1) {
    followLine();
    //Serial.print("qtr");
    // Serial.println(computeQtr());
    if (computeQtr() < 2) break;
  }

  stopMotors();
  //delay(50);
  goForTurn();
}

void goForTurn() {
  while (1) {
    followLine();
    qtrread();
    if (sagqtrValue == 0 || solqtrValue == 0) break;
  }

  stopMotors();
//  delay(250);
}


void goUntilColor() {
  while (1) {
    renkCounter = 0;
    followLine();
    renkoku();
    if (colorControl()) break;
  }
  stopMotors();
  delay(100);
}

boolean colorControl() {
  while (!((0.65 < red) && (red < 0.70) && (1.15 < green) && (green < 1.25) && (1.09 < blue) && (blue < 1.20))) {
    renkCounter++;
    Serial.println("while");
    if (renkCounter > 2){
      Serial.println("if");
      return true;
    }
    renkoku();
  }
  return false;
}
/*void goUntilColor() {
   int renk = 0;
  while (1) {

    followLine();

    renkoku();

    if (!(((0.65 < red) && (red < 0.70) && (1.15 < green) && (green < 1.25) && (1.09 < blue) && (blue < 1.20)))) {

      renk = renk + 1;
      Serial.print("renk");
      Serial.print(renk);


    }
    if (renk > 2) {
      Serial.println(" siyah değil, odadayım ");
      break;
    }
  }

  stopMotors();


  delay(100);
  // goUntilPrisma();
  }*/

void goBack() {
  while (1) {
    motorhiz(-95, -85);   //-40 -65 ti
    qtrread();
    if (sagqtrValue == 0 || solqtrValue == 0) break;
  /* if (sagqtrValue == 0 || solqtrValue == 0){
     if(solqtrValue == 0){
      motorhiz(0, -10);
      if(sagqtrValue == 0) break;
    }
     if(sagqtrValue == 0){
      motorhiz(-10, 0);
      if(solqtrValue == 0) break;
    }
   }*/
   
  }

  stopMotorsToBack();
  delay(300);//elleme
}

void goBackIfRight() {
  while (1) {
    motorhiz(-90, -60);   
    qtrread();
    if (sagqtrValue == 0 || solqtrValue == 0) break;

   
  }

  stopMotorsToBack();
  delay(300);//elleme
}
void goBackIfLeft() {
  while (1) {
    motorhiz(-80, -100);   
    qtrread();
    if (sagqtrValue == 0 || solqtrValue == 0) break;
}
  stopMotorsToBack();
  delay(300);//elleme
}

int amIRight() {

  if (digitalRead(sharpsol) == 1 && digitalRead(sharpsag) == 1 && digitalRead(sharporta) == 0)
    return 1;
  else if (digitalRead(sharpsol) == 1 && digitalRead(sharpsag) == 1 && digitalRead(sharporta) == 1)
    return 2;
  else if(digitalRead(sharpsol) == 0 && (digitalRead(sharpsag) == 1 || digitalRead(sharporta) == 1))
    return 3;
  else if(digitalRead(sharpsag) == 0 && (digitalRead(sharpsol) == 1 || digitalRead(sharporta) == 1))
    return 4;
  else return 5;
}
void goUntilPrisma() {
 
  while (1) {
    followLine();
    // motorhiz(50, 50);
    if (amIRight() == 1 ) {
      Serial.println("I am Right");
       stopMotors();
      
     delay(200);
      break;
    }
    else if (amIRight() == 3) {
      Serial.println("I am wrong");
      goBackIfLeft();
      // delay(20);
      //goUntilPrisma();
    }
    else if (amIRight() == 4) {
      Serial.println("I am wrong");
      goBackIfRight();
     
    }
    else if (amIRight() == 5) {
      Serial.println("I am wrong");
      goBack();
      // delay(20);
      //goUntilPrisma();
    }
  
  }

}


void goToRoom() {

  goUntilT();
  turnLeft();
  goUntilPrisma();
   motorhiz(0, 0);
  turnServo();
  renkkaydet();
  goStep(1,LEFT);
  goBack();
  turnRight();
}


void goToRoomForDrop() {
  goUntilT();
  turnLeft();
  goUntilColor();
  findBlock();
  turnServoForDrop();
  goBack();
  turnRight();
}

void goFirst2room() {
  goUntilColor();
  findBlock();
  turnServoForDrop();
  goBack();
  turnRight();
}

void travelAllRoom() {
  for (int i = 0; i < 7; i++) {
    goToRoom();
    room++;
  }
}


//bu fonksiyon bitmedi düzenlenecek
void travelAllRoomForDrop() {
  goFirst2room();
  goFirst2room();

  for (int i = 0; i < 6; i++) {
    goToRoomForDrop();

  }

  goUntilColor();
  findBlock();
  turnServoForDrop();
  //renkbul();
}
