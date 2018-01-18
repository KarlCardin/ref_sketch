/*
Purpose: find the minimum and maximum values of an array of
data values
Dr. Purdum, Nov. 22, 2014
*/

#include <stdio.h>
int todaysReadings[] = { 62, 64, 65, 80, 59};

void setup() {
int lowTemp;
int hiTemp;
int retVal;
Serial.begin(9600);
Serial.println("=== Before function call:");
Serial.print("The lvalue for lowTemp is: ");
Serial.print((long) &lowTemp, DEC);
Serial.print(" and the rvalue is ");
Serial.println((long) lowTemp, DEC);
Serial.print("The lvalue for hiTemp is: ");
Serial.print((long) &hiTemp, DEC);
Serial.print(" and the rvalue is ");
Serial.println((long) hiTemp, DEC);
retVal = CalculateMinMax(todaysReadings, &lowTemp, &hiTemp);
Serial.println("=== After the function call:");
Serial.print("The lvalue for lowTemp is: ");
Serial.print((long) &lowTemp, DEC);
Serial.print(" and the rvalue is ");
Serial.println((long) lowTemp, DEC);
Serial.print("The lvalue for hiTemp is: ");
Serial.print((long) &hiTemp, DEC);
Serial.print(" and the rvalue is ");
Serial.println((long) hiTemp, DEC);
Serial.println("\n");
}
void loop() {}

