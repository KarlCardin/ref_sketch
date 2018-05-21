#include <SoftwareSerial.h>

// Attach the serial display's RX line to digital pin 2
SoftwareSerial LCDserial(3,2); // pin 2 = TX, pin 3 = RX (unused)


int valvePin;
float openTime;

void setup() {
  // put your setup code here, to run once:
LCDserial.begin(9600); // set up serial port for 9600 baud
Serial.begin(9600);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
}

void loop() {
someFunction(valvePin,openTime);
Serial.print("The valve pin is: ");Serial.println(valvePin);
Serial.print("Open the valve for: ");Serial.println(openTime);

char openTime_string[30];
dtostrf(openTime,5,2,openTime_string);
LCDserial.write(254); 
LCDserial.write(1);
LCDserial.write(254); 
LCDserial.write(128);
LCDserial.write("Open valve for: ");
LCDserial.write(254); 
LCDserial.write(192);
LCDserial.write(openTime_string);
LCDserial.write(254); 
LCDserial.write(200);
LCDserial.write("ms");
}

void someFunction(int &valvePin, float &openTime){
Serial.println("########## Start Function ##########");
//reading = analogRead(salPin)
float x_a,x_o,m_a;

float x_f=.120;
float x_i= 100;
if(x_i <= 100){
	x_i = 5E-4*x_i;
}else{
	x_i = 2.5E-4*(x_i-100)+0.05;
}
Serial.print("The initial salinity is: ");Serial.println(x_i);
Serial.print("The target salinity is: ");Serial.println(x_f);
Serial.print("The error of the system is: ");Serial.println(x_f-x_i); //Desired - current
if (x_i<x_f){
x_a = 1;
valvePin = 6;	
}else{
x_a = 0;
valvePin = 7;		
}
Serial.print("So we will add: ");Serial.print(x_a);Serial.println("% NaCl");

x_o = 0.15*x_a+0.85*x_i;
m_a = 100*((x_f-x_i)/(x_a-x_o));
openTime = (m_a/2)*1000;
Serial.print("We will add: ");Serial.print(m_a);Serial.println("g");
Serial.println("########## End Function ##########");
}

