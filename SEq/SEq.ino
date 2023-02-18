int pot0=0;
int pot1=1;
int val0,val1;
int i,n;
int leds[] = {9, 8, 7, 6, 5, 4, 3, 2};//pin on which leds are connected
void setup()
{
  Serial.begin(9600);
  for (i=0;i<=7;i++)
    {
     pinMode(leds[i],OUTPUT);
    }
}
void loop()
{
  val0= analogRead(pot0);
  val1= analogRead(pot1);
  Serial.println(val0);
  Serial.println(val1);
  delay(1);
  for(n=0; n<sizeof(leds);n++)
  {
     digitalWrite(leds[i],HIGH);
     delay(100);
   }
  
}
