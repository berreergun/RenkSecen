#include <Adafruit_TCS34725.h>

#include <Wire.h>
#include <AFMotor.h>
//motor define
AF_DCMotor motorsol(3);
AF_DCMotor motorsag(4);
//motor hızları
int motorsolhiz;
int motorsaghiz;
uint16_t  r,g,b,c;
float red,green,blue,ortalama;


Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);


const int ilkmotorsolhiz = 70;
const int ilkmotorsaghiz = 70;
float kp = 15;
bool cizgitam = false;
bool soladondu = false;
bool geridonecek = false;
//qtr pins
const byte qtrpins[] = {22, 24, 26, 28, 30, 32};
byte sensorvalues[6];
const byte solqtr = 38;
const byte sagqtr = 36;
byte sagqtrValue;
byte solqtrValue;
int i=0;

void setup() {
  Serial.begin(9600);
  qtrpinsdefine();
  


}

void loop() {
  
  //For qtrs
  qtrread();
  //qtryazdirma();

  //Pid line follow
  int p = positionQtr();
  motorhiz(ilkmotorsolhiz - p * kp, ilkmotorsaghiz + p * kp);

  //for turn
//renkoku();
  if(tcs.begin()){
    
  }
  else{
    Serial.print("okumadı");
  }


  donmefonk();


   motorhiz(ilkmotorsolhiz - p * kp, ilkmotorsaghiz + p * kp);
  //To control motors
  /*  Serial.print(ilkmotorsolhiz-p*kp);
    Serial.print(" ");
    Serial.println(ilkmotorsaghiz+p*kp);*/
  //Serial.println(p);

  if(soladondu && sensorvalues[3] == 1 && sensorvalues[4] == 1 && sensorvalues[2] == 1 && sensorvalues[1] == 1 && sensorvalues[0] == 1 && sensorvalues[5] == 1 ){

    Serial.println(geridonecek);

    qtrread();
    motorhiz(0,0);
    delay(200);
  
    motorhiz(-100, -100);
    delay(250);
    motorhiz(0,0);
    soladondu=false;
    
   //çizginin bittiği ve rengi okuyacağı yer
    renkkaydet()
   //rengi kaydedip geri dönecek
   
    geridonecek=true;
    
    Serial.println("2");
 
    Serial.println(geridonecek);

  }
  if(geridonecek){
     motorhiz(-ilkmotorsolhiz, -ilkmotorsaghiz);
     motorhiz(-1*(ilkmotorsolhiz - p * kp), -1*(ilkmotorsaghiz + p * kp));
     if( sagqtrValue == 0 || solqtrValue == 0){

      motorhiz(50,-50);
      while(sensorvalues[0] == 1){
        
         motorhiz(50,-50);
         qtrread();
         delay(100);
         if(sensorvalues[0] == 0){
          
           motorhiz(ilkmotorsolhiz - p * kp, ilkmotorsaghiz + p * kp);
           geridonecek=false;
          break;
         }
      }

     
     }
     
  }



}

void donmefonk() {


  qtrread();
  int p = positionQtr();
  if (sensorvalues[3] == 0 && sensorvalues[4] == 0 && sensorvalues[2] == 0 && sensorvalues[1] == 0 ) {
    qtrread();
    cizgitam = true;
    Serial.print("    ife girdi   ");
   // motorhiz(0, 0);
    delay(100);
  }

  if (cizgitam && sagqtrValue == 0 && solqtrValue == 0) {
      Serial.print("    donmeye  girdi   ");
    while (sensorvalues[5] == 1 ) {
      motorhiz(-50, 50);
      qtrread();
      delay(100);
      if (sensorvalues[5] == 0) {
        delay(50);
        motorhiz(ilkmotorsolhiz, ilkmotorsaghiz);
        delay(50);
        motorhiz(ilkmotorsolhiz - p * kp, ilkmotorsaghiz + p * kp);
        cizgitam = false;
        soladondu=true;
        break;
      }

    }

  }
  else {
    motorhiz(ilkmotorsolhiz - p * kp, ilkmotorsaghiz + p * kp);

  }

   motorhiz(ilkmotorsolhiz - p * kp, ilkmotorsaghiz + p * kp);


}
