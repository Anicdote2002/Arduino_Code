int pot0=0;
int pot1=1;//potentiometer pins
int val0,val1;//variables used for storing values from potentiometer
int i,n,b;//variables to be used as counters
int leds[] = {9, 8, 7, 6, 5, 4, 3, 2};//pin on which leds are connected
void setup()
{
  
  Serial.begin(9600);
   for (i=0;i<=7;i++)
    {
     pinMode(leds[i],OUTPUT);
     
    }
}
//setting up functions to be used in main code
void first3rd()//when POT 0 is in the 1st third of its input range
{
  for(i=0; i < sizeof(leds);i++)
   {
      if((val1 >=128*i) && (val1 <((128*i)+128)))//checks for input values from POT1 based on the eight input range from POT1
      {
       ledfunc1(i);
      }
   }
}
void second3rd()//when POT 0 is in the 2nd third of its input range
{
 for(i=0; i < sizeof(leds);i++)
   {
      if((val1 >=128*i) && (val1 <((128*i)+128)))
      {
       ledfunc2(i);
      }
   }
}
void third3rd()//when POT 0 is in the last third of its input range
{
for(i=0; i < sizeof(leds);i++)
   {
      if((val1 >=128*i) && (val1 < ((128*i)+128)))
      {
       ledfunc3(i);
      }
   } 
}
void ledfunc1(int n)//for sequence 1
{
    digitalWrite(leds[n],HIGH);
    delay(10);
    digitalWrite(leds[n],LOW);
    delay(10);
}
void ledfunc2(int n)//for sequence 2
{
  for(i=0; i <= n+1 ;i++)
  {
    digitalWrite(leds[i-1],HIGH);
    digitalWrite(leds[i+1],LOW);
  }
}   
void ledfunc3(int n)//for sequence 3
{
 while (i<=n)
 {
  for(b=i;b<=i;b++)
  {
    digitalWrite(leds[b-1],HIGH);
    digitalWrite(leds[b],HIGH);
    digitalWrite(leds[b+1],HIGH);
    delay(1000);
  }
  for(b=i;b<=i;b++)
  {
    delay(10);
    digitalWrite(leds[b-1],LOW);
    digitalWrite(leds[b],LOW);
    digitalWrite(leds[b+1],LOW);
  }
    i++;
 }
}  
void loop() 
{
  val0= analogRead(pot0);
  val1= analogRead(pot1);
  Serial.println(val0);
  Serial.println(val1);
  delay(1);
  if ( val0 < 341)//checks value from POT 0 to determine 
     {            //which third of the input range it is (VALUES FROM POT 0-1023; 
       first3rd();//I DIVIDED THEM INTO THIRDS FOR POT O AND EIGHTS FOR POT 1)
     }
 else if( val0 >= 341 && val0<628)
   {
    second3rd();
   }
  else if( val0 >= 628 && val0 < 1024)
   {
    third3rd();
   }
}
