#include <Servo.h>

Servo testServo;

void setup() {
  testServo.attach(9); // Attach servo to pin 9
  testServo.write(90); // Move to 90 degrees
  delay(2000);
}

void loop() {
  testServo.write(80);  // Move to 0 degrees
  delay(5000);
  testServo.write(180); // Move to 180 degrees
  delay(2000);
}
