//program designed to test LEDS connected to pin

uint8_t ledPins[] = {18,19,20,21,23};

void setup() {
  for(unsigned char i=0; i<5; i++){
    pinMode(ledPins[i], OUTPUT);
  }

}

void loop() {
  for(unsigned char i=0; i<5; i++){
    digitalWrite(ledPins[i],HIGH);
    delay(500);
    digitalWrite(ledPins[i],LOW);
    delay(500);
  }
}
