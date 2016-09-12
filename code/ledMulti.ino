const int LEDBLUE = 11;
const int LEDRED = 10;
const int LEDGREEN = 9;
const int LEDGREEN2 = 6;
const int BUTTON = 12;

int redVal = 15;
int blueVal = 8;
int greenVal = 0;
int redChange = 1;
int blueChange = 1;
int greenChange = 1;

int buttonPower = 0;
int selection = 2;

void setup() {
  pinMode(LEDBLUE, OUTPUT);
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDGREEN2, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonPower = digitalRead(BUTTON);
  if(buttonPower == HIGH) {
    selection++;
    delay(500);
  }
  if(selection > 2) {
    selection = 0;
  }

  if(selection == 0) {
    immediate();
  }
  if(selection == 1) {
    solid();
  }
  if(selection == 2) {
    transitioning();
  }
}

void immediate() {
  analogWrite(LEDBLUE, 15);
  analogWrite(LEDRED, 15);
  digitalWrite(LEDGREEN, LOW);
  digitalWrite(LEDGREEN2, LOW);
  buttonPower = digitalRead(BUTTON);
  if(buttonPower == HIGH) {
    return;
  }
  delay(200);
  analogWrite(LEDBLUE, 0);
  analogWrite(LEDRED, 15);
  digitalWrite(LEDGREEN, HIGH);
  digitalWrite(LEDGREEN2, HIGH);
  buttonPower = digitalRead(BUTTON);
  if(buttonPower == HIGH) {
    return;
  }
  delay(200);
  analogWrite(LEDBLUE, 15);
  analogWrite(LEDRED, 0);
  digitalWrite(LEDGREEN, HIGH);
  digitalWrite(LEDGREEN2, HIGH);
  buttonPower = digitalRead(BUTTON);
  if(buttonPower == HIGH) {
    return;
  }
  delay(200);
}

void flash(){
  analogWrite(LEDBLUE, 15);
  analogWrite(LEDRED, 15);
  digitalWrite(LEDGREEN, HIGH);
  digitalWrite(LEDGREEN2, HIGH);
  buttonPower = digitalRead(BUTTON);
  if(buttonPower == HIGH) {
    return;
  }
  delay(10);
  analogWrite(LEDBLUE, 0);
  analogWrite(LEDRED, 0);
  digitalWrite(LEDGREEN, LOW);
  digitalWrite(LEDGREEN2, LOW);
  buttonPower = digitalRead(BUTTON);
  if(buttonPower == HIGH) {
    return;
  }
  delay(600);
}

void solid(){
  analogWrite(LEDBLUE, 15);
  analogWrite(LEDRED, 15);
  digitalWrite(LEDGREEN, HIGH);
  digitalWrite(LEDGREEN2, HIGH); 
}

void transitioning(){
    if(redVal == 15) {
      redChange = -1;
    } else if (redVal == 0) {
      redChange = 1;
    }
    redVal += redChange;
    analogWrite(LEDRED, redVal);

    if(blueVal == 15) {
      blueChange = -1;
    } else if (blueVal == 0) {
      blueChange = 1;
    }
    blueVal += blueChange;
    analogWrite(LEDBLUE, blueVal);

    if(greenVal == 255) {
      greenChange = -17;
    } else if (greenVal == 0) {
      greenChange = 17;
    }
    greenVal += greenChange;
    analogWrite(LEDGREEN, greenVal);
    analogWrite(LEDGREEN2, greenVal);
    buttonPower = digitalRead(BUTTON);
    if(buttonPower == HIGH) {
      return;
    }
    delay(200);
}

