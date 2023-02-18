#include "Wire.h"
#include <MPU6050_light.h>
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define ENA 9
#define ENB 10
#define trigPin 11
#define echoPin 13
#define buttonpin 7
#define ledpin 6
MPU6050 mpu(Wire);
unsigned long timer = 0;
long  duration; 
int   distance; 
bool  state = false;
bool  ustate = true;
float anglei;
float angleZ;
int   presstime1 = 1;
int   presstime2 = 300;
int   presslength = 0;
float zdir = 0;
float *zdirad = &zdir;
void setup()
{
  Serial.begin(9600);
  Wire.begin();

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(ledpin,    OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 

  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while (status != 0) { } //CALIBRATION SEQUENCE FOR THE GYROSCOPE
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");

}
void loop() {

  while (state == true && ustate == true)
  {
    mpu.update();
    angleZ = mpu.getAngleZ();
    drive(150, 150);
    Serial.println("On");
    if (angleZ < zdir )
    {
      drive(150, 127);
    }
    else if (angleZ > zdir )
    {
      drive(127, 150);
    }
    Serial.println(angleZ);
    state  = checkbutton(state, zdirad);
    ustate = checkultra();
  }
  mpu.update();
  angleZ = mpu.getAngleZ();
  Serial.println(angleZ);
  Serial.println("Off");
  state  = checkbutton(state, zdirad);
  ustate = checkultra();
  drive(0, 0);
}


void drive( int MotorAspeed,  int MotorBspeed)
{
  analogWrite (ENA, MotorAspeed);
  analogWrite (ENB, MotorBspeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

bool checkbutton(bool pstate, float *zad) //PUSH BUTTON CHECK
{
  bool nextstate = pstate;
  while ( digitalRead(buttonpin) == LOW)
  {
    presslength = presslength + 1;
    Serial.println(presslength);
  }
  if (presslength >= presstime2) {
    nextstate = true;
    mpu.update();
    *zad = mpu.getAngleZ();
    digitalWrite(ledpin, HIGH);
    Serial.println("Zdir:");
    Serial.println(zdir);
  }
  else if ((presslength >= presstime1))
  {
    nextstate = false;
    digitalWrite(ledpin, LOW);
  }
  presslength = 0;
  return nextstate;
}


bool checkultra()// ULTRASONIC SENSOR READING CHECK
{
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
  
  if (distance <= 30)
    {
    return false;
    }
  else
    {
     return true;
    }
}
