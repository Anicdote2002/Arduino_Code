int pin_number=13;
int delay_no=600;
int freq=725;// declaring the starting value of the frequency
int Pval;

void setup() {
  Serial.begin(9600);
}
void loop() 
{
  int Pval=analogRead(A0);// returns the value that the light sensor reads
  Serial.println(Pval);
  delay(10);
  while ( freq < 1600 )// freqency keeps incrementing as long as it is less then 1600
  {
   if (Pval < 30)// in my room conditions less than 30 means the light sensor is covered and then triggerred
   {
    tone(pin_number,freq);
    delay(delay_no);
    tone(pin_number,(freq-200));
    delay(delay_no);
   }
   else 
   {
     noTone(pin_number);
   }
   freq=freq+100;
  }
  noTone(pin_number);//when freqency more than 1600, the siren stops
  freq=725; // frequency returns to original value
}
