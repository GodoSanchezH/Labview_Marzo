#include <WiFi.h>

WiFiServer server(8000);//escuchara a los clientes en este puerto
 char rx;
void setup() {
  Serial.begin(115200);
  WiFi.begin("GODO-2.4G","luis1624");

  while(WiFi.status() != WL_CONNECTED){
    Serial.println(".");
    delay(500);
  }
  Serial.println("Wifi Conectado");
  Serial.println(WiFi.localIP());

  //INICIAMOS EL SERVER
  server.begin();
  pinMode(2,OUTPUT);

}

void loop() {
 
 WiFiClient Client = server.available();

 if (Client) {
  Serial.println("Cliente Conectado");
  for(;;){
      while(Client.available()){
         rx = Client.read();
        if(rx == 'a') 
        {
          digitalWrite(2,1);
          server.print("Led 1 Prendido");
          rx = 'c';
        }
        if(rx == 'b') {
          digitalWrite(2,0);
           server.print("Led 1 Apagado");
           rx = 'c';
          }
      }
  }
 }
}
