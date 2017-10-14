#include <Adafruit_NeoPixel.h>

short red   = 0;
short green = 0;
short blue  = 0;
short minRandom = 0;
short maxRandom = 255;
unsigned int counterBridge1 = 0;
int counterBridge2 = 19;
Adafruit_NeoPixel stripBridge1 = Adafruit_NeoPixel(10, 10, NEO_GRB + NEO_KHZ800); //Number of leds, Pin, constants of the library
Adafruit_NeoPixel stripBridge2 = Adafruit_NeoPixel(20, 9, NEO_GRB + NEO_KHZ800); //Number of leds, Pin, constants of the library


void setup() {
  stripBridge1.begin(); //Inicializa los leds
  stripBridge2.begin();
  stripBridge1.setBrightness(3); //Para no encandilarse
  stripBridge2.setBrightness(3); //Para no encandilarse   
  stripBridge1.show(); //Muestra los leds
  stripBridge2.show();
}
 
void loop() {

  if(counterBridge1 > 9){
    counterBridge1 = 0;
  }
  else {
    counterBridge1 = counterBridge1 + 1;
  }
  if(counterBridge2 < 0){
    counterBridge2 = 19;
  }
  else {
    counterBridge2 = counterBridge2 - 1;
  }  
  
  red = random(minRandom, maxRandom);
  green = random(minRandom, maxRandom);
  blue = random(minRandom, maxRandom);
  stripBridge1.setPixelColor(counterBridge1,green,red,blue); //Coloca los colores en en el led counterBridges; 
  stripBridge2.setPixelColor(counterBridge2,green,red,blue);
  stripBridge1.setPixelColor(counterBridge1-1,0,0,0);
  stripBridge2.setPixelColor(counterBridge2+1,0,0,0);
  stripBridge1.show();
  stripBridge2.show();
  delay(100);
}
