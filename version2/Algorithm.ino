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

  while (1) {
    followLine();
    renkoku();
    if (!(((0.65 < red) && (red < 0.70) && (1.15 < green) && (green < 1.25) && (1.10 < blue) && (blue < 1.20)))){
      Serial.println("iff siyah değil");
      break;
    }

  }

  stopMotors();

  delay(500);
}

void goBack() {
  while (1) {
    motorhiz(-50, -50);
    qtrread();
    if (sagqtrValue == 0 || solqtrValue == 0) break;
  }
  stopMotors();
  delay(500);
}


void goToRoom() {

  goUntilT();
  turnLeft();
  goUntilColor();
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
