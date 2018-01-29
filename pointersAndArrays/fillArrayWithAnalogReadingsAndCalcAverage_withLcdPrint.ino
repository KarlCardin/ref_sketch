// Use the softwareserial library to create a new "soft" serial port
// for the display.
#include <SoftwareSerial.h>

// Attach the serial display's RX line to digital pin 2
SoftwareSerial LCDserial(3,2); // pin 2 = TX, pin 3 = RX (unused)

#define arrayLength 5
int photoReadPin  = 0, photoPowerPin  = 5, startTime = 0;
float ave;
int readings[arrayLength]; 


void setup() 
{
  //Serial.begin(9600);
  LCDserial.begin(9600); // set up serial port for 9600 baud
  pinMode(photoPowerPin, OUTPUT);
}

void loop() 
{
  int sum = 0; //Reset sum value
  digitalWrite(photoPowerPin,HIGH);
  delay(300);
  ave = makeReadings(photoReadPin, photoPowerPin, readings);
  printValues(readings,ave);

}


/*****
Purpose: Fill array with reading from analog pin and calculate average
Parameter List:
int readPin analog input from votage divider
int powpin digital pin that give power to voltage divider
int *value pointer to the array that will hold values
Return value:
Average of readings
*****/
float makeReadings (int readPin, int powpin, int *value) 
{
  float sum = 0;
  for (int i = 0; i<arrayLength; i ++)
    {
       *(value+i) = analogRead(readPin);
       sum += *(value+i);
    }
  float ave = sum/arrayLength;
  digitalWrite(powpin,LOW);
  delay(100);
  return ave;
}

/*****
Purpose: Print readable array of values and the average to serial LCD
Parameter List:
int *readings pointer to the array holding readings
float ave the average of all the values in the readings array
Return value:
n/a
*****/
void printValues(int *value, float ave)
{
  char charBuf[50];
  String string;
  string += ("[");
    for(int i = 0; i < arrayLength ; i++)
    {
     string += (*(value+i));
      if(i < arrayLength-1)
      {
      string += (", ");
      }
    }
  string += ("] ave=");
  string += (ave);
  //Serial.println(string);  
  string.toCharArray(charBuf, 50);
  LCDserial.write(254); // cursor to beginning of first line
  LCDserial.write(128);
  LCDserial.write(charBuf);
}


 

