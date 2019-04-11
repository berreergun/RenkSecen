void qtrread() {
  for (int i = 0; i < 6; i++) {
    sensorvalues[i] = digitalRead(qtrpins[i]);
  }
  sagqtrValue = digitalRead(sagqtr);

  solqtrValue = digitalRead(solqtr);
}



void qtrpinsdefine() {
  
  for (int i = 0; i < 6; i++) {
    pinMode(qtrpins[i], INPUT_PULLUP);

  }
  pinMode(solqtr, INPUT_PULLUP);
  pinMode(sagqtr, INPUT_PULLUP);
}


void qtryazdirma() {
qtrread();
  for (int i = 0; i < 6; i++) {
    Serial.print(sensorvalues[i]);
  }
  Serial.println();

  Serial.print(solqtrValue);
  Serial.print("     ");
  Serial.print(sagqtrValue);
  Serial.println();


}

int computeQtr() {
  int value = 0;
  qtrread();

  for (int i = 0; i < 6; i++) {
    value += sensorvalues[i];
  }

  return value;
}

void defineAll() {
  qtrpinsdefine();
  motordefine();
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(sharpsol, INPUT_PULLUP);
  pinMode(sharpsag, INPUT_PULLUP);
  pinMode(sharporta, INPUT_PULLUP);
}
