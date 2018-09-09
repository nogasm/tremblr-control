/*
Example sketch to remotely control the Tremblr speed using a 315MHz transmitter
You can't directly set the speed, but can send "faster" and "slower" commands
*/

#include <RCSwitch.h>

//Signals for each button on the remote control
#define RC_UP 16076992
#define RC_MID 16076812
#define RC_DOWN 16076848
#define RC_LEFT 16076803
#define RC_RIGHT 16077568

RCSwitch mySwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #14  
  mySwitch.enableTransmit(14);
}


void loop() {
  //Ramp up the speed
  for(int i = 0; i < 15; i++){
    mySwitch.send(RC_UP, 24);
    delay(50);
  }
  
  //Stop the tremblr. By default, the speed remains unchanged when started again.
  mySwitch.send(RC_MID, 24);
  delay(50);

  //Reduce the speed to minimum while stopped.
  for(int i = 0; i < 15; i++){
    mySwitch.send(RC_DOWN, 24);
    delay(50);
  }

  
  delay(50);
  //Start the tremblr again.
  mySwitch.send(RC_MID, 24);
}
