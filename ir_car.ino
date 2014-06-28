#include<IRremote.h>
#include<IRremoteInt.h>


int RECV_PIN = 12;
int dir1 = 2;
int dir2 = 3;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);	
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
  if (irrecv.decode(&results)) 
  {
  	
    Serial.println(results.value,DEC);
    if(results.value == 3041526525)
    {
     digitalWrite(dir1,HIGH);
     digitalWrite(dir2,LOW);
     delay(50);
     resetp();   
    }
    else if(results.value == 3041559165)
    {
    	digitalWrite(dir1,LOW);
    	digitalWrite(dir2,HIGH);
    	delay(1000);
    	resetp();
    }
    irrecv.resume(); // Receive the next value
  }
  
}

void resetp()
  {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
  }
