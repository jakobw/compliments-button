#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = ""; // network ssid
const char* password = ""; // network password
const char* url = ""; // url to request on button press

const int buttonPin = D2;

int buttonState = 0;
int previousState = 0;

void setup() {
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to the network");

}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && previousState == LOW) {
    Serial.println ("button pressed");

    HTTPClient http;

    http.begin(url);
    http.GET();
  }

  previousState = buttonState;
}
