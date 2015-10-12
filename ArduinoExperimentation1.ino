#include <Arduino.h>
#include "relay_control.h"
#include "DHT.h"
#include "DS2321.h"

//DS3231 Real Time Clock
#include "Wire.h"

//For writing log values to the Arduino's internal memory (EEPROM)
#include "EEPROM.h"
/** the current address in the EEPROM (i.e. which byte we're going to write to next) **/
int addr = 0;
uint8_t light_pin = 7;
uint8_t humidity_pin = 12;
relay_control light_relay(light_pin);
relay_control humidity_control(humidity_pin);
DS2321 clock;

//DHT Sensor
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
    Wire.begin();
    light_relay.begin();
    humidity_control.begin();
    // set the initial time here:
    // DS3231 seconds, minutes, hours, day, date, month, year
    clock.setTime(30,42,21,4,26,11,14);

}

void loop() {
    clock.displayTime();
    light_relay.on();
    humidity_control.off();

    // Wait a few seconds between measurements.
    delay(2000);

    light_relay.off();
    humidity_control.on();

    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float humidity = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float temperature_celsius = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    float temperature_fahrenheit = dht.readTemperature(true);

    // Check if any reads failed and exit early (to try again).
    if (isnan(humidity) || isnan(temperature_celsius) || isnan(temperature_fahrenheit)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    // Compute heat index in Fahrenheit (the default)
    float heat_index_fahrenheit = dht.computeHeatIndex(temperature_fahrenheit, humidity);
    // Compute heat index in Celsius (isFahreheit = false)
    float heat_index_celsius = dht.computeHeatIndex(temperature_celsius, humidity, false);

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(temperature_celsius);
    Serial.print(" *C ");
    Serial.print(temperature_fahrenheit);
    Serial.print(" *F\t");
    Serial.print("Heat index: ");
    Serial.print(heat_index_celsius);
    Serial.print(" *C ");
    Serial.print(heat_index_fahrenheit);
    Serial.println(" *F");

    EEPROM.write(addr, temperature_fahrenheit);
    EEPROM.write(addr+1, temperature_celsius);
    addr = addr + 2;
    if(addr == EEPROM.length())
        addr = 0;
}
