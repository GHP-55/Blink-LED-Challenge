int ledPin = 5;
int togglePin = 3;
int tempValue;

void setup() {
  pinMode(ledPin, OUTPUT); //Yellow wire
  pinMode(togglePin, INPUT); //Blue wire
  Serial.begin(9600);
}

void loop() {
  if (tempValue != digitalRead(togglePin)) { //Button Pressed
    Toggle_Light();
  }
  tempValue = digitalRead(togglePin);
  Serial.println(digitalRead(togglePin));
}

void Toggle_Light () {
  if (digitalRead(ledPin) == LOW) { //If off turn on
    digitalWrite(ledPin, HIGH);
  }else if (digitalRead(ledPin) == HIGH) { //If on turn off
    digitalWrite(ledPin, LOW);
  }else { //Fuck
    Serial.println("Something went wrong.");
  }
}
