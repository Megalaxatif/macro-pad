#include <Keyboard.h>

const int ROWS = 4;
const int COLS = 4;
// map of the macro pad
const uint8_t key_map[ROWS][COLS] = {
  KEY_F1, KEY_F2, KEY_F3, KEY_F4,
  KEY_F8, KEY_F7, KEY_F6, KEY_F5,
  KEY_F9, KEY_F10, KEY_F11, KEY_F12,
  KEY_F1, KEY_F2, KEY_F3, KEY_F4
};

const int col_pin[COLS] = {9, 8, 7, 6}; // plug the column cables on these pin
const int row_pin[ROWS] = {5, 4, 3, 2}; // plug the row cables on these pin


void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  // declare all the rows as output
  for (int i = 0; i < ROWS; i++){
    pinMode(row_pin[i], OUTPUT);
  }
  // declare all the colums as input pullup
  for (int i = 0; i < COLS; i++){
    pinMode(col_pin[i], INPUT_PULLUP);
  }
}

void loop() {
  // browse the lines
  for (int i = 0; i < ROWS; i++){
    digitalWrite(row_pin[i], LOW);
    // browse the colums
    for (int j = 0; j < COLS; j++){
      if (digitalRead(col_pin[j]) == LOW){ // if the key has just been pressed
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(key_map[i][j]);
        delay(35);
        Keyboard.releaseAll();
      }
    }
    digitalWrite(row_pin[i], HIGH);
  }
  delay(10); // short delay
}