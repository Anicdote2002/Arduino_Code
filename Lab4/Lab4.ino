int pot0 = 0;
int pot1 = 1;
int i;
int leds[] = {9, 8, 7, 6, 5, 4, 3, 2};//pin on which led is connected



void setup() {
  
 
  for (i=0;i<=7;i++)
  {
    pinMode(leds[i],OUTPUT);
  }

}

//int myfunction() {
    // do something
    //return 0;
//}
//for (int i = 0; i < sizeOf(leds); i++) {
    //digitalWrite(leds[i], HIGH);
//}
//for (int i = sizeOf(leds); i > 3; i--) {
    //digitalWrite(leds[i], LOW);
//}


void loop() {
  // put your main code here, to run repeatedly:
  for (i=0;i<=7;i++)
  { 
    //pinMode(leds[i],OUTPUT);
    digitalWrite(leds[i], HIGH);
    delay (20);
    digitalWrite(leds[i],LOW);
    delay(20);
  }
  //digitalWrite(leds[0],HIGH);
  //delay(1000);
  //digitalWrite(leds[7],LOW);
  //delay(1000);

}
//ledfunction(0);
    //for (int i = 0; i < sizeof(leds); i++) {
    //digitalWrite(leds[i], HIGH);
    //delay(40);

    //ledfunction(2);
    //for (int i =7; i >=0 ; i--) 
   // {
    //digitalWrite(leds[i], LOW);
    //delay(40);
   // }













void first3rd()
{
  for(i=0;i<sizeof(leds);i++)
   {
      if((val1 >=128*i) && (val1 <=128*i+128))
      {
       ledfunction1(i);
      }
   }
}
void ledfunction1(int n)//for sequence 1
{
    digitalWrite(leds[n],HIGH);
    delay(40);
    digitalWrite(leds[n],LOW);
    delay(40);
}
void second3rd()
{
  for(i=0;i<sizeof(leds);i++)
   {
      if((val1 >=128*i) && (val1 <=128*i+128))
      {
        for(i=0; i<=n;i++)
         {
          digitalWrite(leds[i],HIGH);
          delay(40);
         }
        for(i=n; i>=0;i--)
         {
          digitalWrite(leds[i],LOW);
          delay(40);
         }
      }
   }
}
void ledfunction2(int n)//for sequence 2
{
  
 
}
void third3rd()
{
 for(i=0;i< sizeof(leds);i++)
   {
      if((val1 >=128*i) && (val1 <=128*i+128))
      {
       ledfunction3(i);
      }
   } 
}
void ledfunction3(int n)//sequence 3
{
  for(i=2;i<n+2;i++)
  {
    digitalWrite(leds[i-2],HIGH);
    digitalWrite(leds[i-1],HIGH);
    digitalWrite(leds[i],HIGH);
  }
  //for(i=n+2;i>2;i++)
  //{
    //digitalWrite(leds[i-2],LOW);
    //digitalWrite(leds[i-1],LOW);
    //digitalWrite(leds[i],LOW);
  //}
}  











for(i=0;i<=n;i++)
{
  digitialWrite(leds[i],HIGH);
}














    
