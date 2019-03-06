// 0sa beyaz 1se siyah
#include <Adafruit_TCS34725.h>
#include <Wire.h>
#include <AFMotor.h>
//motor define
AF_DCMotor motorsol(3);
AF_DCMotor motorsag(4);
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
  motorhiz(ilkmotorsolhiz,ilkmotorsaghiz);
}

void loop() {
travelAllRoom();
travelAllRoomForDrop();
while(1);
}
