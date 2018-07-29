#define PIN A0


int state = HIGH;
bool locked = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN, OUTPUT);
  Serial.begin(9600);
  locked = false;
}

void loop() {
  analogRead(PIN);
  _checkLocked();
  if(!locked){
    state = HIGH;
    digitalWrite(PIN, state);
    delay(1000);
  }

  _checkLocked();
  if(!locked){
    state = LOW;
    digitalWrite(PIN, state);
    delay(1000);
  }

    Serial.println(locked);
 
}

bool _checkLocked(){
    locked = false;
   if(millis()>3000){
    delay(15);
    digitalWrite(PIN, LOW);
    pinMode(PIN, INPUT);
    int read = analogRead(PIN);
    if(read>40)//old
    {
      locked = (read<650);//closed
    }
    pinMode(PIN, OUTPUT);
    digitalWrite(PIN, state);
  }
  return locked;
}


