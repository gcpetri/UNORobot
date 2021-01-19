#define STEP_PIN_1 9
#define STEP_PIN_2 10
#define STEP_PIN_3 11
#define STEP_PIN_4 12
#define STEP_PIN_11 3
#define STEP_PIN_12 4
#define STEP_PIN_13 5
#define STEP_PIN_14 6
int step_number = 0;
int step_number_2 = 0;
int incomingByte = 0;
void setup() {
  pinMode(STEP_PIN_1, OUTPUT);
  pinMode(STEP_PIN_2, OUTPUT);
  pinMode(STEP_PIN_3, OUTPUT);
  pinMode(STEP_PIN_4, OUTPUT);
  pinMode(STEP_PIN_11, OUTPUT);
  pinMode(STEP_PIN_12, OUTPUT);
  pinMode(STEP_PIN_13, OUTPUT);
  pinMode(STEP_PIN_14, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
  incomingByte = Serial.read();
  Serial.println(incomingByte, DEC);
  if (incomingByte == 49) {
    Serial.println("left");
    for (int i = 0; i < 250; i++) {
      OneStep(true); // left
      delay(2);
    }
  } else if (incomingByte == 48) {
    Serial.println("right");
    for (int i = 0; i < 250; i++) {
      OneStep(false); // right
      delay(2);
    }
  } else if (incomingByte == 50) {
    Serial.println("left");
    for (int i = 0 ; i < 250; i++) {
      OneStep2(true); // left 2
      delay(2);
    }
  } else if (incomingByte == 51) {
    Serial.println("right");
    for (int i = 0; i < 250; i++) {
      OneStep2(false); // right 2
      delay(2);
    }
  }
  }
  delay(2); // 2 ms is minimum delay between steps
}
void OneStep(bool dir) {
if (dir) {
switch(step_number) {
  case 0: 
    digitalWrite(STEP_PIN_1, HIGH);
    digitalWrite(STEP_PIN_2, LOW);
    digitalWrite(STEP_PIN_3, LOW);
    digitalWrite(STEP_PIN_4, LOW);
    break;
  case 1:
    digitalWrite(STEP_PIN_1, LOW);
    digitalWrite(STEP_PIN_2, HIGH);
    digitalWrite(STEP_PIN_3, LOW);
    digitalWrite(STEP_PIN_4, LOW);
    break;
  case 2:
    digitalWrite(STEP_PIN_1, LOW);
    digitalWrite(STEP_PIN_2, LOW);
    digitalWrite(STEP_PIN_3, HIGH);
    digitalWrite(STEP_PIN_4, LOW);
    break;
  case 3:
    digitalWrite(STEP_PIN_1, LOW);
    digitalWrite(STEP_PIN_2, LOW);
    digitalWrite(STEP_PIN_3, LOW);
    digitalWrite(STEP_PIN_4, HIGH);
    break;
}
} else {
switch(step_number) {
  case 0: 
    digitalWrite(STEP_PIN_1, LOW);
    digitalWrite(STEP_PIN_2, LOW);
    digitalWrite(STEP_PIN_3, LOW);
    digitalWrite(STEP_PIN_4, HIGH);
    break;
  case 1:
    digitalWrite(STEP_PIN_1, LOW);
    digitalWrite(STEP_PIN_2, LOW);
    digitalWrite(STEP_PIN_3, HIGH);
    digitalWrite(STEP_PIN_4, LOW);
    break;
  case 2:
    digitalWrite(STEP_PIN_1, LOW);
    digitalWrite(STEP_PIN_2, HIGH);
    digitalWrite(STEP_PIN_3, LOW);
    digitalWrite(STEP_PIN_4, LOW);
    break;
  case 3:
    digitalWrite(STEP_PIN_1, HIGH);
    digitalWrite(STEP_PIN_2, LOW);
    digitalWrite(STEP_PIN_3, LOW);
    digitalWrite(STEP_PIN_4, LOW);
    break;
}}
step_number++;
if (step_number > 3) {
step_number = 0; }
}
void OneStep2(bool dir) {
if (dir) {
switch(step_number_2) {
  case 0: 
    digitalWrite(STEP_PIN_11, HIGH);
    digitalWrite(STEP_PIN_12, LOW);
    digitalWrite(STEP_PIN_13, LOW);
    digitalWrite(STEP_PIN_14, LOW);
    break;
  case 1:
    digitalWrite(STEP_PIN_11, LOW);
    digitalWrite(STEP_PIN_12, HIGH);
    digitalWrite(STEP_PIN_13, LOW);
    digitalWrite(STEP_PIN_14, LOW);
    break;
  case 2:
    digitalWrite(STEP_PIN_11, LOW);
    digitalWrite(STEP_PIN_12, LOW);
    digitalWrite(STEP_PIN_13, HIGH);
    digitalWrite(STEP_PIN_14, LOW);
    break;
  case 3:
    digitalWrite(STEP_PIN_11, LOW);
    digitalWrite(STEP_PIN_12, LOW);
    digitalWrite(STEP_PIN_13, LOW);
    digitalWrite(STEP_PIN_14, HIGH);
    break;
}
} else {
switch(step_number_2) {
  case 0: 
    digitalWrite(STEP_PIN_11, LOW);
    digitalWrite(STEP_PIN_12, LOW);
    digitalWrite(STEP_PIN_13, LOW);
    digitalWrite(STEP_PIN_14, HIGH);
    break;
  case 1:
    digitalWrite(STEP_PIN_11, LOW);
    digitalWrite(STEP_PIN_12, LOW);
    digitalWrite(STEP_PIN_13, HIGH);
    digitalWrite(STEP_PIN_14, LOW);
    break;
  case 2:
    digitalWrite(STEP_PIN_11, LOW);
    digitalWrite(STEP_PIN_12, HIGH);
    digitalWrite(STEP_PIN_13, LOW);
    digitalWrite(STEP_PIN_14, LOW);
    break;
  case 3:
    digitalWrite(STEP_PIN_11, HIGH);
    digitalWrite(STEP_PIN_12, LOW);
    digitalWrite(STEP_PIN_13, LOW);
    digitalWrite(STEP_PIN_14, LOW);
    break;
}}
step_number_2++;
if (step_number_2 > 3) {
step_number_2 = 0; }
}
