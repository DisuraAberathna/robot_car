#include <Ultrasonic.h>
Ultrasonic u = Ultrasonic(3, 4);  // Trig.Echo

#include <Servo.h>
Servo s = Servo();

int ENA = 11;
int IN1 = 10;
int IN2 = 9;

int ENB = 5;
int IN3 = 7;
int IN4 = 6;

void setup() {
  // put your setup code here, to run once:
  s.attach(2);  // Servo Pin

  // Motor A
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  analogWrite(ENA, 200);

  // Motor B
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  analogWrite(ENB, 200);

  Serial.begin(9600);  // Serial Monitor
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = Serial.read();

  // Forward
  if (x == "1") {
    s.write(90);
    delay(300);

    int d = u.read();

    if (d > 20) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
  }

  // Reverce
  if (x == "2") {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(500);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  // Turn Right
  if (x == "3") {
    s.write(45);
    delay(300);

    int d = u.read();

    if (d > 20) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(500);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    s.write(90);
  }

  // Turn Left
  if (x == "4") {
    s.write(135);
    delay(300);

    int d = u.read();

    if (d > 20) {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(500);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    s.write(90);
  }

  // Stop
  if (x == "5") {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}
