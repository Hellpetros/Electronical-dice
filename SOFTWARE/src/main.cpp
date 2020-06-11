#include <Arduino.h>

#define LED_TOPLEFT 8
#define LED_TOPCENTER 7
#define LED_TOPRIGHT 6

#define LED_CENTER 5

#define LED_BOTLEFT 2
#define LED_BOTCENTER 3
#define LED_BOTRIGHT 4

#define BUTTON 9

long led_count = 0;

void clear_leds();
void set_leds(long led_count_i);

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");

  pinMode(LED_TOPLEFT, OUTPUT);
  pinMode(LED_TOPCENTER, OUTPUT);
  pinMode(LED_TOPRIGHT, OUTPUT);

  pinMode(LED_CENTER, OUTPUT);

  pinMode(LED_BOTLEFT, OUTPUT);
  pinMode(LED_BOTCENTER, OUTPUT);
  pinMode(LED_BOTRIGHT, OUTPUT);

  pinMode(BUTTON, OUTPUT);

  clear_leds();
}

void loop() {
  if(digitalRead(BUTTON) == HIGH){
    led_count = random(1, 7);
    set_leds(led_count);
    delay(300);

    led_count = random(1, 7);
    set_leds(led_count);
    delay(300);

    led_count = random(1, 7);
    Serial.print("Random number is:  "); Serial.println(led_count);
    set_leds(led_count);
    delay(500);
  }
}

void clear_leds(){
  digitalWrite(LED_TOPLEFT, LOW);
  digitalWrite(LED_TOPCENTER, LOW);
  digitalWrite(LED_TOPRIGHT, LOW);

  digitalWrite(LED_CENTER, LOW);
  
  digitalWrite(LED_BOTLEFT, LOW);
  digitalWrite(LED_BOTCENTER, LOW);
  digitalWrite(LED_BOTRIGHT, LOW);

  Serial.println("Leds cleared...");
}

void set_leds(long led_count_i){
  clear_leds();
  switch (led_count_i)
  {
  case 1:
    digitalWrite(LED_CENTER, HIGH);
    break;
  
  case 2:
    digitalWrite(LED_BOTLEFT, HIGH);
    digitalWrite(LED_TOPRIGHT, HIGH);
    break;

  case 3:
    digitalWrite(LED_BOTLEFT, HIGH);
    digitalWrite(LED_CENTER, HIGH);
    digitalWrite(LED_TOPRIGHT, HIGH);
    break;
  
  case 4:
    digitalWrite(LED_BOTLEFT, HIGH);
    digitalWrite(LED_BOTRIGHT, HIGH);

    digitalWrite(LED_TOPLEFT, HIGH);
    digitalWrite(LED_TOPRIGHT, HIGH);
    break;

  case 5:
    digitalWrite(LED_BOTLEFT, HIGH);
    digitalWrite(LED_BOTRIGHT, HIGH);

    digitalWrite(LED_CENTER, HIGH);

    digitalWrite(LED_TOPLEFT, HIGH);
    digitalWrite(LED_TOPRIGHT, HIGH);
    break;

  case 6:
    digitalWrite(LED_BOTLEFT, HIGH);
    digitalWrite(LED_BOTCENTER, HIGH);
    digitalWrite(LED_BOTRIGHT, HIGH);

    digitalWrite(LED_TOPLEFT, HIGH);
    digitalWrite(LED_TOPCENTER, HIGH);
    digitalWrite(LED_TOPRIGHT, HIGH);
    break;

  default:
    break;
  }
}