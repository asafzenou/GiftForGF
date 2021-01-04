const int listSize = 9;
int ledList[listSize]= {13, 12, 11, 10, 9, 8, 7, 6, 5};

//ultrasonic sensor
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04



void setup() {
  Serial.begin(9600);
  delay(1000);
  for(int i=0; i < listSize; i++){
    pinMode(ledList[i], OUTPUT);
  }  
  //ultrasonic sensor
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
}

void off_FromTheEndToStart();

void loop() {
  action_By_Distance();

}

/// choosing leds by the distance from sensor
void action_By_Distance(){
  int distance = get_Distance_Ultrasonic();
  if (distance > 1000){
    turningOnA_Heart_M();    
  }  
  else if(distance > 200){
      even_And_NotEven();
  }
  else {
    on_All_Leds_Together(); 
  }
}


/// This function will turn A and then Heart and then the M in that order
void turningOnA_Heart_M(){
  off_All_Leds_Together();
   for(int i=0; i < listSize/3; i++){
    digitalWrite(ledList[i], HIGH);
  }
  delay(3000);
  off_All_Leds_Together(); 
  for(int i=listSize/3; i < (2*listSize)/3; i++){
    digitalWrite(ledList[i], HIGH);
  }
  delay(3000);
  off_All_Leds_Together();
  for(int i=(2*listSize)/3; i < listSize; i++){
    digitalWrite(ledList[i], HIGH);
  }
  delay(5000);
  off_All_Leds_Together();
}

/// Maxing even and not even leds
void even_And_NotEven(){
  for(int i=0; i<3; i++){
    on_All_even_Leds_Together();
    delay(1000);
    on_All_not_even_Leds_Together();
    delay(1000);
  }
  
  
}


/// Turning off all leds from the end to start
void off_FromTheEndToStart(){
  for(int i=listSize-1; i >= 0; i--){
    digitalWrite(ledList[i], LOW);
    delay(700);
    Serial.println("The i is " + String(i) );
    Serial.println("The number is " +String(ledList[i]) );    
  }  
}

/// Turning off all leds from the start to end
void off_FromTheStartToEnd(){
  for(int i=0; i < listSize ; i++){
    digitalWrite(ledList[i], LOW);
    delay(700);
    Serial.println("The i is " + String(i) );
    Serial.println("The number is " +String(ledList[i]) );    
  }  
}


/// Turning on all the leds in the same time
void on_All_Leds_Together(){
  for(int i=0; i < listSize; i++){
    digitalWrite(ledList[i], HIGH);
  }
}


/// Turning on all the leds in the same time
void off_All_Leds_Together(){
  for(int i=0; i < listSize; i++){
    digitalWrite(ledList[i], LOW);
  }
}

/// Turning on all even leds together
void on_All_even_Leds_Together(){
  off_All_Leds_Together();
  for(int i=0; i < listSize; i+=2){
    digitalWrite(ledList[i], HIGH);
  }
}

/// Turning on all not even leds together
void on_All_not_even_Leds_Together(){
  off_All_Leds_Together();
  for(int i=1; i < listSize; i+=2){
    digitalWrite(ledList[i], HIGH);
  }
}

///ultrasonic distance information
int get_Distance_Ultrasonic(){
  long duration; // variable for the duration of sound wave travel
  int distance; // variable for the distance measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}
