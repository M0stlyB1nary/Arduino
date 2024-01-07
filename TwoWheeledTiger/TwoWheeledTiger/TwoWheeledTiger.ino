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

  

  long distanceFront, distanceLeft, distanceRight, randNumber;


  distanceFront, distanceRight, distanceLeft = 0;
  //Look for straight ahead obstacles. 
  myservo.write(90);
  delay(750);
  distanceFront = findDistance();
  //Serial.println("Front Distance: " + distanceFront);
  
  //Left obstacles
  myservo.write(135);
  delay(750);
  distanceLeft = findDistance();
  //Serial.println("Left Distance: " + distanceLeft);
  
  //Right obstacles
    myservo.write(45);
  delay(750);
  distanceRight = findDistance();

   myservo.write(90);
   delay(500);
        
  if (distanceFront > 0 && distanceRight > 0 && distanceLeft > 0)
  {
  
      if (distanceFront > distanceRight && distanceFront > distanceLeft)
      {            
        //Go Forward
        goForward(2000, motorSpeed);
      }
      else if (distanceRight > distanceLeft && distanceRight > distanceFront)
      {
        turnRight(250, motorSpeed);
        goForward(2000, motorSpeed);
      }
      else if (distanceLeft > distanceRight && distanceLeft > distanceFront)
      {
        turnLeft(250, motorSpeed);
        goForward(2000, motorSpeed);
      }
      else
      {
        goForward(2000, motorSpeed);
      }
  }
  delay(500);
}

 long findDistance()
 {

   long duration = 0;
   long distance = 0;
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(5);
   
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   Serial.println(duration);
   distance = duration/58.2;
   Serial.println("Distance: " + distance);
   return distance;
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


