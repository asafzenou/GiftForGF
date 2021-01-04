const int listSize = 9;
int ledList[listSize]= {13, 12, 11, 10, 9, 8, 7, 6, 5};

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(4, OUTPUT);
  for(int i=0; i < listSize; i++){
    pinMode(ledList[i], OUTPUT);
    
  }  
}

void off_FromTheEndToStart();

void loop() {
  turningOnA_Heart_M();
  
}


// This function will turn A and then Heart and then the M in that order
void turningOnA_Heart_M(){
  off_All_Leds_Together();
   for(int i=0; i < listSize/3; i++){
    digitalWrite(ledList[i], HIGH);
  }
  delay(3000);
    
  for(int i=listSize/3; i < (2*listSize)/3; i++){
    digitalWrite(ledList[i], HIGH);
  }
  delay(3000);
  for(int i=(2*listSize)/3; i < listSize; i++){
    digitalWrite(ledList[i], HIGH);
  }
  delay(5000);
}


// Turning off all leds from the end to start
void off_FromTheEndToStart(){
  for(int i=listSize-1; i >= 0; i--){
    digitalWrite(ledList[i], LOW);
    delay(700);
    Serial.println("The i is " + String(i) );
    Serial.println("The number is " +String(ledList[i]) );    
  }  
}

// Turning off all leds from the start to end
void off_FromTheStartToEnd(){
  for(int i=0; i < listSize ; i++){
    digitalWrite(ledList[i], LOW);
    delay(700);
    Serial.println("The i is " + String(i) );
    Serial.println("The number is " +String(ledList[i]) );    
  }  
}


// Turning on all the leds in the same time
void on_All_Leds_Together(){
  for(int i=0; i < listSize; i++){
    digitalWrite(ledList[i], HIGH);
  }
}


// Turning on all the leds in the same time
void off_All_Leds_Together(){
  for(int i=0; i < listSize; i++){
    digitalWrite(ledList[i], LOW);
  }
}

// Turning on all even leds together
void on_All_even_Leds_Together(){
  for(int i=0; i < listSize; i+=2){
    digitalWrite(ledList[i], HIGH);
  }
}

// Turning on all not even leds together
void on_All_not_even_Leds_Together(){
  for(int i=1; i < listSize; i+=2){
    digitalWrite(ledList[i], HIGH);
  }
}
