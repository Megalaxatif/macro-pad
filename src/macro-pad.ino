#include <Keyboard.h>


const int ROWS = 4;
const int COLS = 4;

const char key_map[ROWS][COLS] = {
  {'a', 'b', 'c', 'd'},
  {'h', 'g', 'f', 'e'},
  {'i', 'j', 'k', 'l'},
  {'p', 'o', 'n', 'm'}
};

const int col_pin[COLS] = {9, 8, 7, 6};
const int row_pin[ROWS] = {5, 4, 3, 2};


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
        Keyboard.write(key_map[i][j]); // we write the character on the keyboard once
        //Serial.println(key_value_array[i][j]);
        while (digitalRead(col_pin[j]) == LOW){}; // wait for the key to be released to avoid spam
      }
    }
    digitalWrite(row_pin[i], HIGH);
  }
  delay(10); // short delay
}