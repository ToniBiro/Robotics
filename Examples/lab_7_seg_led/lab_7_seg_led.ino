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


int segments[seg_size] = {
  pin_a, pin_b, pin_c, pin_d, pin_e, pin_f, pin_g, pin_dp
};
void setup() {
  Serial.begin(9600);
  for(int i = 0; i < seg_size; ++i)
  {
    pinMode(segments[i], OUTPUT);
  }
  pinMode(pin_x, INPUT);
  pinMode(pin_y, INPUT);
  pinMode(pin_sw, INPUT_PULLUP);
}

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

void digit_write(byte digit,byte dp)
{
  for (int i = 0; i < seg_size-1; ++i)
  {
    digitalWrite(segments[i], digit_matrix[digit][i]); 
  }

  digitalWrite(segments[seg_size - 1], dp);
}

int dpState = 0;
int sw_value = 0;
int x_value = 0;
int y_value = 0;
int min_threshold = 400;
int max_threshold = 600;
bool joy_moved = false;
int digit;
int lastSwState = 0;
int swState = 0;

void loop() {
  x_value = analogRead(pin_x);
  y_value = analogRead(pin_y);
  sw_value = digitalRead(pin_sw);

  if (x_value < min_threshold && joy_moved == false) {
  if (digit > 0) {
      digit--;
  } else {
      digit = 9;
  }
  joy_moved = true;
  }

 // On Ox axis, if the value is bigger than a chosen max threshold, then
 // increase by 1 the digit value
  if (x_value > max_threshold && joy_moved == false) {
  if (digit < 9) {
      digit++;
  } else {
      digit = 0;
  }
  joy_moved = true;
  }

  if (x_value >= min_threshold && x_value <= max_threshold) {
  joy_moved = false;
  }

  // simple state change detector. Ideally, use debounce.
  swState = digitalRead(pin_sw);
  if (swState !=  lastSwState) {
    if (swState == LOW) {
        dpState = !dpState;
    }
  }
  lastSwState = swState;
 
  digit_write(digit, dpState);
  delay(1);

  
}
