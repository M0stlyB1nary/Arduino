/*
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 12 Trig to Arduino pin 13
Red POS to Arduino pin 11
Green POS to Arduino pin 10
560 ohm resistor to both LED NEG and GRD power rail
More info at: http://goo.gl/kJ8Gl
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/

int trigPin = 13;
int echoPin = 12;
int Blueled = 11;
int Redled = 10;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(Blueled, OUTPUT);
  pinMode(Redled, OUTPUT);
}

void loop() {
  long duration, inches;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  inches = microsecondsToInches(duration);
  
  if (inches < 6) {  // This is where the LED On/Off happens
    digitalWrite(Blueled,LOW); // When the Red condition is met, the Green LED should turn off
    digitalWrite(Redled,HIGH);
  }
  else if (inches < 12) {
    digitalWrite(Blueled,HIGH);
    digitalWrite(Redled,LOW);
  }
  else {
    digitalWrite(Blueled,LOW);
    digitalWrite(Redled,LOW);
  }
  delay(100);
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}
