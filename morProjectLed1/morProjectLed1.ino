int listSize = 8;
int ledList[8]= {13, 12, 11, 10, 9, 8, 7, 6};

void setup() {
  Serial.begin(9600);
  delay(1000);
  for(int i=0; i < listSize; i++){
    pinMode(ledList[i], OUTPUT);
  }  
}

void loop() {
  turningOnA_Heart_M();
  off_FromTheEndToStart(); 
}


// This function will turn A and then Heart and then the M in that order
void turningOnA_Heart_M(){
    digitalWrite(ledList[i], HIGH);
    delay(700);
  }
delay(3000);
    
  for(int i=4; i < listSize; i++){
    digitalWrite(ledList[i], HIGH);
    delay(700);
  }
}


// Turning off all leds from the end to that start
void off_FromTheEndToStart(){
  for(int i=listSize-1; i >= 0; i--){
    digitalWrite(ledList[i], LOW);
    delay(700);
    Serial.println("The i is " + String(i) );
    Serial.println("The number is " +String(ledList[i]) );    
  }  
}
