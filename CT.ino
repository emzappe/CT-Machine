int Relay = 7;
int elay = 8;
int turns = 10;
int button = 6;
int potStep = A1;
int potSample = analogRead(potStep);
int numberOfSteps = 15;
const uint8_t DirPin = 2;
const uint8_t StepPin = 3;
const uint8_t CSPin = 4;

void setup() {
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
  delay(1000);
  int x = numberOfSteps;
  if (digitalRead(button) == HIGH) {
    CT(x);
   
  }
  
}

void CT(int x) {
  int numCycles = x; 
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
  delay(500);

  digitalWrite(DirPin, LOW);
  for (int x = 0; x < 3200; x++) {
    digitalWrite(StepPin, HIGH);
    delayMicroseconds(200);
    digitalWrite(StepPin, LOW);
    delayMicroseconds(200);
  }
    
    Serial.print("Cycle number: ");
    Serial.println(i + 1);
  }

  
}
