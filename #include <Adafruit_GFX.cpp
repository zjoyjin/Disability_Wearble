#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>

// Define pins for the color OLED display
#define sclk 13  
#define mosi 11  
#define cs   10  
#define rst  9   
#define dc   8   

// Create an instance of the SSD1331 display
Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, mosi, sclk, rst);

// Pin definitions
const int soundSensorPin = 0; // Sound sensor connected to A0
const int buzzerPin = 3;      // Buzzer connected to D3

// Colors for the OLED display
#define BLACK   0x0000
#define RED     0xF800
#define GREEN   0x07E0
#define BLUE    0x001F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("in setup");



  printf("1");

  //Initialize the color OLED display
  display.begin();
  display.fillScreen(BLACK); // Clear the screen with black
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("System Ready!");
  printf("2");
 

  //Set pin modes
  pinMode(soundSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  Serial.println("in loop");
  int soundValue = digitalRead(soundSensorPin); // Read digital value from the sound sensor

  if (soundValue == HIGH) { // Sound detected
    // Fire alarm (example: continuous sound)
    display.fillScreen(RED); // Fill the screen with red
    display.setCursor(0, 0);
    display.println("Fire Alarm!");
    tone(buzzerPin, 1000); // Buzzer sound
    delay(100); // Wait for 1 second
    noTone(buzzerPin); 
    Serial.println("first bug");

    // Door knock (example: short sound)
    display.fillScreen(GREEN); 
    display.setCursor(0, 0);
    display.println("Door Knock!");
    tone(buzzerPin, 500); 
    delay(5000); 
    noTone(buzzerPin); 
    //printf("4");

    display.fillScreen(BLACK);
  }
}