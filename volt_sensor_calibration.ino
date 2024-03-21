const int analogPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float rawVolt1 = analogRead(analogPin);
  delay(1000);
  float rawVolt2 = analogRead(analogPin);
  float avgVolt = (rawVolt1 + rawVolt2) / 2;
  float volt = (avgVolt / 1023.0) * 250.0;
  Serial.println(volt);
  delay(1000);
  Serial.println(volt);
}
