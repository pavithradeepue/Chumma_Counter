#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// WiFi Credentials
const char* ssid = "Redacted";
const char* password = "Redacted";

// Firebase Settings (use your actual DB URL and token)
const char* firebaseHost = "Redacted";  // End with .json
const char* firebaseAuth = "Redacted";  

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Button pins
const int incPin = 15;     // Increment
const int decPin = 18;    // Decrement
const int confPin = 4;   // Confirm

// Counter state
int counter;
bool confirmed = false;

void connectWiFi() {
  display.clearDisplay();
  display.setCursor(0, 20);
  display.setTextSize(1);
  display.println("Connecting to WiFi...");
  display.display();

  WiFi.begin(ssid, password);
  int retry = 0;
  while (WiFi.status() != WL_CONNECTED && retry < 20) {
    delay(500);
    Serial.print(".");
    retry++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi connected!");
  } else {
    Serial.println("WiFi failed.");
    display.clearDisplay();
    display.setCursor(0, 20);
    display.print("WiFi Failed");
    display.display();
    while (true);  // Halt
  }
}

void fetchInitialCounter() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // If auth is required, append token
    String url = String(firebaseHost);  // already ends with .json
    // Uncomment if needed:
    // url += "?auth=" + String(firebaseAuth);

    http.begin(url);
    int httpCode = http.GET();

    if (httpCode == 200) {
      String response = http.getString();
      Serial.print("Fetched initial value: ");
      Serial.println(response);
      counter = response.toInt();  // if value is a raw integer
    } else {
      Serial.print("Failed to fetch initial value, HTTP code: ");
      Serial.println(httpCode);
    }

    http.end();
  }
}


void sendToFirebase(int count) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = String(firebaseHost) + "?auth=" + firebaseAuth;
    String payload = String(count);

    http.begin(url);
    http.addHeader("Content-Type", "application/json");

    int httpCode = http.PUT(payload);  // Use PUT to overwrite
    if (httpCode > 0) {
      String response = http.getString();
      Serial.println("Firebase updated: " + response);
    } else {
      Serial.println("Error sending to Firebase: " + http.errorToString(httpCode));
    }

    http.end();
  }
}

void setup() {
  Serial.begin(115200);

  // Initialize buttons
  pinMode(incPin, INPUT);
  pinMode(decPin, INPUT);
  pinMode(confPin, INPUT);

  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Chumma");
  display.println("Counter");
  display.display();
  delay(2000);


  connectWiFi();
  fetchInitialCounter(); 
  updateDisplay();
}

void loop() {
  static unsigned long lastDebounceTime = 0;
  static int lastIncState = HIGH;
  static int lastDecState = HIGH;
  static int lastConfState = HIGH;

  int incState = digitalRead(incPin);
  int decState = digitalRead(decPin);
  int confState = digitalRead(confPin);

  if (millis() - lastDebounceTime > 200) {
    if (incState == LOW && lastIncState == HIGH) {
      counter++;
      confirmed = false;
      updateDisplay();
      lastDebounceTime = millis();
    }

    if (decState == LOW && lastDecState == HIGH) {
      counter--;
      confirmed = false;
      updateDisplay();
      lastDebounceTime = millis();
    }

    if (confState == LOW && lastConfState == HIGH) {
      confirmed = true;
      sendToFirebase(counter);
      updateDisplay();
      lastDebounceTime = millis();
    }
  }

  lastIncState = incState;
  lastDecState = decState;
  lastConfState = confState;
}

void updateDisplay() {
  display.clearDisplay();
  display.setCursor(0, 10);
  display.setTextSize(1);
  display.print("Pages read:");
  display.setTextSize(2);
  display.setCursor(0, 30);
  display.println(counter);

  if (confirmed) {
    display.setTextSize(1);
    display.setCursor(0, 55);
    display.println(">> Confirmed <<");
  }

  display.display();
}
