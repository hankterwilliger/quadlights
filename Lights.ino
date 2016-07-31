// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
//#include <Serial.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      14

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
char incomingByte ;
int delayval = 500; // delay for half a second
int leftStart = 1;
int leftEnd = 7;
int rightStart = leftEnd + 1;
int rightEnd = leftEnd + 7;
int frontStart = rightEnd + 1;
int frontEnd = rightEnd + 7;
int backStart = frontEnd + 1;
int backEnd = frontEnd + 7;
int black[] = {0,0,0};
int blue = 1;
int red = 2;
int orange = 3;
int yellow = 4;
int green[] = {0,150,0};
int white[] = {255,255,255};

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);
//  showLights(black,leftStart,backEnd);   
}


void showGreenLights(int Start, int End){
  Serial.println(Start);
  Serial.println(End);
  Serial.println("Green");
  for (int i=Start;i<=End;i++){
    pixels.setPixelColor(i-1, pixels.Color(0,255,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(50); // Delay for a period of time (in milliseconds).
  }
}

void showYellowLights(int Start, int End){
  Serial.println(Start);
  Serial.println(End);
  Serial.println("Yellow");
  for (int i=Start;i<=End;i++){
    pixels.setPixelColor(i-1, pixels.Color(255,100,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(50); // Delay for a period of time (in milliseconds).
  }
}

void showRedLights(int Start, int End){
  Serial.println(Start);
  Serial.println(End);
  Serial.println("Green");
  for (int i=Start;i<=End;i++){
    pixels.setPixelColor(i-1, pixels.Color(255,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(50); // Delay for a period of time (in milliseconds).
  }
}

void showBlueLights(int Start, int End){
  Serial.println(Start);
  Serial.println(End);
  Serial.println("Green");
  for (int i=Start;i<=End;i++){
    pixels.setPixelColor(i-1, pixels.Color(0,0,255));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(50); // Delay for a period of time (in milliseconds).
  }
}


void offGreenLights(int Start, int End){
  Serial.println(Start);
  Serial.println(End);
  Serial.println("Green");
  for (int i=End;i>=Start;i--){
    pixels.setPixelColor(i-1, pixels.Color(0,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(50); // Delay for a period of time (in milliseconds).
  }
}
void blinkLights(int Start, int End){
  for ( int j=0;j<=10;j++ ){
  for (int i=Start;i<=End;i++){
    int c1 = random(0, 255) ;
    int c2 = random(0, 255) ;
    int c3 = random(0, 255) ;
    
    pixels.setPixelColor(i-1, pixels.Color(c1,c2,c3));
    pixels.show(); // This sends the updated pixel color to the hardware.
//    delay(delayval); // Delay for a period of time (in milliseconds).
  }
  delay(100);
  for (int i=Start;i<=End;i++){  
    pixels.setPixelColor(i-1, pixels.Color(0,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  delay(100);  
}  
}


void showWhiteLights(int Start, int End){
  Serial.println(Start);
  Serial.println(End);
  Serial.println("White");
  for (int i=Start;i<=End;i++){
    pixels.setPixelColor(i-1, pixels.Color(150,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
//    delay(delayval); // Delay for a period of time (in milliseconds).
  }
}

void showNoLights(int Start, int End){
  for (int i=End;i>=Start;i--){
    pixels.setPixelColor(i-1, pixels.Color(0,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(75); // Delay for a period of time (in milliseconds).
  }
}

void showLights(int Color, int Start, int End){
  for (int i=Start;i<=End;i++){
    pixels.setPixelColor(i-1, pixels.Color(0,150,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
//    delay(delayval); // Delay for a period of time (in milliseconds).
  }
}


void loop() {
   if (Serial.available() > 0) {
    incomingByte = Serial.read(); // read the incoming byte:
    Serial.print(" I received:");
    Serial.println(incomingByte);
    switch (incomingByte) {
      case 'D':
        showBlueLights(leftStart,rightEnd);
        delay(1000);
        showNoLights(leftStart,rightEnd); 
        break;      
      case 'd':
        showBlueLights(leftStart,rightEnd);
        delay(1000);
        showNoLights(leftStart,rightEnd); 
        break;             
      case 'U':
        showYellowLights(leftStart,rightEnd);
        delay(1000);
        showNoLights(leftStart,rightEnd); 
        break;      
      case 'u':
        showYellowLights(leftStart,rightEnd);
        delay(1000);
        showNoLights(leftStart,rightEnd); 
        break;    
      case 'L':
        showGreenLights(leftStart,leftEnd);
        delay(1000);
        showNoLights(leftStart,backEnd); 
        break;
      case 'l':
        showGreenLights(leftStart,leftEnd);
        delay(1000);
        showNoLights(leftStart,backEnd); 
        break;
      case 'R':
        showRedLights(rightStart,rightEnd);
      delay(1000);
        showNoLights(leftStart,backEnd); 
        break;
      case 'r':
        showRedLights(rightStart,rightEnd);
      delay(1000);
        showNoLights(leftStart,backEnd); 
        break;      case 'B':
        showRedLights(backStart,backEnd);
        delay(1000);
        showNoLights(leftStart,backEnd); 
        break;
      case 'X':
        blinkLights(leftStart,backEnd);
        delay(1000);
        showNoLights(leftStart,backEnd); 
        break;        
      case 'x':
         blinkLights(leftStart,backEnd);
        delay(1000);
        showNoLights(leftStart,backEnd); 
        break;                
      default:
        showNoLights(leftStart,backEnd); 
        delay(1000);      
        showNoLights(leftStart,backEnd); 
        break;
    }
  }
}


// For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

//  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//  pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.

//   pixels.show(); // This sends the updated pixel color to the hardware.

//   delay(delayval); // Delay for a period of time (in milliseconds).

//  }
//}
