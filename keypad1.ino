#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;
string message = "hi";
char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup()
{
    Serial.begin(9600);
	lcd.begin();

	lcd.backlight();
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Welcome");
}

void loop()
{
    char keyPressed = customKeypad.waitForKey();
    message += keyPressed;
    lcs.clear();
    lcd.print(message);
}