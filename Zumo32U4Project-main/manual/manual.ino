#include <Zumo32U4.h>


String data;
char dl;

enum State {
  pause_state,
  run_state
};



const int motorSpeed = 150;
const int motorSpeeds = 75;







Zumo32U4LCD lcd;
Zumo32U4LineSensors lineSensors;
unsigned int lineSensorValues[3];
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4ProximitySensors proxSensors;
State state = pause_state;
Zumo32U4Buzzer buzzer;

void setup() {

  lineSensors.initThreeSensors();
  lineSensors.emittersOn();
  proxSensors.initThreeSensors();
    Serial.begin(9600);  
}

void loop() {
if(Serial.available()){
data = Serial.readString();  
dl = data.charAt(0);
if(dl == 'F'){
   
    motors.setSpeeds(motorSpeeds, motorSpeeds);
}
else if(dl == 'B'){
  motors.setSpeeds(-motorSpeeds, -motorSpeeds);    
}
else if(dl == 'L'){
  motors.setSpeeds(-motorSpeeds, motorSpeeds);    
}
else if(dl == 'R'){
  motors.setSpeeds(motorSpeeds, -motorSpeeds);    
}
}

}