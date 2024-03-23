#include <SPI.h>
#include <SD.h>

// Pin defenitions

const int VSPin1 = A0;
const int CSPin1 = A1;
const int tempPin1 = A2;
const int VSPin2 = A3;
const int CSPin2 = A4;
const int tempPin2 = A5;

File dataFile; // File object

unsigned long previousMillis = 0;
const long interval = 10 * 60 * 1000; //Time interval for taking values

void setup() {
  Serial.begin(9600);

  // init SD

  if (!SD.begin(SS)) {
    Serial.println("SD card initialization failed!");
    return;
  }
  Sesrial.println("SD card initilizd Successfully.");
}

void loop() {
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // open data.txt

    dataFile = SD.open("data.txt", FILE_WRITE);

    if (dataFile) {
      
      float v1 = readVoltage(VSPin1);
      float v2 = readVoltage(VSPin2);
      float c1 = readCurrent(CSPin1);
      float c2 = readCurrent(CSPin2);
      float t1 = readTemp(tempPin1);
      float t2 = readTemp(tempPin2);

      // print data to Serial Monitor

      Serial.println("\nData Set 1 : \t");
      printData(v1, c1, t1);

      Serial.println("\nData Set 2 : \t");
      printData(v2, c2, t2);

      // write data to data.txt
      dataFile.print("Data Set 1 : \n");
      dataFile.print("Voltage 1 : ");
      dataFile.print(v1);
      dataFile.print("\n");
      dataFile.print("Current 1 : ");
      dataFile.print(c1);
      dataFile.print("\n");
      dataFile.print("Temperature 1 : ");
      dataFile.print(t1);
      dataFile.print("\n\n");
      dataFile.print("Data Set 2 : \n");
      dataFile.print("Voltage 2 : ");
      dataFile.print(v2);
      dataFile.print("\n");
      dataFile.print("Current 2 : ");
      dataFile.print(c2);
      dataFile.print("\n");
      dataFile.print("Temperature 2 : ");
      dataFile.println(t2);
      dataFile.println("\n\n");

      dataFile.close(); //close data.txt

    } else {
      Serial.println("Error opening data.txt!");
    }
  }

  delay(1000); //prevent excessive logging

}

float readVoltage(int sensorPin) {
  float rawVolt1 = analogRead(sensorPin);
  delay(2000);
  float rawVolt2 = analogRead(sensorPin);
  float avgVolt = (rawVolt1 + rawVolt2) / 2.0;
  float volt =  (avgVolt / 1023.0) * 250.0;
  return volt;
}

float readCurrent(int sensorPin) {
  float rawCurrent1 = analogRead(sensorPin);
  delay(2000);
  float rawCurrent2 = analogRead(sensorPin);
  float avgCurrent = (rawCurrent1 + rawCurrent2) / 2.0;
  float current = ((avgCurrent / 1023.0) * 5.0 - 2.5) / 0.1;
  return current;
}

float readTemp(int sensorPin) {
  float rawTemp1 = analogRead(sensorPin);
  delay(2000);
  float rawTemp2 = analogRead(sensorPin);
  float avgTemp = (rawTemp1 + rawTemp2) / 1.7;
  float tempVolt = avgTemp * (5.0 / 1023.0);
  float temp = (tempVolt - 0.5) * 100.0;
  return temp;
}

void printData(float volt, float current, float temp) {

  Serial.print("\tVoltage : ");
  Serial.print(volt);
  Serial.print(" V\t");

  Serial.print("Current : ");
  Serial.print(current);
  Serial.print(" A\t");

  Serial.print("Temperature : ");
  Serial.print(temp);
  Serial.print(" °C\t");

}