// Define the PIR sensor pin
int pirSensorPin = 2;
// Define the LED pin
int ledPin = 13;

// Variable to store the count
int motionCount = 0;

// Variable to store the previous state of the PIR sensor
int prevPirState = LOW;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set the PIR sensor pin as an input
  pinMode(pirSensorPin, INPUT);

  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the current state of the PIR sensor
  int pirState = digitalRead(pirSensorPin);

  // Check if the state of the PIR sensor has changed
  if (pirState != prevPirState) {
    // If motion is detected, increment the count and turn on the LED
    if (pirState == HIGH) {
      motionCount++;
      Serial.println("Motion detected! Count: " + String(motionCount));
      digitalWrite(ledPin, HIGH); // Turn on the LED
    } else {
      digitalWrite(ledPin, LOW); // Turn off the LED when motion stops
    }

    // Update the previous state
    prevPirState = pirState;
  }
}
