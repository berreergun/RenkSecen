void renkoku() {

  tcs.getRawData(&r, &g, &b, &c);
  Serial.print(b);
  ortalama = (r + g + b) / 3; // renk değerlerini topla ve ortalamasını al
  red = r / ortalama; // kırmızı renk değeri oranı
  green = g / ortalama; // yeşil renk değeri oranı
  blue = b / ortalama;

}

void renkkaydet() {
  renkoku();
  r1[room] = red ;
  g1[room] = green ;
  b1[room] = blue ;
}


void renkbul() {
  renkoku();
  for ( int a = 0 ; a < 7 ; a++) {
    if (((red > r1[a] - 0.05) && (red < r1[a] + 0.05)) && ((green > g1[a] - 0.05) && (green < g1[a] + 0.05)) && ((blue > b1[a] - 0.05) && (blue < b1[a] + 0.05))) {
      //burada silindiri koyması gerekir.

      Serial.print("Rengi buldum şunda:   ");
      Serial.print(a);
      Serial.println();
      r1[a] = 0;
      g1[a] = 0;
      b1[a] = 0;
    }
  }

}
