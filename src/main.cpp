//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

#define BELL_CHAR 0
#define NOTE_CHAR 1
#define CLOCK_CHAR 2
#define HEART_CHAR 3
#define DUCK_CHAR 4
#define CHECK_CHAR 5
#define CROSS_CHAR 6
#define ARROW_CHAR 7

#define BOX_CHAR 8

uint8_t bell[8] = {0x4, 0xe, 0xe, 0xe, 0x1f, 0x0, 0x4};
uint8_t note[8] = {0x2, 0x3, 0x2, 0xe, 0x1e, 0xc, 0x0};
uint8_t clock[8] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};
uint8_t heart[8] = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};
uint8_t duck[8] = {0x0, 0xc, 0x1d, 0xf, 0xf, 0x6, 0x0};
uint8_t check[8] = {0x0, 0x1, 0x3, 0x16, 0x1c, 0x8, 0x0};
uint8_t cross[8] = {0x0, 0x1b, 0xe, 0x4, 0xe, 0x1b, 0x0};
uint8_t retarrow[8] = {0x1, 0x1, 0x5, 0x9, 0x1f, 0x8, 0x4};

uint8_t box[8] = {
        B11111,
        B10001,
        B10001,
        B10001,
        B10001,
        B10001,
        B10001,
        B11111
};

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void createChars() {
  lcd.createChar(BELL_CHAR, bell);
  lcd.createChar(NOTE_CHAR, note);
  lcd.createChar(CLOCK_CHAR, clock);
  lcd.createChar(HEART_CHAR, heart);
  lcd.createChar(DUCK_CHAR, duck);
  lcd.createChar(CHECK_CHAR, check);
  lcd.createChar(CROSS_CHAR, cross);
  lcd.createChar(ARROW_CHAR, retarrow);

  // BC! Create char is limited to 8 symbols max
  // TODO: make some cache
  lcd.createChar(BOX_CHAR, box);
}
void setup() {
  lcd.init();                      // initialize the lcd
  lcd.backlight();

  createChars();
  lcd.home();
}

void helloWorld() {
    lcd.clear();

    lcd.print("Hello world...");
    lcd.setCursor(0, 1);
    lcd.print(" i ");
    lcd.printByte(HEART_CHAR);
    lcd.print(" Liquid Crystal!");

    delay(5000);
}

// display all keycodes
void displayKeyCodes() {
  uint8_t i = 0;
  while (i < 0xFF) {
    lcd.clear();
    lcd.print("Codes 0x");
    lcd.print(i, HEX);
    lcd.print("-0x");
    lcd.print(i + 15, HEX);
    lcd.setCursor(0, 1);
    for (int j = 0; j < 16; j++) {
      lcd.printByte(i + j);
    }
    i += 16;

    delay(4000);
  }
}

void writeChars() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Here are custom chars:");

    lcd.noCursor();
    lcd.setCursor(0, 1);
    lcd.cursor();
    lcd.write(BELL_CHAR);
    lcd.write(NOTE_CHAR);
    lcd.write(CLOCK_CHAR);
    lcd.write(HEART_CHAR);
    lcd.write(DUCK_CHAR);
    lcd.write(CHECK_CHAR);
    lcd.write(CROSS_CHAR);
    lcd.write(ARROW_CHAR);
    lcd.write(BOX_CHAR);

    lcd.noCursor();
    lcd.setCursor(0, 1);
    lcd.cursor();

    delay(5000);
}

void loop() {
  helloWorld();
  writeChars();
  displayKeyCodes();
}
