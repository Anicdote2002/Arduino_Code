int pot0=0;
int pot1=1;
int val0,val1;
void setup() {
  
  Serial.begin(9600);

}

void loop() {

  val0= analogRead(pot0);
  val1= analogRead(pot1);
  Serial.println(val0);
  Serial.println(val1);
  delay(1);
  
 
}
