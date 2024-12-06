#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define FREQUENCY 50 // Servo frequency in Hz (standard 50 Hz)

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

  // Debug output
  Serial.print("Channel ");
  Serial.print(channel);
  Serial.print(": Angle = ");
  Serial.print(angle);
  Serial.print(", Pulse Width (us) = ");
  Serial.println(pulse);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Testing servo positions...");

  pwm.begin();               // Initialize the Adafruit board
  pwm.setPWMFreq(FREQUENCY); // Set PWM frequency to 50 Hz

  // Define servo channels and angles
  int channels[5] = {11, 12, 13, 14, 15}; // Channels for the 5 servos
  //int angles[5] = {45, 90, -100, 200, 100};        // Set all servos to 0 degrees for testing
  int angles[5] = {0, 0, -0, 0, 0}; 
  // Move each servo to its specified angle
  for (int i = 0; i < 5; i++) {
    if (channels[i] == 11) { // SG90
      moveServo(channels[i], angles[i], SG90_MIN, SG90_MAX);
    } else if (channels[i] == 15) { // High Torque Servo
      moveServo(channels[i], angles[i], HIGH_TORQUE_MIN, HIGH_TORQUE_MAX);
    } else { // MG996R (default for other channels)
      moveServo(channels[i], angles[i], MG996R_MIN, MG996R_MAX);
    }
    delay(1000); // Add delay between movements
  }
}

void loop() {
  // Nothing to do here
}
