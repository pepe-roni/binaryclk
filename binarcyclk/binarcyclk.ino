//array of LED pins for seconds and minutes(PWM)
//skip pins 1 and 0, reserved for TX and RX
uint8_t secPins[] = {2, 3, 4, 5, 6, 7};
uint8_t minPins[] = {8, 9, 10, 11, 12, 13};

//the LED pins for hours are on analog pins 0-5 (PWM)
uint8_t hourPins[] = {14, 15, 16, 17, 18, 19};

//Set the Upload Time, the local time at which the arduino will start ticking at
uint8_t sec = 0;
uint8_t mins = 58;
uint8_t hour = 23;

void setup() {
  //sets up all LED pins to output
  for (unsigned char i = 0; i < 6; i++)
  {
    pinMode(secPins[i], OUTPUT);
    pinMode(minPins[i], OUTPUT);
    pinMode(hourPins[i], OUTPUT);
  }
}

//Runs repeatedly, adjust the delay to compensate for +- in clock speeds
void loop() {
  sec++;
  //everytime sec is 60, mins increases by one and sec is reset
  if (sec == 60) {
    sec = 0 ;
    mins++;
    //everytime mins is 60, hour increases by one and mins is reset
    if (mins == 60) {
      mins = 0;
      hour++;
      if (hour == 24) {
        //when hour is 24, all time variables are reset
        hour = 0;
        sec = 0;
        mins = 0;
      }
    }
  }
  secDisp(sec);
  minsDisp(mins);
  hourDisp(hour);
  //change this if your clock runs slower or faster than expected
  delay(1000);
}


//displays the second LEDs 
void secDisp(unsigned char secBinary){
  //this switches the bits according to the time input using a bitwise AND operator (&)
  for(unsigned char i = 0; i < sizeof(secPins); i++){
    digitalWrite(secPins[i], secBinary &1);
    secBinary /=2;
  }
}

void minsDisp(unsigned char minsBinary){
  //this switches the bits according to the time input using a bitwise AND operator (&)
  for(unsigned char i = 0; i < sizeof(minPins); i++){
    digitalWrite(minPins[i], minsBinary &1);
    minsBinary /=2;
  }
}
void hourDisp(unsigned char hourBinary){
  //this switches the bits according to the time input using a bitwise AND operator (&)
  for(unsigned char i = 0; i < sizeof(hourPins); i++){
    digitalWrite(hourPins[i], hourBinary &1);
    hourBinary /=2;
  }
}
