#include <AccelStepper.h>

// Define Step and Dir pins
#define STEP 6
#define DIR 3

// Define pin to take voltage readings from
#define READING A0

// Create instance
AccelStepper stepper(1, STEP, DIR);

bool runningTest = true;
float res0, res1, res2, res3, res4, res5, res6, res7, res8, res9, res10;

void setup() {
  Serial.begin(115200);
  // while (!Serial.available()) {
  //   ; // Wait for serial to connect
  // }

  pinMode(READING, INPUT);

  // Set the maximum speed and acceleration
  stepper.setMaxSpeed(1000);      // Adjust the maximum speed in steps per second
  stepper.setAcceleration(500);  // Adjust the acceleration in steps per second squared
  
  // Set the initial position of the motor (if needed)
  stepper.setCurrentPosition(0);  // You can set your desired initial position here
}

float findResistance(float analogueReading){
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
  
  while (runningTest) {

    int val0 = analogRead(READING);
    res0 = findResistance(val0);

    Serial.println("Reading inital value");
    Serial.print("Res0: ");
    Serial.println(res0);
    Serial.println("Beginning Stretch");
    Serial.println("");

    delay(5000);

    stepper.runToNewPosition(-21); // 21 steps move approximately 0.5 mm 

    // delay(5000);

    int val1 = analogRead(READING);
    res1 = findResistance(val1);

    Serial.println("Reading 1st increment value");
    Serial.print("Res1: ");
    Serial.println(res1);
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*2);

    // delay(5000);

    int val2 = analogRead(READING);
    res2 = findResistance(val2);

    Serial.println("Reading 2nd increment value");
    Serial.print("Res2: ");
    Serial.println(res2);
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*3);

    // delay(5000);

    int val3 = analogRead(READING);
    res3 = findResistance(val3);

    Serial.println("Reading 3rd increment value");
    Serial.print("Res3: ");
    Serial.println(res3);
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*4);

    // delay(5000);

    int val4 = analogRead(READING);
    res4 = findResistance(val4);

    Serial.println("Reading 4th increment value");
    Serial.print("Res4: ");
    Serial.println(res4);
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*5);

    // delay(5000);

    int val5 = analogRead(READING);
    res5 = findResistance(val5);

    Serial.println("Reading 5th increment value");
    Serial.print("Res5: ");
    Serial.println(res5);
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*6);

    // delay(5000);

    int val6 = analogRead(READING);
    res6 = findResistance(val6);

    Serial.println("Reading 6th increment value");
    Serial.print("Res6: ");
    Serial.println(res6);
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*7);

    // delay(5000);

    int val7 = analogRead(READING);
    res7 = findResistance(val7);

    Serial.println("Reading 7th increment value");
    Serial.print("Res7: ");
    Serial.println(res7);
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*8);

    // delay(5000);

    int val8 = analogRead(READING);
    res8 = findResistance(val8);

    Serial.println("Reading 8th increment value");
    Serial.print("Res8: ");
    Serial.println(res8);
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*9);

    // delay(5000);

    int val9 = analogRead(READING);
    res9 = findResistance(val9);

    Serial.println("Reading 9th increment value");
    Serial.print("Res9: ");
    Serial.println(res9);
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*10);

    // delay(5000);

    int val10 = analogRead(READING);
    res10 = findResistance(val10);

    Serial.println("Reading 10th increment value");
    Serial.print("Res10: ");
    Serial.println(res10);
    Serial.println("5mm total displacement complete");
    Serial.println("");

    delay(5000);

    runningTest = false;

  }

  // // Delay for a while
  // delay(1000);

  // // Move the motor back to the starting position
  // stepper.moveTo(0);
  // stepper.runToPosition();

  // // Delay again
  // delay(1000);

}
