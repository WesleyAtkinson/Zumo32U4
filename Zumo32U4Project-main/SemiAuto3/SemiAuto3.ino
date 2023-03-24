String data;
char dl;
#include <Zumo32U4.h>

enum State {
  pause_state,
  run_state
};


const int motorSpeed = 150;
const int motorSpeeds = 75;
const int pin = 200;
unsigned long previousMillis = 0;  
const long period = 6000;  
const char fugue[] PROGMEM =
  "! O5 L16 agafaea dac+adaea fa<aa<bac#a dac#adaea f"
  "O6 dcd<b-d<ad<g d<f+d<gd<ad<b- d<dd<ed<f+d<g d<f+d<gd<ad"
  "L8 MS <b-d<b-d MLe-<ge-<g MSc<ac<a ML d<fd<f O5 MS b-gb-g"
  "ML >c#e>c#e MS afaf ML gc#gc# MS fdfd ML e<b-e<b-"
  "O6 L16ragafaea dac#adaea fa<aa<bac#a dac#adaea faeadaca"
  "<b-acadg<b-g egdgcg<b-g <ag<b-gcf<af dfcf<b-f<af"
  "<gf<af<b-e<ge c#e<b-e<ae<ge <fe<ge<ad<fd"
  "O5 e>ee>ef>df>d b->c#b->c#a>df>d e>ee>ef>df>d"
  "e>d>c#>db>d>c#b >c#agaegfe f O6 dc#dfdc#<b c#4";
const int blackColor = 600;

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

  lineSensors.read(lineSensorValues);

  
  bool buttonPress = buttonA.getSingleDebouncedPress();

  
  if(buttonPress && state == pause_state) {
    state = run_state;
  }

  else if(buttonPress && state == run_state) {
    state = pause_state;
  }

  
  if(state == run_state) {
    unsigned long currentMillis = millis(); 
    
 
    if(lineSensorValues[0] > blackColor && lineSensorValues[2] > blackColor) {
            state = pause_state;    
      
    }
    else if(lineSensorValues[0] > blackColor && lineSensorValues[2] < blackColor) {
   
      motors.setSpeeds(motorSpeed, -motorSpeed);
    }
    else if(lineSensorValues[0] < blackColor && lineSensorValues[2] > blackColor) {
     
      motors.setSpeeds(-motorSpeed, motorSpeed);
    } else if(lineSensorValues[0] > blackColor && lineSensorValues[2] > blackColor) {
      state = pause_state;      
          } else {
     
      motors.setSpeeds(motorSpeeds, motorSpeeds);
    }
  }
  else if(state == pause_state) {
    motors.setSpeeds(0, 0);
    if(Serial.available()){
data = Serial.readString();  
dl = data.charAt(0);
if(dl == 'Q'){
    motors.setSpeeds(motorSpeeds, -motorSpeeds);
    delay(2500);
    
}
else if(dl == 'E'){
    motors.setSpeeds(-motorSpeeds, motorSpeeds);
    delay(2500);
    motors.setSpeeds(0, 0);
    delay(1000);
    state = run_state;
}
}    
    
  }
  
  lcd.gotoXY(0, 0);
  lcd.print(lineSensorValues[0] / 10);
  lcd.print("  ");


  lcd.gotoXY(5, 0);
  lcd.print(lineSensorValues[1] / 10);
  lcd.print("  ");


  lcd.gotoXY(0, 1);
  lcd.print(lineSensorValues[2] / 10);
  lcd.print("  ");


  lcd.gotoXY(5, 1);
  lcd.print(state);
  lcd.print("  ");
  delay(2);
}
