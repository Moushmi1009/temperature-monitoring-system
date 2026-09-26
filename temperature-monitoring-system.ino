#include <LiquidCrystal.h>

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempPin = A0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("Temperature");
  delay(1000);
  lcd.clear();
}

void loop() {

  // Read TMP36 sensor
  int sensorValue = analogRead(tempPin);

  // Convert analog value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Convert voltage to Celsius
  float temperatureC = (voltage - 0.5) * 100.0;

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");

  lcd.setCursor(0, 1);
  lcd.print(temperatureC);
  lcd.print((char)223);
  lcd.print("C   ");

  // Display on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  delay(1000);
}
