#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH  1000   // Minimum pulse width in microseconds (0°)
#define MAX_PULSE_WIDTH  2000   // Maximum pulse width in microseconds (120°)
#define FREQUENCY        50     // Servo frequency in Hz (standard 50 Hz)

// Function to convert angle to pulse width for the MG996R
int angleToPulse(int angle) {
  return map(angle, 0, 120, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Testing MG996R Servo with Adafruit PWM Servo Driver");

  pwm.begin();               // Initialize the Adafruit board
  pwm.setPWMFreq(FREQUENCY); // Set PWM frequency to 50 Hz

  // Define the desired angle here
  int angle = 0; // Change this value to desired angle (0 to 120 degrees)

  // Calculate pulse width and move servo
  int pulse = angleToPulse(angle); // Get the pulse width for the desired angle
  int pwmValue = pulse * FREQUENCY * 4096L / 1000000L; // Convert to Adafruit scale
  pwm.setPWM(12, 0, pwmValue); // Send the signal to Channel 0

  // Print debug information
  Serial.print("Moving to ");
  Serial.print(angle);
  Serial.println(" degrees.");
}

void loop() {
  // Do nothing in the loop since the servo moves only once on startup
}
