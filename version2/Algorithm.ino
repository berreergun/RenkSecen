void goUntilT() {
  while (1) {
    followLine();
    if (computeQtr() < 2) break;
  }
  stopMotors();
  delay(500);
  goForTurn();
}

void goForTurn() {
  while (1) {
    followLine();
    qtrread();
    if (sagqtrValue == 0 || solqtrValue == 0) break;
  }
  stopMotors();
  delay(500);
}

void goUntilColor() {
  int renk = 0;
  while (1) {
    followLine();

    renkoku();
    if (!(((0.65 < red) && (red < 0.70) && (1.15 < green) && (green < 1.25) && (1.09 < blue) && (blue < 1.20)))) {

      renk = renk + 1;
      Serial.print("renk");
      Serial.print(renk);


    }
    if (renk > 1) {
      Serial.println("iff siyah değil");
      break;
    }
  }

  stopMotors();


  delay(100);
  goUntilPrisma();
}

void goBack() {
  while (1) {
    motorhiz(-60, -50);
    qtrread();
    if (sagqtrValue == 0 || solqtrValue == 0) break;
  }
  stopMotors();
  delay(500);
}
int amIRight() {

  if (digitalRead(sharpsol) == 1 && digitalRead(sharpsag) == 1 && digitalRead(sharporta) == 0)
    return 1;
  else if (digitalRead(sharpsol) == 1 && digitalRead(sharpsag) == 1 && digitalRead(sharporta) == 1)
    return 2;
  else
    return 3;
}
void goUntilPrisma() {

  while (amIRight() == 2) {
    motorhiz(50, 50);


    if (amIRight() == 1 ) {
      //Serial.println("IamRight");
      break;
    }

    else if (amIRight() == 3) {
      // Serial.println("Iam wrong");
      goBack();
      delay(1000);
      goUntilColor();
 

    }

  }

  stopMotors();
  delay(1000);
}
/* if (sharporta) break;

  }
  if(sharpSag){
  goBack();
  delay(1000);
  goUntilColor();

  }
  if(sharpSol){
  goBack();
  delay(1000);
  goUntilColor();
  }*/




void goToRoom() {

  goUntilT();
  turnLeft();
  goUntilColor();
  goUntilPrisma();
  renkkaydet();
  goBack();
  turnRight();
}


void goToRoomForDrop() {
  goUntilT();
  turnLeft();
  goUntilColor();
  renkbul();
  goBack();
  turnRight();
}

void goFirst2room() {
  goUntilColor();
  renkbul();
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
  renkbul();
}
