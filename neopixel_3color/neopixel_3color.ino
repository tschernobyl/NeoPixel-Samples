/********************************************************************************************************
  neopixel_3color:
  Written by Scott Kildall
  
  This sketch will show three bands of solid colors on the NeoPixel strip
  the 1st 1/3 will be 1 color, the 2nd 1/3 another, and the last 1/3 a different color
  A switch at pin 4 will turn the whole strip off
  
---------------------------------------------------------------------------------------------------------
NeoPixel Information for initializing the strip, below
  60ma/pixel for current load
  Parameter 1 = number of pixels in strip
  Parameter 2 = pin number (most are valid)
  Parameter 3 = pixel type flags, add together as needed:
    NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
    NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
    NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
    NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
**********************************************************************************************************/

#include <Adafruit_NeoPixel.h>
 
// the data pin for the NeoPixels
int neoPixelPin = 0;

// How many NeoPixels we will be using, charge accordingly
int numPixels = 20;

// Instatiate the NeoPixel from the ibrary
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, neoPixelPin, NEO_GRB + NEO_KHZ800);

//Dutch flag colors
// Color set RED
int r1 = 255;
int g1 = 0;
int b1 = 0;

// Color set WHITE
int r2 = 255;
int g2 = 255;
int b2 = 255;

// Color set BLUE
int r3 = 0;
int g3 = 0;
int b3 = 255;



// our button - not used in my program but the sketch doesn't work without
int switchPin = 4;

// a pre-processor macro
#define DELAY_TIME (10)

void setup() {
  strip.begin();  // initialize the strip
  strip.show();   // make sure it is visible
  strip.clear();  // Initialize all pixels to 'off'
  strip.setBrightness(50);  //Set a more reasonable brightness - but if we're using in daylight maybe we should ramp it up

}

void loop() {
  // Check to see if switch is on/off and call the proper function
  if( digitalRead(switchPin) == true )
     allOff();
  else
     activate();
     
  // delay for the purposes of debouncing the switch
  delay(DELAY_TIME);
}

// Turns all the NeoPixels off
void allOff() {
  strip.clear();
  strip.show();
}

// turn 1/3 of strip different colors. this is a crude, but effective way to do this.
void activate() {
   // first 1/3 pixels = color set #1
    for( int i = 0; i < 8 ; i++ ) {
       strip.setPixelColor(i, r1, g1, b1 );
    }
    
    // next 1/3 pixels = color set #2
    for( int i = 8; i < 13 ; i++ ) {
       strip.setPixelColor(i, r2, g2, b2 );
    }
    
     // last 1/3 pixels = color set #3
    for( int i = 13; i < 20; i++ ) {
       strip.setPixelColor(i, r3, g3, b3 );
    }
      
  strip.show();
}
