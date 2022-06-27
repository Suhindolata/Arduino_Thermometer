
#include <LiquidCrystal.h>
#include "DHT.h"

// set the DHT Pin
#define DHTPIN 2

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  dht.begin();
  lcd.print("");
}

void loop() {
  delay(2000);
  lcd.clear();
  
  // read humidity
  int h = dht.readHumidity();
  //read temperature in Celsius
  float t = dht.readTemperature();
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  if (isnan(h) || isnan(t) || isnan(hic)) {
    lcd.print("ERROR");
    return;
  }
  
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(t);
  lcd.print("C");
  lcd.setCursor(9,0);
  lcd.print("Hum:");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("HI:");
  lcd.print(hic);
  lcd.print("C");
}
