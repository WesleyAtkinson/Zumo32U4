
#include <Zumo32U4.h>

// --- Enums ---

// States. Here we just start out with a couple.
enum State {
  pause_state,
  run_state
};

// --- Constants

// What speed to run the motor
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

// --- Global Variables ---

Zumo32U4LCD lcd;
Zumo32U4LineSensors lineSensors;
unsigned int lineSensorValues[3];
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4ProximitySensors proxSensors;
State state = pause_state;
Zumo32U4Buzzer buzzer;
// --- Setup Function
void setup() {
  // Initialize the line sensors, and turn on the LEDs for them.
  lineSensors.initThreeSensors();
  lineSensors.emittersOn();
  proxSensors.initThreeSensors();
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
    if (currentMillis - previousMillis >= period) { 
      previousMillis = currentMillis;   
      
      proxSensors.read();    
       int center_left_sensor = proxSensors.countsFrontWithLeftLeds();
       int center_right_sensor = proxSensors.countsFrontWithRightLeds();
      if(center_right_sensor > 4 || center_left_sensor > 4){
        motors.setSpeeds(0,0);
         buzzer.playFrequency(440, 200, 15);
        delay(500);
        }
      motors.setSpeeds(-pin, pin);
      delay(250);
      proxSensors.read();
       center_left_sensor = proxSensors.countsFrontWithLeftLeds();
        center_right_sensor = proxSensors.countsFrontWithRightLeds();
      if(center_right_sensor > 4 || center_left_sensor > 4){
        motors.setSpeeds(0,0);
         buzzer.playFrequency(440, 200, 15);
        delay(500);
        
        }
      motors.setSpeeds(-pin, pin);
      delay(250);  
      proxSensors.read();
       center_left_sensor = proxSensors.countsFrontWithLeftLeds();
        center_right_sensor = proxSensors.countsFrontWithRightLeds();
      if(center_right_sensor > 4 || center_left_sensor > 4){
        motors.setSpeeds(0,0);
         buzzer.playFrequency(440, 200, 15);
        delay(500);
        }
      motors.setSpeeds(-pin, pin);
      delay(250);  
      proxSensors.read();
       center_left_sensor = proxSensors.countsFrontWithLeftLeds();
        center_right_sensor = proxSensors.countsFrontWithRightLeds();
      if(center_right_sensor > 4 || center_left_sensor > 4){
        motors.setSpeeds(0,0);
        delay(500);
        }
      motors.setSpeeds(-pin, pin);
      delay(250); 
      proxSensors.read(); 
       center_left_sensor = proxSensors.countsFrontWithLeftLeds();
        center_right_sensor = proxSensors.countsFrontWithRightLeds();
      if(center_right_sensor > 4 || center_left_sensor > 4){
        motors.setSpeeds(0,0);
         buzzer.playFrequency(440, 200, 15);
        delay(500);
        }
      motors.setSpeeds(-pin, pin);
      delay(350);
      proxSensors.read(); 
       center_left_sensor = proxSensors.countsFrontWithLeftLeds();
        center_right_sensor = proxSensors.countsFrontWithRightLeds();
      if(center_right_sensor > 4 || center_left_sensor > 4){
        motors.setSpeeds(0,0);
         buzzer.playFrequency(440, 200, 15);
        delay(500);
        }
       
      
      
      
    }
 
    if(lineSensorValues[0] > blackColor && lineSensorValues[2] > blackColor) {
      
      motors.setSpeeds(-motorSpeeds, -motorSpeeds);
      delay(500);
      motors.setSpeeds(motorSpeed, -motorSpeed);
      delay(500);
      motors.setSpeeds(-motorSpeeds, -motorSpeeds);
      delay(200);
    }
    else if(lineSensorValues[0] > blackColor && lineSensorValues[2] < blackColor) {
      // There's a line to the left. Veer right.
      motors.setSpeeds(motorSpeed, -motorSpeed);
    }
    else if(lineSensorValues[0] < blackColor && lineSensorValues[2] > blackColor) {
      // There's  line to the right. Veer left.
      motors.setSpeeds(-motorSpeed, motorSpeed);
    } else if(lineSensorValues[0] > blackColor && lineSensorValues[2] > blackColor) {
      
      motors.setSpeeds(-motorSpeeds, -motorSpeeds);
      delay(500);
      motors.setSpeeds(motorSpeed, -motorSpeed);
      delay(250);
    } else {
      
      motors.setSpeeds(motorSpeeds, motorSpeeds);
    }
  }
  else if(state == pause_state) {
    motors.setSpeeds(0, 0);
  }
  
  // Display the values.
  // Divide by 10 because our screen isn't large.

  // First value
  lcd.gotoXY(0, 0);
  lcd.print(lineSensorValues[0] / 10);
  lcd.print("  ");

  // Second value
  lcd.gotoXY(5, 0);
  lcd.print(lineSensorValues[1] / 10);
  lcd.print("  ");

  // Third value
  lcd.gotoXY(0, 1);
  lcd.print(lineSensorValues[2] / 10);
  lcd.print("  ");

  // State
  lcd.gotoXY(5, 1);
  lcd.print(state);
  lcd.print("  ");
  delay(2);
}
