#define arrayLength 5
int photoReadPin  = 0, photoPowerPin  = 5, startTime = 0;
float ave;
int readings[arrayLength]; 


void setup() 
{
  Serial.begin(9600);
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
Purpose: Print readable array of values and the average
Parameter List:
int *readings pointer to the array holding readings
float ave the average of all the values in the readings array
Return value:
n/a
*****/
void printValues(int *value, float ave)
{
  Serial.print("[");
    for(int i = 0; i < arrayLength ; i++)
    {
      Serial.print(*(value+i));
      if(i < arrayLength-1)
      {
      Serial.print(", ");
      }
    }
  Serial.print("] ave=");
  Serial.println(ave);  
}


 

