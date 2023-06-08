#include <Adafruit_CircuitPlayground.h>
int switchPin = 7;
int buttonPinA = 4;
int buttonPinB = 5;
int rando = 0;
bool buttonFlagA = 0;
bool buttonFlagB = 0;
bool switchFlag = 0;
bool switchState = 0;
bool game = 0;

void setup() { //
  CircuitPlayground.begin();//This is the beginning of the setup() function, which is called once when the microcontroller starts running.
  Serial.begin(9600);//This line initializes the serial communication between the microcontroller and a connected computer, with a baud rate of 9600 bits per second. This allows the microcontroller to send messages to the computer via the USB connection.
  pinMode(switchPin, INPUT_PULLUP); //activating pin and the modes
  pinMode(buttonPinA, INPUT_PULLDOWN);
  pinMode(buttonPinB, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(buttonPinA), buttonA, FALLING);//sets up an interrupt that will trigger when the right button on the Circuit Playground board 
  attachInterrupt(digitalPinToInterrupt(buttonPinB), buttonB, FALLING);//sets up an interrupt that will trigger when the left button on the Circuit Playground boar
  randomSeed(analogRead(0)); // Seed the random, randomly
}

void loop() {
    /*if(switchFlag){//reset the flag and switch the state of the switch
    delay(5);
    switchFlag = 0;
    if (rando == 2){
      CircuitPlayground.clearPixels();
      game = 0;
    }else{
      CircuitPlayground.clearPixels();
      game = 0;
      Serial.println(" Wrong ");
    }
  }*/
  if(buttonFlagA){//reset the flag and restart the count
    delay(5);
    buttonFlagA = 0;
      if (rando == 0){
      CircuitPlayground.clearPixels();
      game = 0;
    }else{
      CircuitPlayground.clearPixels();
      game = 0;
      Serial.println(" Wrong ");//If wrong then will flash red and beep
      for(int i = 0; i<10; i++){
      CircuitPlayground.setPixelColor(i, 255, 0, 0);
      }
      CircuitPlayground.playTone(1400,50);
      delay(50);
      CircuitPlayground.clearPixels();
    }
    }
    if(buttonFlagB){//reset the flag and restart the count
    delay(5);
    buttonFlagB = 0;
      if (rando == 1){
      CircuitPlayground.clearPixels();
      game = 0;
    }else{
      CircuitPlayground.clearPixels();
      game = 0;
      Serial.println(" Wrong ");
      for(int i = 0; i<10; i++){
      CircuitPlayground.setPixelColor(i, 255, 0, 0);
      }
      delay(50);
      CircuitPlayground.playTone(1400,50); //here is the sound
      CircuitPlayground.clearPixels();
    }
    }
    if (!game){
rando = random(2); //randomizing a number and then setting it to that case which will produce a color
switch(rando){
  case 0:
      for(int i = 0; i<10; i++){
      CircuitPlayground.setPixelColor(i, 0, 0, 255);//This is for the blue color
      }
      game = 1;
    break;
  case 1:
      for(int i = 0; i<10; i++){
      CircuitPlayground.setPixelColor(i, 0, 255, 0);//This is for the green color
      }
      game = 1;
    break;
 
  default:
    break;
}
}
}
    void buttonA(void){//button set up
  buttonFlagA = 1;
}
    void buttonB(void){
  buttonFlagB = 1;
}
 