#include <Servo.h>
#include <IRremote.h>
#include <Wire.h>
#include <Stepper.h>

//Initialise pins
#define servoPin1 6
#define servoPin2 8
#define servoPin3 7//Continuos rotation
#define servoPin4 4
#define receiverPin 3

//Initialize button codes
#define rightButton1 64 //Button >>|
#define leftButton1 68  //Button |<<
#define rightButton2 24 //Button 2
#define leftButton2 12 //Button 1
#define leftButton3 0x7//Button -
#define rightButton3 0x9//Button EQ
#define leftButton4 66//Button 7
#define rightButton4 82//Button 8
#define sweeperButton 94//  BUtton 3

//Stores the last read data
unsigned long lastRead=0;

//Stores position of servos
int position=0;
int newPosition1=0;
int newPosition2=0;
int newPosition4=0;

int steps=2048;//Total steps for stepper motor to move 360 degrees

int plus=0;//To ensure the motor doesn't over turn, I used a counter to allow it to turn a set amount of times before stopping

//Create servo objects
Servo servo1;
Servo servo2;
Servo servo3;//Continuos rotation
Servo servo4;

Stepper armStepper(steps, 9, 11, 10, 12);//Create stepper object

//Function that returns the new position of a servo based on the signal received
int findPosition(int currentPosition, unsigned long signal){
  //Turns servos right
  if(signal==rightButton1 || signal==rightButton2 || signal==rightButton4){
    if(currentPosition>=0){
      currentPosition-=8;
    } 
  }
  //Turns servos left
  if(signal==leftButton1 || signal==leftButton2 || signal==leftButton4){
    if(currentPosition<=180){
      currentPosition+=8;
    }
  }

  return currentPosition;
}


void setup() {
  //Allow receiver pin to receive signals
  IrReceiver.begin(receiverPin, ENABLE_LED_FEEDBACK);
  
  //Attach servos and bring them to neutral position
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo4.attach(servoPin4);
  servo3.write(90);
  servo1.write(0);
  servo2.write(0);
  servo4.write(0);
  
  //Set stepper motor speed
  armStepper.setSpeed(12);
  
  //Begin serial monitor for position and commmand reading
  Serial.begin(9600);
}

void loop() {

  if(IrReceiver.decode()){
    unsigned long read=IrReceiver.decodedIRData.command;
    
    if(read==0x0){
      //If junk signal, read becomes its last read value
      read=lastRead;
    }else{
      //If new signal, signal is saved in last read
      lastRead=read;
    }

  //Logic for motor control. If plus>3, stop moving.  
  if(plus<5){
    //Servo 1 control
    if(read==rightButton1 || read==leftButton1){
      newPosition1=findPosition(newPosition1, read);
      servo1.write(newPosition1);
    }
    
    //Servo 2 control
    if(read==rightButton2 || read==leftButton2){
      newPosition2=findPosition(newPosition2, read);
      servo2.write(newPosition2);
    }
    
    //Stepper motor control
    if(read==rightButton3){
      armStepper.step(steps/10);
      lastRead=0;
    }
    if(read==leftButton3){
      armStepper.step(-steps/10);
      lastRead=0;
    }

    //Servo 4 control
    if(read==rightButton4){
      newPosition4=findPosition(newPosition4, read);
      servo4.write(newPosition4);
    }
    if(read==leftButton4){
      newPosition4=findPosition(newPosition4, read);
      servo4.write(newPosition4);
    }

    plus++;

  }
  else{
    plus=0;//Reset plus to 0 to begin cycle again
    lastRead=0;
  }
  
  //Statement for movement of continuous rotation servo
  if(read==sweeperButton && read!=leftButton3 && read!=rightButton3){
    servo3.attach(servoPin3);
    servo3.write(50);
    delay(400);

    servo3.write(90);
    delay(150);

    servo3.write(135);
    delay(400);

    servo3.write(90);
    delay(150);

    //Ensure motor does not continuously move after it is done
    lastRead=0;
    servo3.detach();
  }

  //Prints data to serial monitor
   Serial.print("Command: ");
   Serial.println(read);
   Serial.print("--Servo 1 Position: ");
   Serial.println(newPosition1);
   Serial.print("--Serv0 2 Position: ");
   Serial.println(newPosition2);
   Serial.print("--Servo 4 Position: ");
   Serial.println(newPosition4);
   IrReceiver.resume();

  }
  delay(100);
}
