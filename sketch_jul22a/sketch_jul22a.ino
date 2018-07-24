// Arduino 24h Binary Clock with Seconds. (17 LEDs total)
// You can find a demonstration video of this project
// here on Youtube: https://www.youtube.com/watch?v=R1rWMhTKyh0
// Full project on Hackter.io : https://www.hackster.io/peter-lunk/arduino-24h-binary-clock-with-seconds-17-leds-total-2c2374
// Greetings, MrLunk

// pins 2 - 13 are the regular digital pwm pins.
int ledPinsHr[] = {2, 3, 4, 5, 6, 7};
int ledPinsSec[] = {8, 9, 10, 11, 12, 13};

// pins 14 - 20 are the analog pins 0 - 5 used as digital pwm pins  
int ledPinsMin[] = {A0, A1, A2, A3, A4, A5};

// set Start time here
int countS = 0;   // Seconds
int countM = 13;  // Minutes
int countH = 23;  // Hours

byte countSec;
byte countMin;
byte countHr;
#define nBitsSec sizeof(ledPinsSec)/sizeof(ledPinsSec[0])
#define nBitsMin sizeof(ledPinsMin)/sizeof(ledPinsMin[0])
#define nBitsHr sizeof(ledPinsHr)/sizeof(ledPinsHr[0])

void setup(void)
{
  for (byte i = 0; i < nBitsSec; i++) {
    pinMode(ledPinsSec[i], OUTPUT);
  }

  for (byte i = 0; i < nBitsMin; i++) {
    pinMode(ledPinsMin[i], OUTPUT);
  }

  for (byte i = 0; i < nBitsHr; i++) {
    pinMode(ledPinsHr[i], OUTPUT);
  }
}

// ----- Main Routine -------------------------------------------------

void loop(void)
{
  countS = (countS + 1);
  if (countS > 59)
  {
    countS = 0;
    countM = (countM + 1);
    if (countM > 59)
    {
      countM = 0;
      countH = (countH + 1);
      if (countH > 23)
      {
        countH = 0;
        countM = 0;
        countS = 0;
      }
    }
  }

  dispBinarySec(countS);
  dispBinaryMin(countM);
  dispBinaryHr(countH);

  delay(1000);   // 1000 milliseconds = approx. 1 second delay
  // ADJUST for fast or slow running clock here, in milliseconds.
}

// ----- Subroutines ---------------------------------------------------

void dispBinarySec(byte nSec)
{
  for (byte i = 0; i < nBitsSec; i++) {
    digitalWrite(ledPinsSec[i], nSec & 1);
    nSec /= 2;
  }
}

void dispBinaryMin(byte nMin)
{
  for (byte i = 0; i < nBitsMin; i++) {
    digitalWrite(ledPinsMin[i], nMin & 1);
    nMin /= 2;
  }
}

void dispBinaryHr(byte nHr)
{
  for (byte i = 0; i < nBitsHr; i++) {
    digitalWrite(ledPinsHr[i], nHr & 1);
    nHr /= 2;
  }
}

