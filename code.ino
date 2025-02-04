#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#define LED_PIN_1 4
#define LED_PIN_2 5
#define EXT_LED_PIN 12
#define BUZZER_PIN 2
Adafruit_MPU6050 mpu;
void setup() {
Serial.begin(115200);
pinMode(LED_PIN_1, OUTPUT);
pinMode(LED_PIN_2, OUTPUT);
pinMode(EXT_LED_PIN, OUTPUT);
pinMode(BUZZER_PIN, OUTPUT);
if (!mpu.begin()) {
Serial.println("Failed to find MPU6050 chip");
while (1) {
delay(10);
}}
Serial.println("MPU6050 Found!");]
void loop() {
sensors_event_t accel;
mpu.getEvent(&accel);
float magnitude = sqrt(pow(accel.acceleration.x, 2) +
pow(accel.acceleration.y, 2) + pow(accel.acceleration.z, 2));
if (magnitude > 9.78) {
Serial.println("Fall Detected!");
digitalWrite(LED_PIN_1, HIGH);
digitalWrite(LED_PIN_2, HIGH);
digitalWrite(EXT_LED_PIN, HIGH);
tone(BUZZER_PIN, 1000);
delay(1000);
noTone(BUZZER_PIN);
delay(5000);
digitalWrite(LED_PIN_1, LOW);
digitalWrite(LED_PIN_2, LOW);
digitalWrite(EXT_LED_PIN, LOW);
}
delay(100);
}