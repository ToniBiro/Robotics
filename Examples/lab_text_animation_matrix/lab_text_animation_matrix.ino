
//Connect these pins to the corresponding row input of the 8x8 matrix.
const unsigned char RowPins[] = {6, 11, A5, 9, 5, A4, 4, A2};
//Connect these pins to the corresponding column input of the 8x8 matrix.
const unsigned char ColumnPins[] = {10, 3, 2, 7, A3, 8, 12, 13};

unsigned char A[] = {B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};
unsigned char B[] = {B01111000,B01001000,B01001000,B01110000,B01001000,B01000100,B01000100,B01111100};
unsigned char C[] = {B00000000,B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110};
unsigned char D[] = {B00000000,B00111000,B00100100,B00100010,B00100010,B00100100,B00111000,B00000000};
unsigned char E[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00111100,B00000000};
unsigned char F[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00100000,B00000000};
unsigned char G[] = {B00000000,B00111110,B00100000,B00100000,B00101110,B00100010,B00111110,B00000000};
unsigned char H[] = {B00000000,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00000000};
unsigned char I[] = {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
unsigned char J[] = {B00000000,B00011100,B00001000,B00001000,B00001000,B00101000,B00111000,B00000000};
unsigned char K[] = {B00000000,B00100100,B00101000,B00110000,B00101000,B00100100,B00100100,B00000000};
unsigned char L[] = {B00000000,B00100000,B00100000,B00100000,B00100000,B00100000,B00111100,B00000000};
unsigned char M[] = {B00000000,B00000000,B01000100,B10101010,B10010010,B10000010,B10000010,B00000000};
unsigned char N[] = {B00000000,B00100010,B00110010,B00101010,B00100110,B00100010,B00000000,B00000000};
unsigned char O[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};
unsigned char P[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100000,B00100000,B00000000};
unsigned char Q[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001};
unsigned char R[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100100,B00100100,B00000000};
unsigned char S[] = {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
unsigned char T[] = {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000};
unsigned char U[] = {B00000000,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000};
unsigned char V[] = {B00000000,B00100010,B00100010,B00100010,B00010100,B00010100,B00001000,B00000000};
unsigned char W[] = {B00000000,B10000010,B10010010,B01010100,B01010100,B00101000,B00000000,B00000000};
unsigned char X[] = {B00000000,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B00000000};
unsigned char Y[] = {B00000000,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00000000};
unsigned char Z[] = {B00000000,B00111100,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};

unsigned char *Alphabet[] = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};
unsigned char AlphabetCharactersLower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};


unsigned char* DisplayBuffer = nullptr;

unsigned char DisplayIndex = 0;
unsigned long DisplayLetterBeginMilliseconds = 0;
unsigned long DisplayLetterEndMilliseconds = 0;
bool DisplayActive = false;

void setup()
{
    // Open serial port
    Serial.begin(9600);
    //Sets up all of the row pins to be used as outputs.
    for(unsigned char i = 0; i < sizeof(RowPins); i++)
    {
        pinMode(RowPins[i], OUTPUT);
    }
    //Sets up all of the column pins to be used as outputs.
    for(unsigned char i = 0; i < sizeof(ColumnPins); i++)
    {
        pinMode(ColumnPins[i], OUTPUT);
    }
}


//Resets the values used to time the duration of display.
void SetDisplayTiming(const unsigned displayMilliseconds)
{
    DisplayLetterBeginMilliseconds = millis();
    DisplayLetterEndMilliseconds = DisplayLetterBeginMilliseconds + displayMilliseconds;
    DisplayActive = true;
}

void UpdateDisplay()
{
    //Loop through rows.
    for(unsigned char i = 0; i < sizeof(RowPins); i++)
    {
        //Loop through columns.
        for(unsigned char j = 0; j < sizeof(ColumnPins); j++)
        {
            //Turn column on for the corresponding bit.
            digitalWrite(ColumnPins[j], ~DisplayBuffer[i] >> j & 1);
        }
        //Turn on row to activate led.
        digitalWrite(RowPins[i], 1);

        //Uncomment the delay to increase brightness.  With 8 rows, any delay greater than 2 ms will cause flickering.  This is due to the refresh rate dropping below 60hz.
        //delayMicroseconds(2000);

        //Turn row back off.
        digitalWrite(RowPins[i], 0);
    }
}


//Updates the DisplayBuffer to the corresponding letter.  Letter can be either uppercase, 'A', or lowercase 'a'.
void SetDisplayLetter(char letter)
{
    //If letter supplied is an uppercase letter, subtract 65 to zero the letter so it can be used as an index. (The 'A' character has an integer value of 65)
    if(letter > 64 && letter < 91) letter -= 65;
    //If letter supplied is a lowercase letter, subtract 97 to zero the letter so it can be used as an index.  (The 'a' character has an integer value of 97)
    else if(letter > 96 && letter < 123) letter -= 97;
    //Letter supplied is not a lowercase or uppercase letter, print error to serial.
    else
    {
        Serial.println("Error - Function: 'DisplayLetter' Cause: Specified Letter character is not an alphabet character");
        return;
    }
    DisplayBuffer = Alphabet[letter];
}
void SetDisplayLetter(const char letter, const unsigned displayMilliseconds)
{
    SetDisplayLetter(letter);
    SetDisplayTiming(displayMilliseconds);
}

//If it's time to display the next letter, do so.
void TryToDisplayNextLetter()
{
    //Letter is currently displayed, now we can check to see if enough time has elapsed for us to turn it off.
    if(DisplayActive)
    {
        //If enough time has elapsed, turn off display to allow display of the next letter.
        if(millis() > DisplayLetterEndMilliseconds)
        {
            DisplayActive = false;
        }
        return;
    }
    SetDisplayLetter(AlphabetCharactersLower[DisplayIndex],200);
    //Counts up the index for the next letter.
    DisplayIndex++;
    //Reset the index to zero if we just displayed the last letter in the alphabet.
    if(DisplayIndex == 26) DisplayIndex = 0;
}

//This example does not use delays and is non-blocking.
void loop()
{
    while(true)
    {
        TryToDisplayNextLetter();
        UpdateDisplay();
    }

    //Add other code as necessary.
}
