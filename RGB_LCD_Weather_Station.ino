#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define DHTPIN 2
#define DHTTYPE DHT22

int redPin = 6;
int greenPin = 5;
int bluePin = 3;

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Error Check
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor error!");

    delay(2000);
    return;
  }


  // Serial
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %\t");


  // LCD
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Temp");
  lcd.setCursor(10, 0);
  lcd.print(t, 1);   // 1 tizedes
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity");
  lcd.setCursor(10, 1);
  lcd.print(h, 1);
  lcd.print("%");


  // RGB LED
  if (t <= 0) {
    // Fagy: Fehér
    setColor(255, 255, 255);
  }
  else if (t > 0 && t <= 18) {
    // Hideg: Kék
    setColor(0, 0, 255);
  }
  else if (t > 18 && t <= 25) {
    // Ideális: Zöld
    setColor(0, 255, 0);
  }
  else if (t > 25 && t <= 30) {
    // Meleg: Narancs
    setColor(255, 100, 0);
  }
  else {
    // Hőség: Piros
    setColor(255, 0, 0);
  }

  delay(2000);
}

void setColor (int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}