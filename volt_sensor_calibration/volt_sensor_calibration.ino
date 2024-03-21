const int analogPin = A5;
const int cf = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float rawVolt1 = analogRead(analogPin);
  // delay(1000);
  float rawVolt2 = analogRead(analogPin);
  delay(1000);
  float rawVolt3 = analogRead(analogPin);
  float rawVolt4 = analogRead(analogPin);
  float avgVolt = (rawVolt1 + rawVolt2 + rawVolt3 + rawVolt4) / 4;
  float volt = (avgVolt / 1023.0) * 250.0;
  float newVolt = (volt / cf) + 1;
  Serial.println(newVolt);
  // delay(1000);
  // Serial.println(volt);
}
