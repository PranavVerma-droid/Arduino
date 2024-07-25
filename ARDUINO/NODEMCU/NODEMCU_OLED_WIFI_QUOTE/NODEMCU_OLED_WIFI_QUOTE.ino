#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266HTTPClient.h>

// Replace these with your WiFi credentials
const char* ssid = "Airtel Lockdown";
const char* password = "11234567";

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* api_key = "kVk3d2MNQeJK21KzPxSwvg==31H8zNnO62RE6qdj";
//const char* category = "happiness";
const char* api_url = "https://api.api-ninjas.com/v1/quotes?category=happiness";

unsigned long last_fetch_time = 0;
const unsigned long fetch_interval = 24 * 60 * 60 * 1000; // Fetch quote every 24 hours

void setup() {
  Serial.begin(115200);
  delay(100); // Delay to allow time for serial monitor to initialize

  Serial.println("Initializing...");

  // Initialize OLED display with I2C address 0x3C
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  Serial.println("OLED initialized");

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Connecting to Wifi:");
  display.println(ssid);
  display.display();
 
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    display.print(".");
    display.display();
  }
  Serial.println("\nWiFi connected!");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Connected to Wifi.");
  display.println("Setup Complete.");
  display.println("Made by:");
  display.println("PranavVerma-droid.");
  display.display();
  Serial.println("Setup complete");
  delay(4000);

  
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Initializing Data");
  display.display();
  delay(1000);
  display.println("Data Initialized.");
  display.display();
  delay(1000);

  fetchQuote();
}

void loop() {
  unsigned long current_time = millis();
  if (current_time - last_fetch_time >= fetch_interval) {
    fetchQuote();
    last_fetch_time = current_time;
  }

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Waiting...");
  display.display();
  delay(1000); // Add a delay to reduce screen flicker
}

void fetchQuote() {
  WiFiClient client; // Create a WiFiClient object
  
  HTTPClient http;
  http.begin(client, api_url); // Use begin(WiFiClient, url) instead
  
  http.addHeader("X-Api-Key", api_key);
  
  int httpCode = http.GET();
  Serial.println(httpCode);
  if (httpCode == HTTP_CODE_OK) {
    String payload = http.getString();
    Serial.println(payload);

    // Parse the JSON payload and extract the quote
    // Display the quote on the OLEDscreen
    // You'll need to implement JSON p arsing and OLED display code here
  } else {
    Serial.println("Error fetching quote");
  }

  http.end();
}
