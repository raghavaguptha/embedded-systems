
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns

//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //R1,R2,R3,R4
byte colPins[COLS] = {6, 7, 8}; //C1,C2,C3,C4

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup()
{
  Serial.begin(9600);
}
  
void loop()
{
  char customKey = customKeypad.getKey();
  
  if (customKey)
  {
    Serial.println(customKey);
  }
}
