#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define Servo_plus 2
#define Credits 7
#define Servo_minus 4
#define Lights 6
int s_angle = 60; // angle of the servo
int lock = 0; // 0 refers to unlocked (the other side controls), 1 refers to locked
int count = 0; // used for preset; 0 is 60 degrees, 1 is 0 degrees

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo mainservo;

void setup() {
  pinMode(Servo_plus, INPUT_PULLUP);
  pinMode(Servo_minus, INPUT_PULLUP);
  pinMode(Credits, INPUT_PULLUP);
  pinMode(Lights, INPUT_PULLUP);
  mainservo.attach(11);
  mainservo.write(180);
  delay(1000);
  mainservo.write(0);// home the servo
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.clear();
}
void loop() {
  if (s_angle < 0) // limit the servo to 0 degrees
  {
    s_angle = 0;
  }
  if (s_angle > 120) // limit the servo to 60 degrees
  {
    s_angle = 120;
  }
  if (digitalRead(Servo_plus) == HIGH) {
    s_angle = s_angle + 2; // change angle by 1
    mainservo.write(s_angle);
    delay(10); // to help the servo reach the desired position
  }
  if (digitalRead(Servo_minus) == HIGH) {
    s_angle = s_angle - 2; // change the angle by 1
    mainservo.write(s_angle);
    delay(10); // to help the servo reach the desired position
  }
  lcd.clear();
  lcd.print("Angle: ");
  lcd.print(s_angle - 60);
}

