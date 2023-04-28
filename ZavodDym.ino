#include <Wire.h>
#define SLAVE_ADDRESS 0x04

int d2 = 2;
int aPin=A0;
int avalueA=0;

int d3 = 3;
int bPin=A1;
int avalueB=0;

int d4 = 4;
int cPin=A2;
int avalueC=0;




void setup() 
{
    Serial.begin(9600);       
    pinMode(d2,OUTPUT);
    pinMode(d3,OUTPUT);
    pinMode(d4,OUTPUT);

    
    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(receiveData);
    Wire.onRequest(sendData);
   

    
}
int pin,st,val=0,flag=0,index=0;
char buf[8];
byte b[2];
void loop()
{
  avalueA=analogRead(aPin);
  
  if (avalueA < 500){
    digitalWrite(d2,LOW);
  } if (avalueA > 500){
     digitalWrite(d2,HIGH);
  }

  avalueB=analogRead(bPin);

  if (avalueB < 500){
    digitalWrite(d3,LOW);
  } if (avalueB > 500){
     digitalWrite(d3,HIGH);
  }


  avalueC=analogRead(cPin);

  if (avalueC < 500){
    digitalWrite(d4,LOW);
  } if (avalueC > 500){
     digitalWrite(d4,HIGH);
  }
  
  
  if(flag==1)
  {
    flag=0;
    val=analogRead(pin);
    b[0]=val/256;
    b[1]=val%256;
   } 

 
}

void receiveData(int byteCount)
{
    while(Wire.available()>0) 
    {     
      pin=Wire.read();
      flag=1;
      
    }
}

// callback for sending data
void sendData()
{
  Wire.write(b,2);
}
