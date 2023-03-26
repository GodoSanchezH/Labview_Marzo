
char Dato_rx_labview;
uint16_t adc0,adc1,adc2,adc3;
uint8_t bt1,bt2;
void setup() {


/*Inicializamos la comunicacion Serial*/
Serial.begin(9600);

/*Salidas Digitales*/
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);

/*Entradas Digitales*/
pinMode(3,INPUT);
pinMode(2,INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

    if(Serial.available()>0){
      Dato_rx_labview = Serial.read();

      if(Dato_rx_labview == 'X'){
        adc0 = analogRead(0);
        adc1 = analogRead(1);
        adc2 = analogRead(2);
        adc3 = analogRead(3);

        bt1 = digitalRead(2);
        bt2 = digitalRead(3);

      /*eSCRIBIMOS LA INFORMACION*/
      Serial.print(adc0);
      Serial.print(";");
      Serial.print(adc1);
      Serial.print(";");
      Serial.print(adc2);
      Serial.print(";");
      Serial.print(adc3);
      Serial.print(";");
      Serial.print(bt1);
      Serial.print(";");
      Serial.print(bt2);
      Serial.print("\n\r");                        
      }
        /*Escribir Info*/
        if(Dato_rx_labview == 'a') digitalWrite(13,HIGH);
        if(Dato_rx_labview == 'b') digitalWrite(13,LOW);
        if(Dato_rx_labview == 'c') digitalWrite(12,HIGH);
        if(Dato_rx_labview == 'd') digitalWrite(12,LOW);
        if(Dato_rx_labview == 'e') digitalWrite(11,HIGH);
        if(Dato_rx_labview == 'f') digitalWrite(11,LOW);
        if(Dato_rx_labview == 'g') digitalWrite(10,HIGH);
        if(Dato_rx_labview == 'h') digitalWrite(10,LOW);


    }






}
