
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  // put your setup code here, to run once:
    pinMode(33, OUTPUT);
    pinMode(15,INPUT);
    Serial.begin(9600);
    SerialBT.begin("ESP32 CAM"); //Bluetooth device


}

void loop() {
  /*code for testing the uploading of code*/
    digitalWrite(33,LOW); // Led on
    delay(500);            
    digitalWrite(33,HIGH);  //  Led off
    delay(500);

while(SerialBT.available()>0) {
  int x=analogRead(15);
    int y=map(x,0,4095,0,100);
    int val=SerialBT.parseInt();

    if(val>0){
          SerialBT.write(y);

    }
    else{

    }
    
    

    //Serial.println(y);
  }
    
 
      
    
    
}
