// 0sa beyaz 1se siyah
#include <Adafruit_TCS34725.h>
#include <Wire.h>
#include <Servo.h>

//motor define
int E1 = 5;
int M1 = 4;
int E2 = 6;
int M2 = 7;

//motor hızları
int motorsolhiz;
int motorsaghiz;

uint16_t  r, g, b, c;
float red, green, blue, ortalama;


Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

int renkCounter = 0;
const int ilkmotorsolhiz = 70;
const int ilkmotorsaghiz = 75;
float kp = 30;
bool cizgitam = false;
bool soladondu = false;
bool geridonecek = false;
//qtr pins
const byte qtrpins[] = {22, 24, 26, 28, 30, 32};
byte sensorvalues[]={1,1,1,1,1,1};
const byte solqtr = 38;
const byte sagqtr = 36;
byte sagqtrValue;
byte solqtrValue;
int room = 0;
float r1[7];
float g1[7];
float b1[7];
const int sharpsol = 43;
const int sharporta = 45;
const int sharpsag = 47;

const int stepPin = 31; //değişecek
const int dirPin = 33; 
int currentBlock=0;
Servo servoKucuk;  /* servo motor nesnesi yaratildi */
Servo servoBuyuk;
Servo myservomotor; // sınıfın bir örneğini aldık

boolean checkBox=false;
unsigned int start;
enum directions {
  RIGHT,
  LEFT
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  defineAll();
  servoTurn(servoKucuk, 60);
  servoTurn(servoBuyuk, 80);
  qtrread();
}

void loop() {
 
  travelAllRoom();
  travelAllRoomForDrop();
  while (1);
}
