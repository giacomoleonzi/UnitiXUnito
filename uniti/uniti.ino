/****************************************************************************
  UNITI X UNITO

  giacomoleonzi@gmail.com

******************************************************************************/

#include "wifi.h"
#include <WiFiUdp.h>
#include <RTCZero.h>
#include "time.h"


WiFiClient client;


void setup()
{
  Serial.begin(9600);

  //**********************************************************
  //************STARTING CONNECTION***************************
  //**********************************************************
  startConnection();
  //**********************************************************
  //************STARTING RTC**********************************
  //**********************************************************
  startRTC();

}

int i = 0;
void loop()
{
  Serial.println("sending .."+ String(i%8));
  const char* key = "val1";
  send_event(key, String(i%8), getDateTime());
  Serial.print(getDateTime());
  Serial.println();
  delay(30*1000);
  i++;
}
