
#include <SPI.h>
#include <MFRC522.h>

// RFID module pins
#define SS_PIN 10
#define RST_PIN 9

// Flow sensor pin
#define FLOW_SENSOR 2

// Motor driver pins
#define ENA 5
#define IN1 7
#define IN2 8

// LED pins
#define GREEN_LED 3
#define RED_LED 4

// RFID initialization
MFRC522 rfid(SS_PIN, RST_PIN);

// Flow sensor variables
volatile unsigned long pulseCount = 0;
unsigned long lastTime = 0;

float flowRate = 0.0;
float totalLitres = 0.0;

// Replace with your actual RFID card UID
byte authorizedUID[] = {0xDE, 0xAD, 0xBE, 0xEF};

// Motor state
bool pumpOn = false;

// Calibration value (example for YF-S201)
const float pulsesPerLitre = 450.0;

// Count flow sensor pulses
void countPulse() {
  pulseCount++;
}

// Check RFID card
bool checkCard() {
  if (rfid.uid.size != sizeof(authorizedUID)) {
    return false;
  }

  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] != authorizedUID[i]) {
      return false;
    }
  }

  return true;
}

// Stop motor
void stopPump() {
  digitalWrite(ENA, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  pumpOn = false;
}

// Start motor
void startPump() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 180);
  pumpOn = true;
}

void setup() {
  Serial.begin(9600);

  // Initialize RFID
  SPI.begin();
  rfid.PCD_Init();

  // Configure pins
  pinMode(FLOW_SENSOR, INPUT_PULLUP);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  // Initial motor state
  stopPump();

  // Flow sensor interrupt
  attachInterrupt(
    digitalPinToInterrupt(FLOW_SENSOR),
    countPulse,
    FALLING
  );

  Serial.println("IoT Water Flow Monitoring System");
  Serial.println("Scan your RFID card");
}

void loop() {

  // RFID authentication
  if (rfid.PICC_IsNewCardPresent() &&
      rfid.PICC_ReadCardSerial()) {

    if (checkCard()) {
      Serial.println("Authorized Card");

      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(RED_LED, LOW);

      // Toggle pump state
      if (pumpOn) {
        stopPump();
        Serial.println("Water supply stopped");
      } else {
        startPump();
        Serial.println("Water supply started");
      }

    } else {
      Serial.println("Unauthorized Card");

      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);
    }

    delay(1000);

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }

  // Measure water flow every second
  if (millis() - lastTime >= 1000) {

    noInterrupts();
    unsigned long pulses = pulseCount;
    pulseCount = 0;
    interrupts();

    // Calculate flow rate
    flowRate = (pulses / pulsesPerLitre) * 60.0;

    // Calculate total water consumption
    totalLitres += pulses / pulsesPerLitre;

    // Display results
    Serial.print("Flow Rate: ");
    Serial.print(flowRate);
    Serial.println(" L/min");

    Serial.print("Total Water: ");
    Serial.print(totalLitres, 3);
    Serial.println(" L");

    lastTime = millis();
  }
}
