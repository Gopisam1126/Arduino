const int analogPin = A3;
const int cf  = 1;
const int sensitivity = 0.185;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int rc1 = analogRead(analogPin);
  int rc2 = analogRead(analogPin);
  delay(1000);
  int rc3 = analogRead(analogPin);
  int rc4 = analogRead(analogPin);
  float avgVal = (rc1 + rc2 + rc3 + rc4) / 4;
  float current = ((rc1 / 1023.0) * 5.0 - 2.5) / 0.1;
  Serial.println(current);
}
