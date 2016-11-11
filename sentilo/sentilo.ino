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
  //startRTC();

}

int i = 0;
void loop()
{
  int ana = analogRead(A5);
  Serial.println("sending .."+ String(ana));
  const char* key = "val1";
  send_event(String(ana), "6773be308fff4ed524c5faeb28679d2cf3ff6cd36b89968976b0f0171f3d1213");
  delay(30*1000);
  i++;
}
