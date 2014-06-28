#include <IRremote.h>
#include <IRremoteInt.h>


int RECV_PIN = 8;
int dir1 = 10;
int dir2 = 12;
int mo1 = 5;
int mo2 = 2;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(mo1,OUTPUT);
  pinMode(mo2,OUTPUT);	
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
  if (irrecv.decode(&results)) 
  {
  	
    Serial.println(results.value,DEC);
    if(results.value == 3041575485)
    {
     digitalWrite(dir1,HIGH);
     digitalWrite(dir2,LOW);
        
    }
    if (results.value == 3041526525)
    {
      digitalWrite(mo1,HIGH);
      digitalWrite(mo2,LOW);
    }
     if (results.value == 3041542845)
    {
    	digitalWrite(dir1,LOW);
    	digitalWrite(dir2,HIGH);
    }
     
     if(results.value == 3041559165)
    {
      digitalWrite(mo1,LOW);
      digitalWrite(mo2,HIGH); 
    } 
   if(results.value ==  3041532645)
   {
     resetp();
   }
      irrecv.resume(); // Receive the next value
  }
  
}

void resetp()
  {
  	digitalWrite(dir1,LOW);
        digitalWrite(dir2,LOW);
        digitalWrite(mo1,LOW);
        digitalWrite(mo2,LOW);
  }
