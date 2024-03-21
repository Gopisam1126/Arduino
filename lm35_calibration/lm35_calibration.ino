const int tempPin = A0;
const int cf = 1.2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float rawTemp1 = analogRead(tempPin);
  delay(2000);
  float rawTemp2 = analogRead(tempPin);
  float avgTemp = (rawTemp1 + rawTemp2) / 1.7;
  float tempVolt = avgTemp * (5.0 / 1023.0);
  float temp = (tempVolt - 0.5) * 100.0;
  float newTemp = temp - 11;

  Serial.println(newTemp);
  delay(2000);
  Serial.println(newTemp);
}