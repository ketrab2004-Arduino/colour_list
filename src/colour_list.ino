#include <stdint.h>
#include <SPI.h>
#include <Wire.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include <Colouring.h>

#define DEBUG 0
#include <Extra_Debug.h>

#define TFT_CS 10
#define TFT_DC 9
#define TFT_BL 5
#define SD_CS 4

#define WIDTH 320
#define HEIGHT 240
#define BRIGHTNESS 127

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
//Adafruit_FT6206 ts = Adafruit_FT6206();

void setup() {
    debugBegin(115200);
    tft.begin();
    //ts.begin();

    pinMode(TFT_BL, OUTPUT);
    analogWrite(TFT_BL, BRIGHTNESS);

    tft.setRotation(1);

    tft.fillScreen(ILI9341_BLACK);
}

uint16_t colour = 0;
uint16_t xPos = 0;
uint16_t yPos = 0;
void loop() {
    tft.drawPixel(xPos, yPos, colour);

    debug("X: ");
    debugln(xPos);

    debug("Y: ");
    debugln(yPos);

    debug("C: ");
    debugln(colour);
    
    debugln("===============");

    colour++;

    if (yPos >= HEIGHT) {
        yPos = 0;
    } else {
        if (xPos >= WIDTH) {
            xPos = 0;
            yPos++;
        } else {
            xPos++;
        }
    }
}
