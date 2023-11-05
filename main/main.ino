#include <AccelStepper.h>

// Define Step and Dir pins
#define STEP 6
#define DIR 3

// Define pin to take voltage readings from
#define READING A0

// Create instance
AccelStepper stepper(1, STEP, DIR);

bool runningTest = true;

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

void loop() {
  
  while (runningTest) {
    // Run the stepper motor
    // stepper.runToNewPosition(-22); // 22 steps move approximately 0.5 mm 

    // delay(10000);

    Serial.println("Reading inital value");
    Serial.print("Value: ");
    Serial.println(analogRead(READING));
    Serial.println("Beginning Stretch");
    Serial.println("");

    delay(5000);

    stepper.runToNewPosition(-21); // 21 steps move approximately 0.5 mm 

    // delay(5000);

    Serial.println("Reading 1st increment value");
    Serial.print("Value: ");
    Serial.println(analogRead(READING));
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*2);

    // delay(5000);

    Serial.println("Reading 2nd increment value");
    Serial.print("Value: ");
    Serial.println(analogRead(READING));
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*3);

    // delay(5000);

    Serial.println("Reading 3rd increment value");
    Serial.print("Value: ");
    Serial.println(analogRead(READING));
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*4);

    // delay(5000);

    Serial.println("Reading 4th increment value");
    Serial.print("Value: ");
    Serial.println(analogRead(READING));
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*5);

    // delay(5000);

    Serial.println("Reading 5th increment value");
    Serial.print("Value: ");
    Serial.println(analogRead(READING));
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*6);

    // delay(5000);

    Serial.println("Reading 6th increment value");
    Serial.print("Value: ");
    Serial.println(analogRead(READING));
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*7);

    // delay(5000);

    Serial.println("Reading 7th increment value");
    Serial.print("Value: ");
    Serial.println(analogRead(READING));
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*8);

    // delay(5000);

    Serial.println("Reading 8th increment value");
    Serial.print("Value: ");
    Serial.println(analogRead(READING));
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*9);

    // delay(5000);

    Serial.println("Reading 9th increment value");
    Serial.print("Value: ");
    Serial.println(analogRead(READING));
    Serial.println("Stretching further");
    Serial.println("");

    delay(5000);

    // Run the stepper motor
    stepper.runToNewPosition(-21*10);

    // delay(5000);

    Serial.println("Reading 10th increment value");
    Serial.print("Value: ");
    Serial.println(analogRead(READING));
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
