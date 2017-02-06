#include <time.h>
#include <stdlib.h>

int pot = A0;
int interval = 300;
int LEDS[4] = {3, 5, 6, 9};
int start = 0;
int randomNumber = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
  start = millis();

}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(pot);

  float pot_value = map(analogRead(pot), 0, 1023, 0, 255);
  //  Serial.println(pot_value);
  //  randomNumber = random(15);
  Serial.println(randomNumber);
  for (int i = 0; i < 4; i++) {
    analogWrite(LEDS[i], pot_value + random(20));

    delay(100);
  }

  if (millis() - start > interval || reading - pot_value > 10 ) {

    for (int i = 0; i < 4; i++) {
      for (int j = pot_value; j < 0; j--){
        analogWrite(LEDS[i], j);  
      }
    }

      delay(100);
    }

    start = millis();
  }

