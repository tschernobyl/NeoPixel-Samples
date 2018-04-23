/********************************************************************************************************
  neopixel_bright:
  Written by Scott Kildall
  remixed by emalstm for celebration of Dutch Koningsdag
  Royal Orange fading sketch for LED wearable
  
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
int numPixels = 9;

// Instatiate the NeoPixel from the ibrary
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, neoPixelPin, NEO_GRB + NEO_KHZ800);

// Global RGB values, #royal dutch
int r = 255;
int g = 79;
int b = 0;

// pin for input, not used
int switchPin = 4;

// variables to control brightness levels
int brightness = 50; 
int brightDirection = -3;

// a pre-processor macro
#define DELAY_TIME (100)

void setup() {
  strip.begin();  // initialize the strip
  strip.show();   // make sure it is visible
  strip.clear();  // Initialize all pixels to 'off'
  
  // initialize the serial monitor
  Serial.begin(9600);
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
  strip.clear();    // this is a simpler way to turn all the pixels off
  strip.show();
}

// the activate function will set the pixel color, change the brightness level
// and have a small delay
void activate() {   
  for( int i = 0; i < numPixels; i++ ) 
     strip.setPixelColor(i, r,g,b);
     
  strip.setBrightness(brightness);  
  strip.show();
  
  adjustBrightness();
}

// function which will increment or decrement the brightness level
void adjustBrightness() {
  brightness = brightness + brightDirection;
  if( brightness < 0 ) {
     brightness = 0;
     brightDirection = -brightDirection;
  }
  else if( brightness > 80 ) {
     brightness = 80;
     brightDirection = -brightDirection;
  } 
  
  // output the serial
  Serial.println( brightness );
}
