//This is a port of the Snake game based one a tutorial
//found at https://steemit.com/cn/@pakganern/snake-game-on-arduino-using-nokia-5110-lcd-and-push-buttons
//This has been ported to the DREAMINO 5110 Gamer April 11th, 2019

#include <EEPROM.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

//Assign Pins for DREAMINO 5110 Gamer
#define SW_01       7
#define SW_02       6
#define SW_03       9
#define SW_04       5
#define SW_05       8
#define SW_06       2
#define SW_07       0
#define SW_08       3
#define SW_09       4
#define SW_10       1
#define light_1    12
#define light_2    11
#define light_3    10
#define speakerPin 13
#define BL         14
#define CLK        15
#define DIN        16
#define DC         17
#define CS         18
#define RST        19

Adafruit_PCD8544 display = Adafruit_PCD8544(CLK, DIN, DC, CS, RST); 

#define MAX_WIDTH  84
#define MAX_HEIGHT 48

#define LCD_CONTRAST 100

boolean dl=false,dr=false,du=false,dd=false;
int x[200],y[200],i,slength,tempx=10,tempy=10,xx,yy;
unsigned int high;
uint8_t bh,bl;
int xegg,yegg;
int freq,tb;
int l,r,u,d,p;
unsigned long time=280,beeptime=50;
int score=0,flag=0;


