#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define FREQUENCY        50     // Servo frequency in Hz (standard 50 Hz)

// Servo-specific pulse width ranges
#define MG996R_MIN  1000   // MG996R: Minimum pulse width in microseconds
#define MG996R_MAX  2000   // MG996R: Maximum pulse width in microseconds
#define SG90_MIN    500    // SG90: Minimum pulse width in microseconds
#define SG90_MAX    2400   // SG90: Maximum pulse width in microseconds
#define HIGH_TORQUE_MIN 500  // 20KG Servo: Minimum pulse width in microseconds
#define HIGH_TORQUE_MAX 2500 // 20KG Servo: Maximum pulse width in microseconds

// Function to convert angle to pulse width for specific servo
int angleToPulse(int angle, int minPulse, int maxPulse) {
  return map(angle, 0, 180, minPulse, maxPulse); // Adjusted for servo-specific range
}

// Function to move a servo to a specified angle
void moveServo(int channel, int angle, int minPulse, int maxPulse) {
  int pulse = angleToPulse(angle, minPulse, maxPulse); // Get the pulse width for the angle
  int pwmValue = pulse * FREQUENCY * 4096L / 1000000L; // Convert to Adafruit scale
  pwm.setPWM(channel, 0, pwmValue); // Send the signal to the specified channel

  // Print debug information
  Serial.print("Moving motor on channel ");
  Serial.print(channel);
  Serial.print(" to ");
  Serial.print(angle);
  Serial.println(" degrees.");
}

void setup() {
  Serial.begin(9600);
  Serial.println("Testing multiple servo types with Adafruit PWM Servo Driver");

  pwm.begin();               // Initialize the Adafruit board
  pwm.setPWMFreq(FREQUENCY); // Set PWM frequency to 50 Hz

  // Define the channels and angles for each motor
  int channels[5] = {11, 12, 13, 14, 15}; // Channels for the 5 servos
  int angles[5] = {0, 0, 0, 0, 0};  // Angles for each motor

  // Move each motor to its specified angle with appropriate PWM ranges
  moveServo(channels[0], angles[0], SG90_MIN, SG90_MAX); // SG90 on channel 11
  delay(5000);
  moveServo(channels[1], angles[1], MG996R_MIN, MG996R_MAX); // MG996R on channel 12
  delay(5000);
  moveServo(channels[2], angles[2], MG996R_MIN, MG996R_MAX); // MG996R on channel 13
  delay(5000);
  moveServo(channels[3], angles[3], MG996R_MIN, MG996R_MAX); // MG996R on channel 14
  delay(5000);
  moveServo(channels[4], angles[4], HIGH_TORQUE_MIN, HIGH_TORQUE_MAX); // 20KG Servo on channel 15
  delay(5000);
}

void loop() {
  // Do nothing in the loop since the servos move only once on startup
}
