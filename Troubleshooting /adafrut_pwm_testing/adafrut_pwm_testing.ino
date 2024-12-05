#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH  1000   // Minimum pulse width in microseconds (0°)
#define MAX_PULSE_WIDTH  2000   // Maximum pulse width in microseconds (120°)
#define FREQUENCY        50     // Servo frequency in Hz (standard 50 Hz)

// Function to convert angle to pulse width for the MG996R
int angleToPulse(int angle) {
  int pulse = map(angle, 0, 120, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH); // Map angle to microseconds
  Serial.print("Angle: ");
  Serial.print(angle);
  Serial.print(" -> Mapped Pulse (us): ");
  Serial.println(pulse);
  return pulse;
}

void setup() {
  Serial.begin(9600);
  Serial.println("Testing MG996R Servo with Adafruit PWM Servo Driver");

  pwm.begin();               // Initialize the Adafruit board
  pwm.setPWMFreq(FREQUENCY); // Set PWM frequency to 50 Hz
}

void loop() {
  // Move the servo to 60° (center position)
  int pulse = angleToPulse(60); // Get mapped pulse width in microseconds
  int pwmValue = pulse * FREQUENCY * 4096L / 1000000L; // Convert to Adafruit scale
  Serial.print("Sending 60 degrees - PWM Value: ");
  Serial.println(pwmValue);
  pwm.setPWM(15, 0, pwmValue);
  delay(2000);

  // Move the servo to 0° (minimum position)
  pulse = angleToPulse(0); // Get mapped pulse width in microseconds
  pwmValue = pulse * FREQUENCY * 4096L / 1000000L; // Convert to Adafruit scale
  Serial.print("Sending 0 degrees - PWM Value: ");
  Serial.println(pwmValue);
  pwm.setPWM(15, 0, pwmValue);
  delay(2000);

  // Move the servo to 120° (maximum position)
  pulse = angleToPulse(120); // Get mapped pulse width in microseconds
  pwmValue = pulse * FREQUENCY * 4096L / 1000000L; // Convert to Adafruit scale
  Serial.print("Sending 120 degrees - PWM Value: ");
  Serial.println(pwmValue);
  pwm.setPWM(15, 0, pwmValue);
  delay(2000);
}
