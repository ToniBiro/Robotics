
// stepper motor

const int stepperPin1 = 8;
const int stepperPin2 = 9;
const int stepperPin3 = 10;
const int stepperPin4 = 11;

const int delayTime = 5;

void controlStepper(int step1, int step2, int step3, int step4) {
  digitalWrite(stepperPin1, step1);
  digitalWrite(stepperPin2, step2);
  digitalWrite(stepperPin3, step3);
  digitalWrite(stepperPin4, step4);
  delay(delayTime);
}

void setup() {
  Serial.begin(9600);
  pinMode(stepperPin1, OUTPUT);
  pinMode(stepperPin2, OUTPUT);
  pinMode(stepperPin3, OUTPUT);
  pinMode(stepperPin4, OUTPUT);
}

void loop() {
  controlStepper(HIGH, LOW, LOW, LOW);
  controlStepper(HIGH, HIGH, LOW, LOW);
  controlStepper(LOW, HIGH, LOW, LOW);
  controlStepper(LOW, HIGH, HIGH, LOW);
  controlStepper(LOW, LOW, HIGH, LOW);
  controlStepper(LOW, LOW, HIGH, HIGH);
  controlStepper(LOW, LOW, LOW, HIGH);
}
