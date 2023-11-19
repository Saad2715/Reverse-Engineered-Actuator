#include <AccelStepper.h>

// Define Step and Dir pins
#define STEP 6
#define DIR 3

// Define pin to take voltage readings from
#define READING A0

// Create instance
AccelStepper stepper(1, STEP, DIR);

bool runningTest = true;
float val, res;

void setup() {
  Serial.begin(9600);

  stepper.setMaxSpeed(100);
  stepper.setAcceleration(50);
  stepper.setCurrentPosition(0);
}

float findResistance(float analogueReading) {
  float Vin = 5.0;            // 5V
  float R1 = 220.0;           // 220 Ohms
  float R2;                   // Variable resistor
  float Vincrement = 0.0049;  // Voltage per unit (5V/1024units)
  float I;                    // Circiut Current

  float Vreading = analogueReading * Vincrement;
  I = (Vin - Vreading) / R1;  // I = Vr1/R1 = (Vin - Vr2)/R1
  R2 = Vreading / I;

  return R2;
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    if (data.equals("start")) {
      Serial.println("Starting experiment in 5 seconds...");
      delay(5000);
      // Add your code to respond to the command here
      while (runningTest) {

        Serial.println("Moving to 0.5mm now --------------------------------------------------------------");
        moveTo0_5();
        delay(3000);

        Serial.println("Moving to 1mm now ----------------------------------------------------------------");
        moveTo1();
        delay(3000);

        Serial.println("Moving to 1.5mm now ----------------------------------------------------------------");
        moveTo1_5();
        delay(3000);

        Serial.println("Moving to 2mm now ----------------------------------------------------------------");
        moveTo2();
        delay(3000);

        Serial.println("Moving to 2.5mm now ----------------------------------------------------------------");
        moveTo2_5();
        delay(3000);

        Serial.println("Moving to 3mm now ----------------------------------------------------------------");
        moveTo3();
        delay(3000);

        Serial.println("Moving to 3.5mm now ----------------------------------------------------------------");
        moveTo3_5();
        delay(3000);

        Serial.println("Moving to 4mm now ----------------------------------------------------------------");
        moveTo4();
        delay(3000);

        Serial.println("Moving to 4.5mm now ----------------------------------------------------------------");
        moveTo4_5();
        delay(3000);

        Serial.println("Moving to 5mm now ----------------------------------------------------------------");
        moveTo5();
        delay(3000);

        Serial.println("Moving to 5.5mm now ----------------------------------------------------------------");
        moveTo5_5();
        delay(3000);

        Serial.println("Moving to 6mm now ----------------------------------------------------------------");
        moveTo6();
        delay(3000);

        Serial.println("Moving to 6.5mm now ----------------------------------------------------------------");
        moveTo6_5();
        delay(3000);

        Serial.println("Moving to 7mm now ----------------------------------------------------------------");
        moveTo7();
        delay(3000);

        Serial.println("Moving to 7.5mm now ----------------------------------------------------------------");
        moveTo7_5();
        delay(3000);

        Serial.println("Moving to 8mm now ----------------------------------------------------------------");
        moveTo8();
        delay(3000);

        Serial.println("Moving to 8.5mm now ----------------------------------------------------------------");
        moveTo8_5();
        delay(3000);

        Serial.println("Moving to 9mm now ----------------------------------------------------------------");
        moveTo9();
        delay(3000);

        Serial.println("Moving to 9.5mm now ----------------------------------------------------------------");
        moveTo9_5();
        delay(3000);

        Serial.println("Moving to 10mm now ----------------------------------------------------------------");
        moveTo10();
        delay(3000);

        Serial.println("finish");

        runningTest = false;
      }

      // stepper.moveTo(-1000);
      // while(stepper.distanceToGo() != 0)
      // {
      //   Serial.println(stepper.currentPosition());
      //   stepper.run();
      //   delay(10);
      // }
      // Serial.println("Processing command...");
      // delay(2000);  // Simulating some processing time
      // Serial.println("Command processed.");
    }
  }
}

void moveTo0_5() {

  // Serial.println("In zero point five");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo1() {

  // Serial.println("In one");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 2);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo1_5() {

  // Serial.println("In one point five");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 3);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo2() {

  // Serial.println("In two");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 4);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo2_5() {

  // Serial.println("In two point five");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 5);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo3() {

  // Serial.println("In three");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 6);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo3_5() {

  // Serial.println("In three point five");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 7);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo4() {

  // Serial.println("In four");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 8);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo4_5() {

  // Serial.println("In four point five");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 9);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo5() {

  // Serial.println("In five");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 10);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo5_5() {

  // Serial.println("In five point five");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 11);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo6() {

  // Serial.println("In six");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 12);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo6_5() {

  // Serial.println("In six point five");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 13);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo7() {

  // Serial.println("In seven");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 14);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo7_5() {

  // Serial.println("In seven point five");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 15);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo8() {

  // Serial.println("In eight");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 16);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo8_5() {

  // Serial.println("In eight point five");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 17);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo9() {

  // Serial.println("In nine");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 18);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo9_5() {

  // Serial.println("In nine point five");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 19);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}

void moveTo10() {

  // Serial.println("In ten");
  // Serial.println("one");
  // Serial.println("two");
  // Serial.println("three");

  stepper.moveTo(-21 * 20);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  delay(3000);

  stepper.moveTo(0);

  while (stepper.distanceToGo() != 0) {
    val = analogRead(READING);
    res = findResistance(val);
    Serial.println(res);
    stepper.run();
  }

  Serial.println("end");
}
