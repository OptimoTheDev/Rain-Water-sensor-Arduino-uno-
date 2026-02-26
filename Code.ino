// Pin definitions
#define RAIN_ANALOG_PIN A0   // A0 from rain sensor
#define RAIN_DIGITAL_PIN 2   // D0 / DQ from rain sensor
#define BUZZER_PIN 8         // Buzzer +

int threshold = 500;  // Adjust after checking Serial Monitor

void setup() {
  pinMode(RAIN_DIGITAL_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);

  Serial.begin(9600); // For debugging
}

void loop() {
  int analogValue = analogRead(RAIN_ANALOG_PIN);
  int digitalValue = digitalRead(RAIN_DIGITAL_PIN);

  // Debug output
  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(" | Digital: ");
  Serial.println(digitalValue);

  /*
    Most rain sensors:
    - D0/DQ = LOW  → rain detected
    - A0 value decreases when wet
  */
  if (digitalValue == LOW && analogValue < threshold) {
    digitalWrite(BUZZER_PIN, HIGH);  // BUZZER ON
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // BUZZER OFF
  }

  delay(200);
}
