#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4;
const byte COLS = 4;
LiquidCrystal lcd(28,30,32,34,36,38);

char keys[ROWS][COLS] = {
  {'1','4','7','.'},
  {'2','5','8','0'},
  {'3','6','9','F'},
  {'P','N','C','S'}
};
byte pin_rows[ROWS] = {29,31,33,35};
byte pin_column[COLS] = {37,39,41,43};

Keypad customKeypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.println("This is test 1");
    
}

void loop() {
  char key = customKeypad.getKey();
  if (key) {
    if (key == 'P') {
      lcd.println("Previous");
      delay(1000);
      lcd.clear();
    } else if (key == 'N') {
      lcd.println("Next");
      delay(1000);
      lcd.clear();
    } else if (key == 'C') {
      lcd.println("Clear");
      delay(1000);
      lcd.clear();
    } else if (key == 'S') {
      lcd.println("Save");
      delay(1000);
      lcd.clear();
    } else {
      lcd.println(key);
      delay(1000);
      lcd.clear();
    }
  }
}
