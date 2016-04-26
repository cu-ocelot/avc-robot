// serial_lcd_test.ino
// Basic serial LCD testing
// Print basic character set and a rolling counter

// Requires SoftwareSerial
#include <SoftwareSerial.h>

// Attach the serial display's RX line to digital pin 2
SoftwareSerial lcdSerial(3,2); // pin 2 = TX, pin 3 = RX (unused)

int x = 0;

void setup() {
  lcdSerial.begin(9600);
  delay(500); // wait for display to boot up
  
  lcdSerial.write(254); // move cursor to beginning of first line
  lcdSerial.write(128);
  lcdSerial.write("                "); // clear display
  lcdSerial.write("                ");

  lcdSerial.write(254); // move cursor to beginning of first line
  lcdSerial.write(128);
 
  lcdSerial.write("ABCDEF1234567890");
  lcdSerial.write("!@#$%^&*()-=");
}

void loop() {
  char buf[4];
  sprintf(buf,"%4d",x);
  x = (x >= 9999)?0:(x+1);
  lcdSerial.write(254); // move cursor to 2:13
  lcdSerial.write(204);
  lcdSerial.write(buf);
  delay(10);
}

