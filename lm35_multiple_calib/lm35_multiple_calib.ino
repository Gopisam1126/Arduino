const int tempPin1 = A3;
const int tempPin2 = A5;
const int cf = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Sensor 1
  float rawTemp1a = analogRead(tempPin1);
  delay(1000);
  float rawTemp2a = analogRead(tempPin1);
  float sensor1 = actVal(rawTemp1a, rawTemp2a);
  float lm35a = sensor1;

  // Sensor 2
  float rawTemp1b = analogRead(tempPin2);
  delay(1000);
  float rawTemp2b = analogRead(tempPin2);
  float lm35b = actVal(rawTemp1b, rawTemp2b);

  // printData
  printData(lm35a, lm35b);
}

float actVal(float s1, float s2) {
  float avg = (s1 + s2) / 2;
  float tempVolt = avg * (5.0 / 1023.0);
  float temp = (tempVolt - 0.5) * 100.0;
  float newTemp = (temp - 11);
  return newTemp;
}

void printData(float v1, float v2) {
  Serial.println("LM35a : ");
  Serial.println(v1);
  Serial.println("\nLM35b : ");
  Serial.println(v2);
}