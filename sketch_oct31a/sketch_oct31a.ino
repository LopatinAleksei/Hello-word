int xPin = A0;
int yPin = A1;
int buttonPin = 2;
int xPosition = 0;
int yPosition = 0;
int buttonState = 0;
int mootor=9;
#include <Servo.h>
int pin = 11;
int pos = 0;
Servo servo;

void setup() {
 servo.attach(pin);
  servo.write(pos);
  delay(2000);
Serial.begin(9600);
pinMode(xPin, INPUT);
pinMode(yPin, INPUT);

pinMode(buttonPin, INPUT_PULLUP);

// pinMode(buttonPin, INPUT);
// digitalWrite(buttonPin, HIGH);
}
void loop() {
xPosition = analogRead(xPin);
yPosition = analogRead(yPin);
buttonState = digitalRead(buttonPin);
Serial.print("X: ");
Serial.print(xPosition);
Serial.print(" | Y: ");
Serial.print(yPosition);
Serial.print(" | Button: ");
Serial.println(buttonState);
delay(100); 

if(yPosition < 490){
  Serial.println("Mootor");
  analogWrite(mootor,255);
} else {
  analogWrite(mootor, 0);}

if(xPosition < 300){
 pos = 0;
 } else if (xPosition > 600){  
  pos = 180;
  } else{
    pos = 90;
    }
  
  servo.write(pos);
}
