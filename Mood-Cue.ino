#include <Servo.h>

Servo myServo;
int potPin = A0;
int potValue;
int angle;
int servoPin = 9;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);

  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);

  Serial.print("Potval: ");
  Serial.println(potValue);

  angle = map(potValue, 0, 1023, 0, 179);

  Serial.print("Angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
}
