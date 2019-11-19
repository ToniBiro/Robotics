const int seg_size = 8;
const int pin_a = 2;
const int pin_b = 3;
const int pin_c = 4;
const int pin_d = 5;
const int pin_e = 6;
const int pin_f = 7;
const int pin_g = 8;
const int pin_dp = 9;

const int pin_sw = 10;
const int pin_x = A0;
const int pin_y = A1;

int dpState = 0;
const int noOfDisplays = 4;
const int noOfDigits = 10;

int segments[seg_size] = {
  pin_a, pin_b, pin_c, pin_d, pin_e, pin_f, pin_g, pin_dp
};

int digits[noOfDisplays] = {
  piD1, pinD2, pinD3, pinD4
};


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

void digit_write(byte digit, byte dp)
{
  for (int i = 0; i < seg_size-1; ++i)
  {
    digitalWrite(segments[i], digit_matrix[digit][i]); 
  }

  digitalWrite(segments[seg_size - 1], dp);
}

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
}

void loop()
{
  int number;
  int digit;
  int lastDigit;
  
  Serial.println(currentNumber);
  
  number = currentNumber;
  digit = 0;
  while (number != 0)
  {
    lastDigit = number % 10; // get the last digit
    showDigit(digit);
    displayNumber(lastDigit, HIGH);
    // increase this delay to see multiplexing in action. At about 100 it
    becomes obvious
    delay(5);
    digit++; // move to next display
    number = number / 10;
  }
  // increment the number
  if (millis() - lastIncreasing >= delayCounting)
  {
    currentNumber = (currentNumber + 1) % 10000;
    lastIncreasing = millis();
  }
}
