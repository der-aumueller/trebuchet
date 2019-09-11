int bewegung=7; //Signal Sensor an Pin 7
int bewegungsstatus=0;
void setup() {
  Serial.begin(9600);

  pinMode(bewegung, INPUT);
}
void loop() {
  bewegungsstatus=digitalRead(bewegung);
  if (bewegungsstatus==HIGH){
  Serial.println("Bewegunsstatus = 1");
  delay(1000);
  }
  else {
  Serial.println("Bewegungsstatus = 0");
  delay(1000);
  }
}
