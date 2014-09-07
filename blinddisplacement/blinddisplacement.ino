const int pinTrigger = 8;
const int pinEcho = 7;
const int pinSpeaker = 12;

void setup(){
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(pinSpeaker, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);
  int distance = pulseIn(pinEcho, HIGH)/58;
  if(distance <= 60 && distance >= 45){
    digitalWrite(pinSpeaker, HIGH);
    delay(200);
    digitalWrite(pinSpeaker, LOW);
    delay(200);
  } else if(distance < 45 && distance >= 30){
    digitalWrite(pinSpeaker, HIGH);
    delay(100);
    digitalWrite(pinSpeaker, LOW);
    delay(100);
  } else if(distance < 30){
    digitalWrite(pinSpeaker, HIGH);
    delay(50);
    digitalWrite(pinSpeaker, LOW);
    delay(50); 
  } else {
    digitalWrite(pinSpeaker, LOW);
  }
  Serial.print(distance);
  Serial.println(" cm");
}
