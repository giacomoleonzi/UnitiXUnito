#include <SPI.h>    //wifi
#include <WiFi101.h>



char ssid[] = "UnitixUnito";     //  your network SSID (name)
char pass[] = "unitixunito";      // your network password
int status = WL_IDLE_STATUS;          // the Wifi radio's status

//network setup
//185.114.108.111:80
//const char *host = "www.greento.it/workshop-IOT/live-server-data-receive.php";
const char *host = "api.thingtia.cloud";

  //**********************************************************
  //************Send Event************************************
  //**********************************************************
void send_event(String value, String id_key) {
  Serial.print("Connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  
  if (!client.connect(host, httpPort)) {
    Serial.println("Connection failed");
    return;
  }
  // We now create a URI for the request

  String url = "/data/karel/gionzi/";
  url += value;
  url += " HTTP/1.1 \r\nIDENTITY_KEY: ";
  url += id_key;
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  // This will send the request to the server
  client.print(String("PUT ") + url +
               "\r\nHost: " + host + "\r\n" +
               "Connection: close\r\n Content-Length: 0)\r\n\r\n");
  // Read all the lines of the reply from server and print them to Serial,
  // the connection will close when the server has sent all the data.
  while (client.connected())
  {
    if (client.available())
    {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    } else {
      // No data yet, wait a bit
      delay(50);
    };
  }
  // All done
  Serial.println();
  Serial.println("closing connection");
  client.stop();
}


  //**********************************************************
  //************printWifiData*********************************
  //**********************************************************
void printWifiData() {
  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  Serial.println(ip);
  // print your MAC address:
  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC address: ");
  Serial.print(mac[5], HEX);
  Serial.print(":");
  Serial.print(mac[4], HEX);
  Serial.print(":");
  Serial.print(mac[3], HEX);
  Serial.print(":");
  Serial.print(mac[2], HEX);
  Serial.print(":");
  Serial.print(mac[1], HEX);
  Serial.print(":");
  Serial.println(mac[0], HEX);
}


  //**********************************************************
  //************printCurrentNet*******************************
  //**********************************************************
void printCurrentNet() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the MAC address of the router you're attached to:
  byte bssid[6];
  WiFi.BSSID(bssid);
  Serial.print("BSSID: ");
  Serial.print(bssid[5], HEX);
  Serial.print(":");
  Serial.print(bssid[4], HEX);
  Serial.print(":");
  Serial.print(bssid[3], HEX);
  Serial.print(":");
  Serial.print(bssid[2], HEX);
  Serial.print(":");
  Serial.print(bssid[1], HEX);
  Serial.print(":");
  Serial.println(bssid[0], HEX);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.println(rssi);

  // print the encryption type:
  byte encryption = WiFi.encryptionType();
  Serial.print("Encryption Type:");
  Serial.println(encryption, HEX);
  Serial.println();
}


  //**********************************************************
  //************startConnection************************************
  //**********************************************************
void startConnection(){
// check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
    }
    // attempt to connect to Wifi network:
    while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(10000);
    }
    //CHECK CONNECTION
    // you're connected now, so print out the data:
    Serial.print("You're connected to the network");
    printCurrentNet();
    printWifiData();
}
