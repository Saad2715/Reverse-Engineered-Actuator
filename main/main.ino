#include <AccelStepper.h>

// Define Step and Dir pins
#define STEP 6
#define DIR 3

// Create instance
AccelStepper stepper(1, STEP, DIR);

 bool runningTest = true;

void setup() {
  Serial.begin(115200);

  // Set the maximum speed and acceleration
  stepper.setMaxSpeed(100);      // Adjust the maximum speed in steps per second
  stepper.setAcceleration(50);  // Adjust the acceleration in steps per second squared
  
  // Set the initial position of the motor (if needed)
  stepper.setCurrentPosition(0);  // You can set your desired initial position here
}

void loop() {
  // Move the motor a specified number of steps
  // stepper.moveTo(5);  // Move 2000 steps in one direction
  while (runningTest) {
    // Run the stepper motor
    stepper.runToNewPosition(45); // 45 steps move approximately 0.5 mm 

    delay(1000);

    Serial.println("Reading value");
    Serial.println("Value: ");
    Serial.println("Stretching further");
    Serial.println("");

    delay(1000);

    // Run the stepper motor
    stepper.runToNewPosition(45*2);

    delay(1000);

    Serial.println("Reading value");
    Serial.println("Value: ");
    Serial.println("Stretching further");
    Serial.println("");

    delay(1000);

    // Run the stepper motor
    stepper.runToNewPosition(45*3);

    delay(1000);

    Serial.println("Reading value");
    Serial.println("Value: ");
    Serial.println("Stretching further");
    Serial.println("");

    delay(1000);

    // Run the stepper motor
    stepper.runToNewPosition(45*4);

    delay(1000);

    Serial.println("Reading value");
    Serial.println("Value: ");
    Serial.println("Stretching further");
    Serial.println("");

    delay(1000);

    // Run the stepper motor
    stepper.runToNewPosition(45*5);

    delay(1000);

    Serial.println("Reading value");
    Serial.println("Value: ");
    Serial.println("Stretching further");
    Serial.println("");

    delay(1000);

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
