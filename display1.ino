#include <SoftwareSerial.h>
#include <LedControl.h>
#define dataPin  12    
#define clockPin  11   
#define csPin  10    
#define numDevices 1
int TX =2;
int RX =3;
int pattern;
LedControl lc = LedControl(12,11,10,1);
SoftwareSerial BluetoothSerial(TX, RX);
void pattern1();
void pattern2();
void setup()
{
pinMode(2, INPUT_PULLUP); 
BluetoothSerial.begin(38400);
lc.shutdown(0,false);
lc.setIntensity(0,8);
}
void loop()
{
  pattern1();
  if (BluetoothSerial.available()>0){
    pattern = BluetoothSerial.read();
    }
  if (pattern == '1'){
    Serial.println("Pattern 1 selected");
    pattern = 1;
    pattern1();
    }
  else if( pattern == '2'){
    Serial.println("Pattern 2 selected");
    pattern =2;
    pattern2();
      }
  }
 
void pattern1(){
  int i;
 for(  i=0;i<8;i++){
  lc.setRow(0,i-1,0x00);
  lc.setColumn(0,i-1,0x00);
  lc.setRow(0,i,0xFF);
  lc.setColumn(0,i,0xFF);
  delay(500);
  lc.setRow(0,i,0x00);
  lc.setColumn(0,i,0x00);
  }
}

void pattern2(){
  int i;
 for(  i=0;i<8;i++){
  lc.setRow(0,7-i,0xFF);
  lc.setColumn(0,7-i,0xFF);
  delay(500);
  lc.setRow(0,7-i,0x00);
  lc.setColumn(0,7-i,0x00);
  }
  
}

