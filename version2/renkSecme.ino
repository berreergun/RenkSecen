// 0sa beyaz 1se siyah
#include <Adafruit_TCS34725.h>
#include <Wire.h>

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
int room = 0;

float r1[7];
float g1[7];
float b1[7];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  qtrpinsdefine();
  motordefine();
 motorhiz(60, 60);
 qtrread();

}

void loop() {
// qtrread();
 
 // renkoku();
// goUntilT();
  // followLine();
  travelAllRoom();
  travelAllRoomForDrop();
  while (1);
}
