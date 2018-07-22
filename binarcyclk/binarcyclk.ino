//array of LED pins for seconds and minutes(PWM)
//skip pins 1 and 0, reserved for TX and RX
unsigned char secPins[] = {2, 3, 4, 5, 6, 7};
unsigned char minPins[] = {8, 9, 10, 11, 12, 13};

//the LED pins for hours are on analog pins 0-5 (PWM)
unsigned char hourPins[] = {14, 15, 16, 17, 18, 19};

//Set the Upload Time, the local time at which the arduino will start ticking at
unsigned char sec = 0;
unsigned char mins = 35;
unsigned char hour = 18;

void setup() {
  //sets up all LED pins to output
  for (unsigned char i = 0; i < 6; i++)
  {
    pinMode(secPins[i], OUTPUT);
    pinMode(minPins[i], OUTPUT);
    pinMode(hourPins[i], OUTPUT);
  }
  Serial.begin(9400);
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
  Serial.print(hour);
  Serial.print(":");
  Serial.print(mins);
  Serial.print(":");
  Serial.print(sec);
  Serial.println();
  
  delay(1000);


}
