
float r1[7];
float g1[7];
float b1[7];
void degerAta(){
  for( int a=0 ; a<7 ; a++){
  r1[a]= 0.0;
  g1[a]= 0.0;
  b1[a]=0.0;
  }
  }
  

void renkkaydet(){
   if(tcs.begin()){
     
  }
  else{
    Serial.print("okumadı");
  }
   for ( int i=0 ; i<7 ; i++){
    if(r1[i]== 0 && g1[i]== 0 && b1[i]==0){
      tcs.getRawData(&r,&g,&b,&c);
      ortalama = (r+g+b)/3; // renk değerlerini topla ve ortalamasını al
      red = r/ortalama; // kırmızı renk değeri oranı
      green = g/ortalama; // yeşil renk değeri oranı
      blue = b/ortalama; 

      r1[i]= red ;
      g1[i]= green ;
      b1[i]= blue ;
     /* Serial.print(r1[i]);
      Serial.print("     ");
      Serial.print(g1[i]);
      Serial.print("     ");
      Serial.print(b1[i]);
      Serial.print("     ");
      Serial.println();*/
      break;
    }
      delay(1000);
  }
  
}
 void renkyazdir(){
  for(int k=0;k<7;k++){
    
      Serial.print(r1[k]);
      Serial.print("     ");
      Serial.print(g1[k]);
      Serial.print("     ");
      Serial.print(b1[k]);
      Serial.print("     ");
      Serial.println();
  }
 }
 void renkbul(){
  
      tcs.getRawData(&r,&g,&b,&c);
      ortalama = (r+g+b)/3; // renk değerlerini topla ve ortalamasını al
      red = r/ortalama; // kırmızı renk değeri oranı
      green = g/ortalama; // yeşil renk değeri oranı
      blue = b/ortalama;
      for ( int a=0 ; a<7 ; a++){
         if (((red > r1[a]-0.05) && (red < r1[a]+0.05)) && ((green > g1[a]-0.05) && (green < g1[a]+0.05)) && ((blue > b1[a]-0.05) && (blue < b1[a]+0.05))){
        //burada silindiri koyması gerekir.
        
          Serial.print("Rengi buldum şunda:   ");
          Serial.print(a);
          Serial.println();
          r1[a]=0;
          g1[a]=0;
          b1[a]=0;
        }
      }

 }


int positionQtr() {
  if (sensorvalues[2] == 0 && sensorvalues[3] == 0) {
    return 0;
  } else if (sensorvalues[3] == 0 || sensorvalues[4] == 0) {
    return 1;
  } else if (sensorvalues[4] == 0 || sensorvalues[5] == 0) {
    return 2;
  } else if (sensorvalues[2] == 0 || sensorvalues[1] == 0) {
    return -1;
  } else if (sensorvalues[0] == 0 || sensorvalues[1] == 0) {
    return -2;
  }

  return 0;
}

/*void donmefonk() {

 
 qtrread();
 int p = positionQtr();
  if (sensorvalues[3] == 0 && sensorvalues[4] == 0 && sensorvalues[2] == 0 && sensorvalues[1] == 0 ) {
    qtrread();
    cizgitam = true;
     Serial.print("    ife girdi   ");
    motorhiz(0,0); 
    delay(1000);
  }
  else{
 cizgitam=false;
    
  }
    if (!cizgitam && sagqtrValue == 0 && solqtrValue == 0) {
    while (sensorvalues[5] == 1 ) {
      motorhiz(-50, 50);
      qtrread();
      delay(100);
      if (sensorvalues[5] == 0) {
        delay(50);
        motorhiz(ilkmotorsolhiz,ilkmotorsaghiz);
        delay(50);
        motorhiz(ilkmotorsolhiz - p * kp, ilkmotorsaghiz + p * kp);
        cizgitam=false;
        break;
      }

    }

      }
      else{
  motorhiz(ilkmotorsolhiz - p * kp, ilkmotorsaghiz + p * kp);
        
      }
  

 

}*/
