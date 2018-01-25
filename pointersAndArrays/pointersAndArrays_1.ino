//Adapted from http://www.cplusplus.com/doc/tutorial/pointers/
void setup() {
  Serial.begin(9600);
  int numbers[5];
  int * p;
  p = numbers;  *p = 10;
  p++;  *p = 20;
  p = &numbers[2];  *p = 30;
  p = numbers + 3;  *p = 40;
  p = numbers;  *(p+4) = 50;
  for (int n=0; n<5; n++){
  Serial.print(numbers[n]);Serial.print(", ");
  }
}

void loop() {
}
