#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define MIN_PULSE_WIDTH       650   // Minimum pulse width for the servo (us)
#define MAX_PULSE_WIDTH       2350  // Maximum pulse width for the servo (us)
#define FREQUENCY             50    // Servo frequency in Hz

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int potPins[4] = {A0, A1, A2, A3};        // Analog pins for the potentiometers
int motorChannels[4] = {12, 13, 14, 15}; // Motor channels for the servos

int potOffsets[4]; // Array to store offset values for each potentiometer

void setup() {
  Serial.begin(9600);
  delay(5000); // Wait for stability
  
  // Initialize offsets based on initial potentiometer readings
  for (int i = 0; i < 4; i++) {
    potOffsets[i] = analogRead(potPins[i]); // Capture initial value
    Serial.print("Potentiometer ");
    Serial.print(i);
    Serial.print(" initial offset: ");
    Serial.println(potOffsets[i]);
  }
}

int mapPotValueToAngle(int potValue, int offset) {
  int adjustedValue = potValue - offset; // Subtract offset
  adjustedValue = constrain(adjustedValue, 0, 1023); // Ensure value is within bounds
  return map(adjustedValue, 0, 1023, 0, 180); // Map to angle (0–180°)
}

int angleToPulseWidth(int angle) {
  return map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH); // Map angle to pulse width
}

void loop() {
  for (int i = 0; i < 4; i++) {
    int potValue = analogRead(potPins[i]); // Read potentiometer value
    int angle = mapPotValueToAngle(potValue, potOffsets[i]); // Adjust value and map to angle
    int pulseWidth = angleToPulseWidth(angle); // Map to pulse width

    // Print debug information
    Serial.print("Potentiometer ");
    Serial.print(i);
    Serial.print(" (Pin ");
    Serial.print(potPins[i]);
    Serial.print(") -> Value: ");
    Serial.print(potValue);
    Serial.print(", Adjusted Angle: ");
    Serial.print(angle);
    Serial.print("°, Pulse Width: ");
    Serial.print(pulseWidth);
    Serial.println(" us");
  }

  delay(500); // Add delay for stable readings
}
