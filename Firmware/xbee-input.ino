#include "XBee.h"

XBee xbee = XBee();
ZBRxIoSampleResponse io = ZBRxIoSampleResponse();
char szXBeeAddress[18];
bool isClosed = false;

void setup() {
    Serial1.begin(9600);
    Serial.begin(9600);
    
    xbee.begin(Serial1);
}

void loop() {
    xbee.readPacket();
    
     if (xbee.getResponse().isAvailable()) {
        if (xbee.getResponse().getApiId() == ZB_IO_SAMPLE_RESPONSE) {
            xbee.getResponse().getZBRxIoSampleResponse(io);
            
            sprintf(szXBeeAddress, "%08X-%08X", 
                io.getRemoteAddress64().getMsb(), 
                io.getRemoteAddress64().getLsb());

            Serial.print(szXBeeAddress);
            Serial.print(" ");
            
            bool isOn = (io.isDigitalOn(4) == 1);
            
            if(isOn && !isClosed){
                Spark.publish("doorstate", "1");
            }
            else if(isClosed && !isOn){
                Spark.publish("doorstate", "0");
            }

            if(isOn){
                isClosed = true;
            }
            else{
                isClosed = false;
            }
            
            Serial.println((isClosed ? "Closed" : "Open"));
        }
     }
}