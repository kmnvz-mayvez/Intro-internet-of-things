// define signal watersensor pin for waterstrength
#define SIGNAL_PIN 33

// declare libary
#include <ESP32Servo.h>

// declare servo
Servo myservo;

// create const pin 
const int pinWater = 35;

// crate variable 
int water;
int cl = 110;
int op = 10;
bool servoActive = true;

// funct for detec water_strenght
void myWaterStrength() {
    sensorValue = analogRead(SIGNAL_PIN);
    Serial.print("Water detected = Sensor Value: ");
    Serial.println(sensorValue);

    delay(500);
  }

// main funct to create automatic_rainsensor
void myFunction() {
  water = digitalRead(pinWater);
  
  if (water == 1) {
    Serial.println("no water");
  } else if (water == 0) {
    Serial.println("water detec");
  }

   if (servoActive) {
    if (water == 0) {
      myservo.write(cl);
      Serial.println("close");
    } else if (water == 1) {
      myservo.write(op);
      Serial.println("open");
  } else {
    myservo.writeMicroseconds(0);
    Serial.println("servo not active");
  }
  delay(500);
}

// set up for publish
void setup() {
  myservo.attach(13);
  pinMode(pinWater, INPUT);
  Serial.begin(115200);
}

// for loop function on the top
void loop() {
  myWaterStrength();
  myFunction();
}
