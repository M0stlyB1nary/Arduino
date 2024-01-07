#include <AFMotor.h>
#include <Servo.h> 

  AF_DCMotor motorR(1);
  AF_DCMotor motorL(3);
  Servo myservo;
  int pos = 0;    // variable to store the servo position 
  int buttonInput = 0;
  int motorSpeed = 1000;

  #define trigPin 12
  #define echoPin 13


void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);  
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.write(90);
  delay(3000);
}

void loop() {
//  moveNoSensor();  
  

  long duration, distanceFront, distanceLeft, distanceRight, randNumber;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceFront = (duration/2) / 29.1;
  if (distanceFront < 25) {

    myservo.write(45);
    duration = pulseIn(echoPin, HIGH);
    distanceLeft = (duration/2) / 29.1;

      if (distanceLeft > distanceFront)
      {
        turnLeft(300, motorSpeed);
        myservo.write(90);
        delay(500);
        goForward(1000, motorSpeed);   
      }
      else
      {
        myservo.write(135);
        duration = pulseIn(echoPin, HIGH);
        distanceRight = (duration/2) / 29.1;
        if (distanceRight > distanceFront)
        {
          turnRight(300, motorSpeed);
          myservo.write(90);
          delay(500);
          goForward(1000, motorSpeed);
        }
        else
        {
          turnRight(600, motorSpeed);
          myservo.write(90);
          delay(500);
          goForward(1000, motorSpeed);
        }
      } 
  } 
  else {
    goForward(2000, motorSpeed);
    Serial.println("go forward");
  }
    myservo.write(90);
}

  void moveNoSensor(){
      delay(5000);
      goForward(2000, motorSpeed);
      delay(500);
    
      turnRight(500, motorSpeed);
      delay(500);
    
      goForward(2000, motorSpeed);
      delay(500);
    
      turnLeft(500, motorSpeed);
      delay(1000);
    
      sweepServoRight();
      delay(1000);
    
      sweepServoLeft();
      delay(100);
  }

  void sweepServoRight() {
      for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
      {                                  // in steps of 1 degree 
          myservo.write(pos);              // tell servo to go to position in variable 'pos' 
          delay(15);                       // waits 15ms for the servo to reach the position 
      } 
  }

  void sweepServoLeft(){  
    for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                            
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
    } 
  }

  //This will have the robot move forward for 1 second.
  void goForward(int duration, int speedVal){
       motorR.run(FORWARD);
       motorL.run(FORWARD);
       motorR.setSpeed(speedVal);
       motorL.setSpeed(speedVal);
       delay(duration);
  
       motorR.setSpeed(0);
       motorL.setSpeed(0);
  }
  
  //This will have the robot move backward for 1 second.
  void goBackward(int duration, int speedVal){
       motorR.run(BACKWARD);
       motorL.run(BACKWARD);
       motorR.setSpeed(speedVal);
       motorL.setSpeed(speedVal);
       delay(duration);
  
       motorR.setSpeed(0);
       motorL.setSpeed(0);
  }

    //This will have the robot turn Right.
  void turnRight(int duration, int speedVal){
       motorR.run(BACKWARD);
       motorL.run(FORWARD);
       motorR.setSpeed(speedVal);
       motorL.setSpeed(speedVal);
       delay(duration);
  
       motorR.setSpeed(0);
       motorL.setSpeed(0);
  }

    //This will have the robot turnLeft.
  void turnLeft(int duration, int speedVal){
       motorR.run(FORWARD);
       motorL.run(BACKWARD);
       motorR.setSpeed(speedVal);
       motorL.setSpeed(speedVal);
       delay(duration);
  
       motorR.setSpeed(0);
       motorL.setSpeed(0);
  }


