/*
 * led
 *
 *  Created on: Oct 1, 2021
 *      Author: crazy-luke
 */
#define irPin 8
#define sensorPin A0
#define rPin 5
#define gPin 3
#define bPin 6

const bool DEBUG = false;
bool iroutput;
int light;

void setup() {
  pinMode(rPin,OUTPUT);  
  pinMode(gPin,OUTPUT);  
  pinMode(bPin,OUTPUT);
  pinMode(irPin, INPUT);  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  light = analogRead(sensorPin);
  iroutput = digitalRead(irPin);
  if(light>=500 && iroutput>0){
    flash();
  }else{
    lightoff();
  }
  if(DEBUG){
    Serial.println(F("-----------------------------"));
    Serial.println(light);
    Serial.println(iroutput);
    Serial.println(F("-----------------------------"));
  }
  delay(500);
}

void flash(){
  for(int a = 0;a<=10;a++){
    int r = random(0,255);
    analogWrite(rPin,r);
    delay(250);
    int g = random(0,255);
    analogWrite(gPin,g);
    delay(250);
    int b = random(0,255);
    analogWrite(bPin,b);
    delay(250);      
  }
}

void lightoff(){
  analogWrite(rPin,0);  
  analogWrite(gPin,0);    
  analogWrite(bPin,0);
}
