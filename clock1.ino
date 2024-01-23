#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 rtc;

int newHour = 0;
int newMinute = 0;
int newSecond = 0;


void setup() {

  Serial.begin(9600);
  Wire.begin();
  rtc.begin();

  // Установка времени по умолчанию
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

}

void loop() {
  // Считывание нового времени из Serial Monitor
  if (Serial.available()) {
    newHour = Serial.parseInt();
    newMinute = Serial.parseInt();
    newSecond = Serial.parseInt();

    // Установка нового времени
    rtc.adjust(DateTime(rtc.now().year(), rtc.now().month(), rtc.now().day(), newHour, newMinute, newSecond));
  }

  // Вывод текущего времени
  DateTime now = rtc.now();
  Serial.print("Текущее время: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.print(now.second());
  Serial.println();

  delay(1000);

}
