#include <Wire.h>
String data;
int x, y, z, m, n, p;
void(* resetFunc) (void) = 0;




void setup() {
  Serial.begin(115200);
}



void loop() {
  while (!Serial.available());

  //This line converts the input string into char
  char data_as_char[50];
  data.toCharArray(data_as_char, 50);
  data = Serial.readString();

  
  if (data.equals("reset")){
    Serial.println("Resetting");
    resetFunc();
  }
  else{
  
    //This line converts char into a set of integers
    if (sscanf(data_as_char , "%d/%d/%d/%d/%d/%d", &x, &y, &z, &m, &n, &p) == 6) {
      Serial.println("Detected data: " + String(x) + ',' + String(y) + ',' + String(z) + ',' + String(m) + ',' + String(n) + ',' + String(p));
    }
  }

}
