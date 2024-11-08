/*
201901723 최가은
2022.09.27.화
*/


void setup() {
  Serial.begin(9600);
  
  int x = 927;
  int y = 212;

  Serial.print(x);
  Serial.print("+");
  Serial.print(y);
  Serial.print("=");
  Serial.print(x+y, DEC);
  Serial.println();
  
  Serial.print(x);
  Serial.print("-");
  Serial.print(y);
  Serial.print("=");  
  Serial.print(x-y, OCT);
  Serial.println();

  Serial.print(x);
  Serial.print("*");
  Serial.print(y);
  Serial.print("=");
  Serial.print(x*y, BIN);
  Serial.println();

  Serial.print(x);
  Serial.print("/");
  Serial.print(y);
  Serial.print("=");
  Serial.print(x/y, HEX);
  Serial.println();
}

void loop() {
}
