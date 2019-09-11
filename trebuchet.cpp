#include <Servo.h>//Servo Bibliothek einbinden
int led=13;//LED an Pin 13
int bewegung=7;//PIR an Pin 7
int bewegungsstatus=0;
Servo ausloeser; //Servo mit ausloeser ansprechen

void setup() {
  pinMode(bewegung, INPUT); //Pin 7 als Input festlegen
  pinMode(led, OUTPUT); //Pin 13 als Output festlegen
  ausloeser.attach(6); //Servo an Pin 6
  ausloeser.write(90); //Servo auf 90 Grad
  delay(10000); //nach 10 Sekunden
  ausloeser.write(148); //Servo auf 148 Grad
  delay(180000); //nach 3 Minuten ist der Auslöser “scharf“, LED leuchtet
  digitalWrite(led, HIGH);
}
void loop() {
  
  bewegungsstatus=digitalRead(bewegung);
  if (bewegungsstatus==HIGH) //Wenn eine Bewegung wahrgenommen wird
  {
  tone(8,100); //Alarmton
  ausloeser.write(90); //Servo auf 90 Grad
  delay(5000); //5 Sekunden warten
  noTone(8); //Ton aus
  
  }
  else //ansonsten
  {
  noTone(8); //kein Ton
  ausloeser.write(148); //Servo auf 148 Grad
  }
  }
