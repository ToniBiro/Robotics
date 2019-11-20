const int pin_a = 12;
const int pin_b = 8;
const int pin_c = 5;
const int pin_d = 3;
const int pin_e = 2;
const int pin_f = 11;
const int pin_g = 6;
const int pin_dp = 4;
const int pinD1 = 7;
const int pinD2 = 9;
const int pinD3 = 10;
const int pinD4 = 13;

const int pin_sw = 10;
const int pin_x = A0;
const int pin_y = A1;

const int seg_size = 8;
int currentNumber = 0;
unsigned long delayCounting = 500; // incrementing interval
unsigned long lastIncreasing = 0;
const int noOfDisplays = 4;
const int noOfDigits = 10;

byte digit_matrix[noOfDigits][seg_size - 1] = {
// a  b  c  d  e  f  g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

int segments[seg_size] = {
  pin_a, pin_b, pin_c, pin_d, pin_e, pin_f, pin_g, pin_dp
};

int digits[noOfDisplays] = {
  pinD1, pinD2, pinD3, pinD4
};

void displayNumber(byte digit, byte dp)
{
  for (int i = 0; i < seg_size-1; ++i)
  {
    digitalWrite(segments[i], digit_matrix[digit][i]); 
  }

  digitalWrite(segments[seg_size - 1], dp);
}

void showDigit(int num)
{
  for(int i = 0; i < noOfDisplays; ++i)
  {
      digitalWrite(digits[i], HIGH);
  }
  digitalWrite(digits[num], LOW);
}

const int xPin = A0;
const int yPin = A1;
const int swPin = A2;

void setup() 
{
  for (int i = 0; i < seg_size - 1; i++)
  {
    pinMode(segments[i], OUTPUT);
  }
  for (int i = 0; i < noOfDisplays; i++)
  {
    pinMode(digits[i], OUTPUT);
  }
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(swPin, INPUT);
}

const int minThreshold = 400;
const int maxThreshold = 600;
int xValue;
int yValue;
int swValue;
bool joyMoved = false;

int lastSwState = 0;
int swState = 0;
int dpState = 0;
int selectedDigit = 0;
int currentNumbers[4] = {0, 0, 0, 0};
int currentDigit = 0;

void loop()
{
  
  xValue = analogRead(xPin);
  yValue = analogRead(yPin);
  
  if (xValue > maxThreshold && joyMoved == false && swState == LOW) {
    if (currentNumbers[currentDigit] < 9) {
        currentNumbers[currentDigit]++;
    } else {
        currentNumbers[currentDigit] = 0;
    }
    joyMoved = true;
  }

  if (xValue >= minThreshold && xValue <= maxThreshold) {
    joyMoved= false;
  }
  
  swState = analogRead(swPin);
  Serial.println(swState);
  Serial.println(xValue);
  if (swState !=  lastSwState) {
    if (swState == LOW) {
        dpState = !dpState;
    }
  }
  lastSwState = swState;

  showDigit(currentDigit);
  displayNumber(currentNumbers[currentDigit], dpState);
}
