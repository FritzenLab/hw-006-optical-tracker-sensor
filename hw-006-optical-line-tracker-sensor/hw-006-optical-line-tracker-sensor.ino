#include <Adafruit_NeoPixel.h>
#define D_in D4
#define ledamount 1
Adafruit_NeoPixel pixels(ledamount, D_in);

long currenttime;
long oldtime;

void setup() {
  // put your setup code here, to run once:
  pinMode(D5, INPUT);
  pixels.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  currenttime= micros();
  if(currenttime - oldtime > 20000){ //only enters the program every 20ms
    oldtime= micros();
    if(digitalRead(D5)){
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(255, 0, 0)); // detection, lights red
      pixels.show();
    }else{
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(0, 0, 255)); // no detection, lights blue
      pixels.show(); 
    }
  }
}
