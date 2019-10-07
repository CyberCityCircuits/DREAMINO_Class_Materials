//Assign Pins for DREAMINO 5110 Gamer
int SW_01      =  7;
int SW_02      =  6;
int SW_03      =  9;
int SW_04      =  5;
int SW_05      =  8;
int SW_06      =  2;
int SW_07      =  0;
int SW_08      =  3;
int SW_09      =  4;
int SW_10      =  1;
int light_1    = 12;
int light_2    = 11;
int light_3    = 10;
//int speakerPin = 13;
int BL         = 14;
int CLK        = 15;
int DIN        = 16;
int DC         = 17;
int CS         = 18;
int RST        = 19;

int wait = 250;


void Setup(){
  Serial.begin(9600);
  
  pinMode(SW_01, INPUT);
  pinMode(SW_02, INPUT);
  pinMode(SW_03, INPUT);
  pinMode(SW_04, INPUT);
  pinMode(SW_05, INPUT);
  pinMode(SW_06, INPUT);
  pinMode(SW_07, INPUT);
  pinMode(SW_08, INPUT);
  pinMode(SW_09, INPUT);
  pinMode(SW_10, INPUT);
  pinMode(light_1, OUTPUT);
  pinMode(light_2, OUTPUT);
  pinMode(light_3, OUTPUT);
  //pinMode(speakerPin, OUTPUT);

  digitalWrite(light_1, HIGH);  delay(wait);
  digitalWrite(light_2, HIGH);  delay(wait);
  digitalWrite(light_3, HIGH);  delay(wait);
  digitalWrite(light_1, LOW);  delay(wait);
  digitalWrite(light_2, LOW);  delay(wait);
  digitalWrite(light_3, LOW);  delay(wait);
  
  
  
}


void lopp(){
  if (digitalRead(SW_01 == HIGH)){Serial.println("Button 01");}

}
