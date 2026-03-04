int Relay = 7;
int lay = 9;
int elay = 8;
int turns = 10;
int button = 6;
int potStep = A1;
int potSample = analogRead(potStep);
int numberOfSteps = 15;
int safteyled = 45;
int buzzer = 42;
int hvled = 41;
int filiment = 11;
const uint8_t DirPin = 2;
const uint8_t StepPin = 3;
const uint8_t CSPin = 4;

void setup() {
  pinMode(hvled, OUTPUT);
  pinMode(filiment, OUTPUT);
  pinMode(safteyled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(lay, OUTPUT);
  pinMode(potSample, INPUT);
  pinMode(button, INPUT);
  pinMode(Relay, OUTPUT);
  pinMode(elay, OUTPUT);
  pinMode(DirPin, OUTPUT);
  pinMode(StepPin, OUTPUT);
  Serial.begin(9600); 
  
  
  
}

void loop() {
  int potSample = analogRead(potStep);
  int numberOfSteps = map(potSample, 0, 1023, 1, 100);
  int x = numberOfSteps;
  digitalWrite(Relay, LOW);
   digitalWrite(elay, LOW);
  if (digitalRead(button) == HIGH) {
     digitalWrite(hvled, HIGH);
     CT(x);
   
  }
  if (digitalRead(button) == LOW) {
     digitalWrite(hvled, LOW);
     digitalWrite(Relay, LOW);
     digitalWrite(elay, LOW);
   
  }
  if (digitalRead(filiment) == HIGH) {
     digitalWrite(lay, HIGH);
     digitalWrite(safteyled, HIGH);
     digitalWrite(buzzer, HIGH);

}
  if (digitalRead(filiment) == LOW) {
     digitalWrite(lay, LOW);
     digitalWrite(safteyled, LOW);
     digitalWrite(buzzer, LOW);

}
}
void CT(int x) {
  int numCycles = 5; 
  for (int i = 0; i < numCycles; i++) {
    {
    digitalWrite(elay, LOW);
    digitalWrite(Relay, LOW);
    delay(12);
    digitalWrite(Relay, HIGH);
    delay(500);
    digitalWrite(elay, HIGH);
    delay(3000);
    digitalWrite(Relay, LOW);
    digitalWrite(elay, LOW);
    
  }
  
  for (int x = 0; x < 3200; x++) {
    digitalWrite(StepPin, HIGH);
    delayMicroseconds(200);
    digitalWrite(StepPin, LOW);
  }
    delay(500);
    Serial.print("Cycle number: ");
    Serial.println(i + 1);
    
  }

  
}
