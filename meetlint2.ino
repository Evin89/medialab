#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);
// creates a "virtual" serial port/UART
// connect BT module TX to D10
// connect BT module RX to D11
// connect BT Vcc to 5V, GND to GND

// this constant won't change:
const int ledPin1 = 1;       // the pin that the LED is attached to
const int ledPin2 = 2;       // the pin that the LED is attached to
const int ledPin3 = 3;       // the pin that the LED is attached to
const int ledPin4 = 4;       // the pin that the LED is attached to
const int ledPin5 = 5;       // the pin that the LED is attached to
const int ledPin6 = 6;       // the pin that the LED is attached to
const int ledPin7 = 7;       // the pin that the LED is attached to
const int ledPin8 = 8;       // the pin that the LED is attached to
const int ledPin9 = 9;       // the pin that the LED is attached to
//const int ledPin10 = 10;       // the pin that the LED is attached to
//const int ledPin11 = 11;       // the pin that the LED is attached to

// Array with LEDS
int leds[] = {ledPin1, ledPin2, ledPin3, ledPin4, ledPin5, ledPin6, ledPin7, ledPin8, ledPin9};

int maxLeds = 8;

void setup() {
  // put your setup code here, to run once:
   for (int i = 0; i < maxLeds; i++){
    pinMode(leds[i], OUTPUT); 
  }
  
  // also add arduinos own led.
  pinMode(13, OUTPUT);
  // initialize serial communication:
  BT.begin(9600);
  BT.println("Initializing");

}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(BT.available()){
    turnAllLedsOff();
    BT.println("incoming");
    int ledsOn = BT.parseInt();
    BT.println(ledsOn); 
    turnLedOn(ledsOn);
    
  } else {
//    BT.println("Nothing incoming");
//    delay(1000);
  }

}

// Alle leds eerst uit.
void turnAllLedsOff(){
    BT.println("alle leds uit");
    for (int i = 0; i < maxLeds; i++){
    digitalWrite(leds[i], LOW); 
  }
}

// Goede LED aan.
void turnLedOn(int ledsOn){
  BT.println(ledsOn+ "/n leds on");
  for (int i = 0; i < ledsOn; i++){
    digitalWrite(leds[i] , HIGH);
  }
}
