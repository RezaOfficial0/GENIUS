#include <Arduino.h>
#include <Servo.h>

// Define pin connections
#define ARM_RPWM 3
#define ARM_LPWM 4
#define ARM_R_EN 22
#define ARM_L_EN 23



#define FL_RPWM 5
#define FL_LPWM 6
#define FL_L_EN 24
#define FL_R_EN 25

#define FR_RPWM 7
#define FR_LPWM 8
#define FR_R_EN 26
#define FR_L_EN 27

#define RL_RPWM 9
#define RL_LPWM 10
#define RL_R_EN 28
#define RL_L_EN 29

#define RR_RPWM 11
#define RR_LPWM 12
#define RR_R_EN 30
#define RR_L_EN 31

Servo sg90;
#define Gripper 13
int gripQuality = 0; 
void setup() {
  Serial.begin(9600);
  // Set pin modes
  pinMode(ARM_RPWM, OUTPUT);
  pinMode(ARM_LPWM, OUTPUT);
  pinMode(ARM_R_EN, OUTPUT);
  pinMode(ARM_L_EN, OUTPUT);

  pinMode(FL_RPWM, OUTPUT);
  pinMode(FL_LPWM, OUTPUT);
  pinMode(FL_R_EN, OUTPUT);
  pinMode(FL_L_EN, OUTPUT);

  pinMode(FR_RPWM, OUTPUT);
  pinMode(FR_LPWM, OUTPUT);
  pinMode(FR_R_EN, OUTPUT);
  pinMode(FR_L_EN, OUTPUT);

  pinMode(RL_RPWM, OUTPUT);
  pinMode(RL_LPWM, OUTPUT);
  pinMode(RL_R_EN, OUTPUT);
  pinMode(RL_L_EN, OUTPUT);

  pinMode(RR_RPWM, OUTPUT);
  pinMode(RR_LPWM, OUTPUT);
  pinMode(RR_R_EN, OUTPUT);
  pinMode(RR_L_EN, OUTPUT);

 
  digitalWrite(ARM_R_EN, HIGH);
  digitalWrite(ARM_L_EN, HIGH);

   digitalWrite(FL_R_EN, HIGH);
  digitalWrite(FL_L_EN, HIGH);

     digitalWrite(FR_R_EN, HIGH);
  digitalWrite(FR_L_EN, HIGH);

     digitalWrite(RL_R_EN, HIGH);
  digitalWrite(RL_L_EN, HIGH);

     digitalWrite(RR_R_EN, HIGH);
  digitalWrite(RR_L_EN, HIGH);

  // Set initial state
  analogWrite(ARM_RPWM, 0);   
  analogWrite(ARM_LPWM, 0);    
  analogWrite(FL_RPWM, 0);   
  analogWrite(FL_LPWM, 0);  
    analogWrite(FR_RPWM, 0);   
  analogWrite(FR_LPWM, 0);  
    analogWrite(RL_RPWM, 0);   
  analogWrite(RL_LPWM, 0);  
    analogWrite(RR_RPWM, 0);   
  analogWrite(RR_LPWM, 0);  

  sg90.attach(Gripper);

}










//Drivetrain Commands


void ARMRotateUp(){
analogWrite(ARM_RPWM, 120);  
  analogWrite(ARM_LPWM, 0);    
  delay(1000); 
  analogWrite(ARM_RPWM, 0);  
  analogWrite(ARM_LPWM, 0);    
  delay(1000); 
}

void ARMRotateDown(){
analogWrite(ARM_RPWM, 0);  
  analogWrite(ARM_LPWM, 80);    
  delay(1000); 

}

void moveForward() {
  analogWrite(FL_RPWM, 100);  
  analogWrite(FL_LPWM, 0);    
   analogWrite(FR_RPWM, 100);  
  analogWrite(FR_LPWM, 0);   
   analogWrite(RL_RPWM, 100);  
  analogWrite(RL_LPWM, 0);   
   analogWrite(RR_RPWM, 100);  
  analogWrite(RR_LPWM, 0);   
            
}
void moveBackward() {
  analogWrite(FL_RPWM, 0);  
  analogWrite(FL_LPWM, 100);    
   analogWrite(FR_RPWM, 0);  
  analogWrite(FR_LPWM, 100);   
   analogWrite(RL_RPWM, 0);  
  analogWrite(RL_LPWM, 100);   
   analogWrite(RR_RPWM, 0);  
  analogWrite(RR_LPWM, 100);   
            
}


void RotationR(){
  analogWrite(FL_RPWM, 100);  
  analogWrite(FL_LPWM, 0);    
   analogWrite(FR_RPWM, 0);  
  analogWrite(FR_LPWM, 100);   
   analogWrite(RL_RPWM, 100);  
  analogWrite(RL_LPWM, 0);   
   analogWrite(RR_RPWM, 0);  
  analogWrite(RR_LPWM, 100);   
}

void RotationL(){
    analogWrite(FL_RPWM, 0);  
  analogWrite(FL_LPWM, 100);    
   analogWrite(FR_RPWM, 100);  
  analogWrite(FR_LPWM, 0);   
   analogWrite(RL_RPWM, 0);  
  analogWrite(RL_LPWM,100);   
   analogWrite(RR_RPWM,100);  
  analogWrite(RR_LPWM, 100);  
}

void StopMove(){
    analogWrite(FL_RPWM, 0);  
  analogWrite(FL_LPWM, 0);    
   analogWrite(FR_RPWM, 0);  
  analogWrite(FR_LPWM, 0);   
   analogWrite(RL_RPWM, 0);  
  analogWrite(RL_LPWM, 0);   
   analogWrite(RR_RPWM, 0);  
  analogWrite(RR_LPWM, 0);   
  
}
void GrippT(){
for (pos = 0; pos <= 180; pos += 1)
{
sg90.write(pos);
delay(15);
}
}
void GrippF(){
for (pos = 180; pos >= 0; pos -= 1)
{
sg90.write(pos);
delay(15);
} 
}



void InputController(){
  if (Serial.available() > 0) {
    // Read the incoming data as a string
    String command = Serial.readStringUntil('\n');  // Read the command until newline

    // Execute the command if it matches
    if (command == "ARMRotateUp();") {
      // Call the function you want to trigger
      ARMRotateUp();
    }
     if (command == "ARMRotateDown();") {
      ARMRotateDown();
    }
      if (command == "MoveForward();") {
      moveForward();
    }
      if (command == "RotationR();") { 
      RotationR();
    }
       if (command == "RotationL();") {
       RotationL();
    }
  }
}


void loop() {
 //InputController();


}