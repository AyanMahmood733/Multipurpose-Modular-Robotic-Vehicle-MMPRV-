#include <Servo.h>
Servo neckServo;
Servo frontServo;
const int trigPin = 2;
const int echoPin = 3;
const int motorPin1 = 8;
const int motorPin2 = 9;
const int motorPin3 = 10;
const int motorPin4 = 11;
const int neckPin = 5;
const int motorspeed1 = 12;
const int motorspeed2 = 13;
long duration;
int distance;
int pos = 90;
int maxdist = 0; 
int pos1;
int neckPos;
int pos2 = 90;
int dist1 = 0;
int pos3;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(neckPin, OUTPUT);
    neckServo.attach(5);
    frontServo.attach(4);
    Serial.begin(9600);
    neckServo.write(90);
}

void loop() {
    int pos = 90;
    int pos1 = 0;
    int dist1 = 0;
    int maxdist = 0;
    int count = 0;
    if (pos == 90){
        Serial.print("Distance ");
        delay(100);
        Serial.println(distance);
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, HIGH);
        digitalWrite(motorPin4, LOW);
        delay(1000);
    }
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.0342 / 2;
    delay(10);
    if (distance <= 30) {
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        Serial.println("Motors stopped");
        delay(300);
        for (count = 0; count <= 17; count++) {
            Serial.println("Rotating HC-SR04");
            if (pos >= 180) {
               pos = 0;
            }
           if (pos <= 180) {
              pos = pos+15;
                Serial.print("Distance at Angle: ");
                Serial.print(pos);
                Serial.print(",");
                neckServo.write(pos);
                delay(10);
                digitalWrite(trigPin, HIGH);
                delayMicroseconds(10);
                digitalWrite(trigPin, LOW);
                duration = pulseIn(echoPin, HIGH);
                distance = duration * 0.0342 / 2;
                delay(100);
              Serial.println(distance);
              if (distance < 200) {
             if (maxdist <= distance){
                maxdist = distance;
                pos1 = pos;
             }
             if (maxdist >= dist1) {
                    dist1 = maxdist;
                    pos2 = pos1;
                    
                }
           }
           }
        Serial.print("Most Optimal Angle for Highest Distance: ");
        Serial.print(pos2);
        Serial.print(",");
        Serial.println(dist1);
        delay(100);
        pos3 = pos2 / 2;
        }
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(1000);
    frontServo.write(pos3);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    neckServo.write(90);
    }
    delay(1000);
    frontServo.write(90);
}