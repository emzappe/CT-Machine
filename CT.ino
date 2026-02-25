int Relay = 7;
int elay = 8;
int turns = 10;
int button = 6;
int potStep = A1;
int photo = 13;
int potSample = analogRead(potStep);
const uint8_t DirPin = 2;
const uint8_t StepPin = 3;
const uint8_t CSPin = 4;

void setup() {
  pinMode(button, INPUT);
  pinMode(Relay, OUTPUT);
  pinMode(elay, OUTPUT);
  pinMode(DirPin, OUTPUT);
  pinMode(StepPin, OUTPUT);
  Serial.begin(9600); 
  int numberOfSteps = map(potSample, 0, 1023, 20, 300);
  int potSample = analogRead(potStep);
  

  
}

void loop() {
  if (digitalRead(button) == HIGH) {
  CT();
  }

}

void CT() {
  int numCycles = photo; 
  for (int i = 0; i < numCycles; i++) {
    {
    digitalWrite(elay, LOW);
    digitalWrite(Relay, LOW);
    delay(12);
    digitalWrite(Relay, HIGH);
    delay(500);
    digitalWrite(elay, HIGH);
    delay(2000);
    digitalWrite(Relay, LOW);
    digitalWrite(elay, LOW);
  }

 {
    digitalWrite(DirPin, LOW);
    digitalWrite(StepPin, HIGH);
    delayMicroseconds(200);
    digitalWrite(StepPin, LOW);
    delayMicroseconds(200);
  }
    
    Serial.print("Cycle number: ");
    Serial.println(i + 1);
  }

  
}