void setup() {
  Serial.begin(9600);      
  display.begin();
  display.clearDisplay();

  pinMode(light_1, OUTPUT);
  pinMode(light_2, OUTPUT);
  pinMode(light_3, OUTPUT);

  pinMode(BL, OUTPUT);

  digitalWrite(BL, LOW);
  
  pinMode(SW_01,INPUT);    
  pinMode(SW_02,INPUT);
  pinMode(SW_03,INPUT);
  pinMode(SW_04,INPUT);
  pinMode(SW_05,INPUT);  
  pinMode(speakerPin,OUTPUT);  
  digitalWrite(SW_01,HIGH);  
  digitalWrite(SW_02,HIGH);
  digitalWrite(SW_03,HIGH);
  digitalWrite(SW_04,HIGH);
  digitalWrite(SW_05,HIGH);
  display.setContrast(LCD_CONTRAST);
  slength=8;             
  xegg=(display.width())/2;  
  yegg=(display.height())/2;  
  display.setTextSize(2);      
  display.setTextColor(BLACK);
  display.setCursor(10,20);
  display.print("SNAKE");
  display.setCursor(10,50);
  display.print("utopian");
  display.display();
  delay(4000);
  display.clearDisplay();  
  for(i=0;i<=slength;i++)  
  {
    x[i]=25-3*i;
    y[i]=10;   
  }  
  for(i=0;i<slength;i++)   
     {
     display.drawCircle(x[i],y[i],1,BLACK);
     }
     display.display();
dr=true;
}
void loop()   
{        
   movesnake();      
} 
void movesnake()
{
  l=digitalRead(SW_02);   
  d=digitalRead(SW_04);
  r=digitalRead(SW_03);
  u=digitalRead(SW_01);
  p=digitalRead(SW_05);  
if(flag==0)
{
direct();            
}
  if(millis()%time==0)   
{             
     if(flag==0)                                
     {
       if(dr==true){tempx=x[0]+3;tempy=y[0];}   
       if(dl==true){tempx=x[0]-3;tempy=y[0];}    
       if(du==true){tempy=y[0]-3;tempx=x[0];}
       if(dd==true){tempy=y[0]+3;tempx=x[0];}
     }   
   flag=0;  
     checkgame();                       
      checkegg();   
 if(tempx<=0){tempx=84+tempx;}    
 if(tempx>=84){tempx=tempx-84;}
 if(tempy<=0){tempy=48+tempy;}
 if(tempy>=48){tempy=tempy-48;}
 for(i=0;i<=slength;i++)      
  {
   xx=x[i];
   yy=y[i]; 
   x[i]=tempx;
   y[i]=tempy;
   tempx=xx;
   tempy=yy;
  }  
drawsnake();        
}
}
void checkgame()      
{
  for(i=1;i<slength;i++)            
  {
    if(x[i]==x[0] && y[i]==y[0])
    {      
      bh=EEPROM.read(1);
      bl=EEPROM.read(0);
      high=(((0xff00+bh)<<8) + bl);      
      if(score>high)
      {
        high=score;
        bh=(high >> 8);
        bl=high & 0xff;       
        EEPROM.write(1,bh);
        EEPROM.write(0,bl);
      }
      display.clearDisplay();
      display.setTextColor(BLACK);       
      display.setTextSize(1);
      display.setCursor(20,12);
      display.print("Game Over");
      display.setCursor(15,30);
      display.print("Score: ");
      display.print(score);
      display.setCursor(15,40);
      display.print("High: ");
      display.print(high);     
      display.display();
      beep(20,5000);            
      display.clearDisplay();      
      slength=8;        
      score=0;
      time=280;      
      redraw();          
    }
  }
}
void checkegg()   
{
  if(x[0]==xegg or x[0]==(xegg+1) or x[0]==(xegg+2) or x[0]==(xegg-1))  
  {
    if(y[0]==yegg or y[0]==(yegg+1) or y[0]==(yegg+2) or y[0]==(yegg-1))
    {
      score+=1;                
      slength+=1;
      if(time>=90)
      {time-=20;}      
      display.fillRect(xegg,yegg,3,3,WHITE);          
      display.display();            
      beep(35,beeptime);          
      xegg=random(1,80);            
      yegg=random(1,40);
    }
  }
}        
void direct()             
{
  if(l==LOW and dr==false)      
  {
    dl=true;du=false;dd=false;
    tempx=x[0]-3;          
    tempy=y[0];
    flag=1;                    
  }  
  else if(r==LOW and dl==false)
  {
    dr=true;du=false;dd=false;
    tempx=x[0]+3;
    tempy=y[0];
    flag=1;
  }  
  else if(u==LOW and dd==false)
  {
    du=true;dl=false;dr=false;
    tempy=y[0]-3;
    tempx=x[0];
    flag=1;
  }  
  else if(d==LOW and du==false)
  {
    dd=true;dl=false;dr=false;
    tempy=y[0]+3;
    tempx=x[0];
    flag=1;
  } 
  else if(p==LOW)
  {
  display.clearDisplay();  
  display.setTextColor(BLACK);
  for(i=5;i>0;i--)
    {
     display.setCursor(25,10); 
     display.setTextSize(1);
     display.print("PAUSED");
     display.setCursor(40,30);
     display.print(i);
     display.display();
     delay(1000);
     display.clearDisplay();
    } 
    redraw();    
  } 
}
void drawsnake()  
{
  display.fillRect(xegg,yegg,3,3,BLACK);  
  display.drawCircle(x[0],y[0],1,BLACK);  
  display.drawCircle(x[slength],y[slength],1,WHITE);
  display.display(); 
}
void redraw()
{
  display.fillRect(xegg,yegg,3,3,BLACK);
  for(i=0;i<slength;i++)
     {
     display.drawCircle(x[i],y[i],1,BLACK);
     }
     display.display();
}               
void beep (int freq,long tb)  
{ 
    int x;   
    long delayAmount = (long)(500/freq);   
    long loopTime = (long)(tb/(delayAmount*2)); 
    for (x=0;x<loopTime;x++)     // One iteration produces sound for one cycle
    {    
        digitalWrite(speakerPin,HIGH);
        digitalWrite(light_1, HIGH);
        digitalWrite(light_2, HIGH);
        digitalWrite(light_3, HIGH);
       
        delay(delayAmount);
        digitalWrite(speakerPin,LOW); 
        digitalWrite(light_1, LOW);
        digitalWrite(light_2, LOW);
        digitalWrite(light_3, LOW);
        delay(delayAmount);
    }        
    delay(2);   
}
