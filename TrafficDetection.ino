const int redLightPin = 12;   // Red LED connected to GPIO 23
const int yellowLightPin = 14; // Yellow LED connected to GPIO 22
const int greenLightPin = 21;  // Green LED connected to GPIO 21
const int buttonPin = 19;      // Pedestrian crossing button connected to GPIO 19

bool pedestrianRequest = false;  // Tracks pedestrian button press

void setup() {
  // Initialize the LED pins as outputs
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);

  // Set the button pin as input
  pinMode(buttonPin, INPUT_PULLUP);  // Enable internal pull-up resistor

  // Initial state of traffic lights
  digitalWrite(redLightPin, HIGH);  // Start with red light
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(greenLightPin, LOW);
}

void loop() {
  // Check if pedestrian button is pressed
  if (digitalRead(buttonPin) == LOW) {
    pedestrianRequest = true;  // Set flag for pedestrian crossing request
  }

  // Regular traffic light sequence
  if (!pedestrianRequest) {
    // Red Light ON for 5 seconds
    digitalWrite(redLightPin, HIGH);
    digitalWrite(yellowLightPin, LOW);
    digitalWrite(greenLightPin, LOW);
    delay(5000);

    // Green Light ON for 5 seconds
    digitalWrite(redLightPin, LOW);
    digitalWrite(yellowLightPin, LOW);
    digitalWrite(greenLightPin, HIGH);
    delay(5000);

    // Yellow Light ON for 2 seconds
    digitalWrite(redLightPin, LOW);
    digitalWrite(yellowLightPin, HIGH);
    digitalWrite(greenLightPin, LOW);
    delay(2000);
  } else {
    // Pedestrian crossing logic
    pedestrianCrossing();
    pedestrianRequest = false;  // Reset the pedestrian request
  }
}

void pedestrianCrossing() {
  // Stop traffic by turning on red light
  digitalWrite(redLightPin, HIGH);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(greenLightPin, LOW);
  delay(5000);  // Keep red light on for pedestrian to cross
  
  // Flash yellow light to warn
  for (int i = 0; i < 5; i++) {
    digitalWrite(yellowLightPin, HIGH);
    delay(500);
    digitalWrite(yellowLightPin, LOW);
    delay(500);
  }
}
