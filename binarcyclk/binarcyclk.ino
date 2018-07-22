//array of LED pins for seconds and minutes(PWM)
//skip pins 1 and 0, reserved for TX and RX
int secPins[] = {2,3,4,5,6,7};
int minPins[] = {8,9,10,11,12,13};

//the LED pins for hours are on analog pins 0-5 (PWM)
int hourPins[] = {14,15,16,17,18,19};

//Set the Upload Time, the local time at which the arduino will start ticking at
int startSec = 0;
int startMin = 35;
int startHour = 18;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
