//Libraries to use - LedControl

//DIN goes to D0 (NODEMCU)
//CS goes to D1 (NODEMCU)
//CLK goes to D2 (NODEMCU)

//Written by Pranav Verma
//https://g.dev/pranavverma

#include <LedControl.h>

int DIN = 16; // D0

int CS =  5;  // D
int CLK = 4;  // D2

LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){

  lc.shutdown(0,false);     //The MAX72XX is in power-saving mode on startup

  lc.setIntensity(0,15);     // Set the brightness to maximum value

  lc.clearDisplay(0);        // and clear the display

}

void loop() {

    byte a[8] = {0xff,0xff,0xc3,0xc3,0xff,0xff,0xc0,0xc0};  // P
    byte b[8] = {0xff,0xff,0xc3,0xc3,0xff,0xf0,0xde,0xc3};     // R
    byte c[8] = {0xff,0xff,0xc3,0xc3,0xff,0xff,0xc3,0xc3};   // A
    byte d[8] = {0xe3,0xf3,0xd3,0xdb,0xcb,0xcb,0xcf,0xc7}; // N
    byte e[8] = {0xff,0xff,0xc3,0xc3,0xff,0xff,0xc3,0xc3};    // A
    byte k[8] = {0xc3,0xc3,0xc3,0xc3,0xc3,0xe7,0x18,0x18};    // V
    
   
    printByte(a);
    delay(1000);
    printByte(b);
    delay(1000);
    printByte(c);
    delay(1000);
    printByte(d);
    delay(1000);
    printByte(e);
    delay(1000);
    printByte(k);
    delay(1000);

}

void printByte(byte character []){
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
