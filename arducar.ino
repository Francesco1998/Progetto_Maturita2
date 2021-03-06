#include <Servo.h>
#include <MeetAndroid.h>
#include <SoftwareSerial.h>

/*define logic control output pin*/
int in1=9;
int in2=8;
int in3=7;
int in4=6;
/*define channel enable output pins*/
int ENA=10;
int ENB=5;
int ABS=135;
/*define forward function*/

int rxPin=2;
int txPin=3;

MeetAndroid meetAndroid(rxPin,txPin,9600);

void setup() {
  Serial.begin(9600); // open serial port to receive data
  /*pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);*/
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  
  // steering in central position
  delay(100);

  // create array loop to iterate over every item in the array
  /*for (int thisReading = 0; thisReading < numOfReadings; thisReading++) {
    readings[thisReading] = 0;
  }*/

  // register callback function
  meetAndroid.registerFunction(moveCar, 'a');
}

void moveCar(byte flag, byte numOfValues)
{
  int length = meetAndroid.stringLength();
  char inputString[length];
 
  meetAndroid.getString(inputString);
  Parsing(inputString);

}
void Parsing(String stringa){
   String motore;
   String direzione;

   int commaIndex = stringa.indexOf(',');
   motore = stringa.substring(0, commaIndex);
  direzione = stringa.substring(commaIndex + 1);

  if(motore=="1" && direzione=="0")
    avanti();
  
  if(motore=="0")
    fermo();

  if(motore=="2" && direzione=="0")
    indietro();

  if(motore=="1" && direzione=="1")
    avanti_destra();
      
  if(motore=="1" && direzione=="2")
    avanti_sinistra();
  
  if(motore=="2" && direzione=="1")
    indietro_destra();

  if(motore=="2" && direzione=="2")
    indietro_sinistra();
}

 void avanti(){
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
 }

 void fermo(){
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
 }

 void indietro(){
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
 }

 void avanti_destra(){
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
 }

 void avanti_sinistra(){
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
 }

 void indietro_destra(){
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
 }

 void indietro_sinistra(){
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
 }
 
void loop() {
 meetAndroid.receive();

 /* for(int i=1; i<1000; i++)
    Parsing("1,0");
  for(int i=1; i<2000; i++)
    Parsing("2,0");
  for(int i=1; i<500; i++)
    Parsing("0,0");
  for(int i=1; i<1000; i++)
    Parsing("1,1");
  for(int i=1; i<3000; i++)
    Parsing("2,2");*/
  
}
