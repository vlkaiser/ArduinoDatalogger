#include <Arduino.h>

#include <datasaveSD.h>
#include <LCDTFT.h>
#include <rtc.h>
#include <SHT40.h>
#include <main.h>

void setup() 
{
  pinMode(errorLED,OUTPUT);
  pinMode(writeLED,OUTPUT);

  pinMode(chipSelect, OUTPUT);

  Serial.begin(57600);        // Config platformio.ini to same baud for serial monitor
  while (!Serial);            // wait for serial port to connect. Needed for native USB

  digitalWrite(writeLED, LOW);
  digitalWrite(errorLED, LOW);
  digitalWrite(chipSelect, LOW);

  // Initialize Devices
  initRTXC();

}

void loop() 
{
  // put your main code here, to run repeatedly:
  Serial.print("Initializing...\n");

  digitalWrite(writeLED, HIGH);

  /*****************
   *  Timestamp:
   * ***************/
  String dataCollected = "";
  DateTime now = rtc.now();

  dataCollected += String(now.hour(), DEC);
  dataCollected += String(':');
  dataCollected += String(now.minute(), DEC);
  dataCollected += String(':');
  dataCollected += String(now.second(), DEC);
  dataCollected += csv;

  Serial.print("Timestamp: ");
  Serial.println(dataCollected);
  
  /*******/
  digitalWrite(errorLED, HIGH);
  delay(500);
  digitalWrite(writeLED, LOW);
  digitalWrite(errorLED, LOW);
  delay(500);

}