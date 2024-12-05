// Define pin connections
const int pirPin = 2;     // PIR sensor output pin
const int ledPin = 8;     // LED pin
const int buzzerPin = 7; // Buzzer pin

// Variable to store PIR sensor state
int motionDetected = 0;

void setup() {
  pinMode(pirPin, INPUT);    // PIR sensor as input
  pinMode(ledPin, OUTPUT);   // LED as output
  pinMode(buzzerPin, OUTPUT); // Buzzer as output

  Serial.begin(9600); // Initialize serial communication for debugging
  //Serial.println("System Initialized. Waiting for motion...");
}

void loop() {
  // Read the state of the PIR sensor
  motionDetected = digitalRead(pirPin);

  if (motionDetected == HIGH) {
    // Motion detected
    Serial.println("0");
     tone(buzzerPin, 1000);
    
    // Turn on the LED
    digitalWrite(ledPin, HIGH);
    
    // Activate the buzzer
    //digitalWrite(buzzerPin, HIGH);
    delay(500); // Keep the buzzer on for 500ms
    noTone(buzzerPin);

    // Keep the LED on for 2 seconds
    delay(2000); 
    digitalWrite(ledPin, LOW);
  } else {
    // No motion detected
    Serial.println("1");
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
}
