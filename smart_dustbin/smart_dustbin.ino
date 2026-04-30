#include <Servo.h>

#define TRIG_PIN 5
#define ECHO_PIN 6
#define SERVO_PIN 9

Servo dustbinServo;

long duration;
int distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  dustbinServo.attach(SERVO_PIN);

  // Lid closed initially
  dustbinServo.write(0);

  Serial.begin(9600);
}

void loop() {

  // Send ultrasonic wave
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  // Read echo
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // If hand detected within 20 cm
  if (distance > 0 && distance <= 20) {

    // Open lid
    dustbinServo.write(90);

    delay(3000);

    // Close lid
    dustbinServo.write(0);
  }

  delay(200);
}