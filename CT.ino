int Relay = 7;
int elay = 8;
const uint8_t DirPin = 2;
const uint8_t StepPin = 3;
const uint8_t CSPin = 4;

void setup() {
  pinMode(Relay, OUTPUT);
  pinMode(elay, OUTPUT);
  pinMode(DirPin, OUTPUT);
  pinMode(StepPin, OUTPUT);
  Serial.begin(9600); 
  
  int numCycles = 11; 

  for (int i = 0; i < numCycles; i++) {
    {
    digitalWrite(elay, LOW);
    digitalWrite(Relay, LOW);
    delay(12);
    digitalWrite(Relay, HIGH);
    delay(500);
    digitalWrite(elay, HIGH);
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

void loop() ;
   digitalWrite(elay, LOW);
   digitalWrite(Relay, LOW);
   digitalWrite(Relay, LOW);
   digitalWrite(elay, LOW);
}
