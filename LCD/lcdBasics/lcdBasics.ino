#include <SoftwareSerial.h>

// Attach the serial display's RX line to digital pin 2
SoftwareSerial LCDserial(3,2); // pin 2 = TX, pin 3 = RX (unused)

// ---------------------------------------------------------------

void setup()
{ 

/*****
Purpose: convert int to char array so that it can be
printed on the LCD
*****/

  int printInt = 1001;
  char printInt_string[10]; 
  sprintf(printInt_string,"%4d",printInt);

/*****
Purpose: convert float to char array so that it can be
printed on the LCD
*****/
  
  float printFloat = 96.0;
  char printFloat_string[20];
  dtostrf(printFloat,5,2,printFloat_string);

/*****
Purpose: combine multiple char arrays
*****/
  strcat( printFloat_string, " and ");
  strcat( printFloat_string,printInt_string);
  LCDserial.begin(9600); // set up serial port for 9600 baud
  delay(500);            // wait for display to boot up

/*****
Purpose: basic lcd specific commands
*****/

  LCDserial.write(254); // clear the screen
  LCDserial.write(1);
  LCDserial.write(254); //Turn on blinking cursor
  LCDserial.write(13);


/*****
Purpose: Use loop to track across each cursor position
*****/

  for(int i = 128; i <= 167; i++)
  {
    LCDserial.write(254);
    LCDserial.write(i);
    delay(150);
  }

    for(int i = 192; i <= 231; i++)
  {
    LCDserial.write(254);
    LCDserial.write(i);
    delay(150);
  }


/*****
Purpose: print the char that we created and turn off the blinking cursor
*****/
  LCDserial.write(254); 
  LCDserial.write(128);
  LCDserial.write(printFloat_string);
  
  LCDserial.write(254); 
  LCDserial.write(0x0C); //Hide cursor
  
  delay(1000);
  

} 



// ------------------------------------------------------------

void loop() 
{ 
  
}




