
class RELOJ
{
  public :
      void IniciarCronometro()
      {
          INICIO=millis();
      }
      void IniciarTemporizador()
      {
          INICIO=millis();
      }
      void Setter_Temporiador(unsigned long Largo)
      {
          Duracion=Largo;
      }
      unsigned long StopTemporizador()
      {
        unsigned long TiempoActual=millis();
        int Estado;
        if((TiempoActual-INICIO)>=Duracion)
        {
          Estado=0;
        }
        else 
        {
          Estado=1;
        }
        return(Estado);
      }
      void PararCronometro()
      {
        FIN=millis();
      }
      void ReiniciarCronometro()
      {
        Duracion=millis();
      }
      unsigned long TiempoDeDuracion()
      {
        Duracion=FIN-INICIO;
        return(Duracion);
      }
    
  private :
      unsigned long INICIO;
      unsigned long FIN;
      unsigned long Duracion;

};
  int LedInicio=12;
  int LedReinicio=13;
  char ReciboChar;
  RELOJ MyTiempo;
void setup() {
  // put your setup code here, to run once:
  pinMode(LedInicio, OUTPUT);
  pinMode(LedReinicio, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hola controlo el tiempo");
}
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) 
  {
    ReciboChar= Serial.read();
    switch (ReciboChar) {
      case 'A':
        MyTiempo.IniciarTemporizador();
        digitalWrite(LedInicio, HIGH);
        Serial.println("Se inicio el tiempo");
        break;
      case 'D':
        MyTiempo.PararCronometro();
        digitalWrite(LedInicio, LOW);
         Serial.println("Se paro el tiempo");
        break;
      case 'R':
        MyTiempo.IniciarTemporizador();
        Serial.println("Se reinicio el tiempo");
        digitalWrite(LedReinicio, HIGH);
        delay(50);
        digitalWrite(LedReinicio, LOW);
         digitalWrite(LedInicio, HIGH);
        break;
    }
  }
}
