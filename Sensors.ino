
void renkoku(){

  tcs.getRawData(&r,&g,&b,&c);
  Serial.print(b);
 ortalama = (r+g+b)/3; // renk değerlerini topla ve ortalamasını al
 red = r/ortalama; // kırmızı renk değeri oranı
 green = g/ortalama; // yeşil renk değeri oranı
 blue = b/ortalama; 
 
 }


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
  for (int i = 0; i < 6; i++) {
    Serial.print(sensorvalues[i]);
  }
  Serial.println();

  Serial.print(solqtrValue);
  Serial.print("     ");
  Serial.print(sagqtrValue);
  Serial.println();


}
