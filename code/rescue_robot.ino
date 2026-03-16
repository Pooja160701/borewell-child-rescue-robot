#define BLYNK_PRINT Serial    
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_TEMPLATE_ID "TMPLK5Ywdiko"
#define BLYNK_DEVICE_NAME "RESCUE ROBOT"
#define BLYNK_AUTH_TOKEN "MaDtOkzpHiprmopjX3pYVLiunkOp_iGn"
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "IOT1";
char pass[] = "123456789";
char auth[] = BLYNK_AUTH_TOKEN;
#define relay1 D1
#define relay2 D2
WidgetTerminal terminal(V6);
unsigned int m=0,act=0,val,val1,val2,val3,val4,val5,val6;

String inputString = ""; 
unsigned char a[200];

void setup()
{
  Serial.begin(9600);
  pinMode(relay1,OUTPUT);
   pinMode(relay2,OUTPUT);
  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,HIGH);
   Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);  
}
BLYNK_WRITE(V0)
{
  int button = param.asInt(); // read button
  if (button == 1) 
  { 
    Serial.print('*');
    Serial.print("001");
   
  } 
  else{
     Serial.print('*');
    Serial.print("005");
  }
}
  BLYNK_WRITE(V1)
{
  int button = param.asInt(); // read button
  if (button == 1) 
  { 
    Serial.print('*');
    Serial.print("002");
   
  } 
  else
  {
     Serial.print('*');
    Serial.print("006");
  }
}
BLYNK_WRITE(V2)
{
  int button = param.asInt(); // read button
  if (button == 1) 
  { 
    Serial.print('*');
    Serial.print("003");
   
  } 
  else
  {
    Serial.print('*');
    Serial.print("004");
  }
}
BLYNK_WRITE(V7)
{
  int button = param.asInt(); // read button
  if (button == 1) 
  { 
  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,LOW);
  } 
}
BLYNK_WRITE(V8)
{
  int button = param.asInt(); // read button
  if (button == 1) 
  { 
  digitalWrite(relay2,HIGH);
  digitalWrite(relay1,LOW);
  } 
}
BLYNK_WRITE(V9)
{
  int button = param.asInt(); // read button
  if (button == 1) 
  { 
   digitalWrite(relay1,HIGH);
  digitalWrite(relay2,HIGH);
  } 
}
void loop()
{
  Serial.print("loop");
   while(Serial.available())
    {
        char data;
        data=Serial.read();
  
        a[m]=data;
          if(a[0] == '*')
          {
            if(m<=12)
            {m++;}
          }
      }
      if(m > 1)
      {
        val1 = (a[1]-0x30)*100 + (a[2]-0x30)*10  + (a[3] - 0x30);
        val2 = (a[4]-0x30)*100 + (a[5]-0x30)*10  + (a[6] - 0x30);
        val3 = (a[7]-0x30)*100 + (a[8]-0x30)*10  + (a[9] - 0x30);
        val4 = (a[10]-0x30)*100 + (a[11]-0x30)*10  + (a[12] - 0x30);
        
        m=0;
      }
   
     
     Blynk.virtualWrite(V3,val1);
     delay(100);
   
   Blynk.virtualWrite(V4,val2);
    delay(100);
   
   Blynk.virtualWrite(V5,val3);
    delay(100);
   if(val3<50){Blynk.virtualWrite(V6,"C02 LEVEL LOW");}
    
     delay(100);
  if(val4==1){Blynk.virtualWrite(V6,"HUMAN DETECTED");}
    
      Blynk.run();
      delay(100);
  }