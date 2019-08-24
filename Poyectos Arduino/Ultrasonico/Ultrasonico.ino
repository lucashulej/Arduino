#define LED1 8
#define LED2 10
#define LED3 12
int trig = 3;
int eco = 2;
int duracion;
int distancia;
void setup()
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(eco,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
}

void loop()
{
  digitalWrite(trig,HIGH);
  delay(1);
  digitalWrite(trig,LOW);
  duracion = pulseIn(eco,HIGH);
  distancia=duracion/58.2;
  Serial.print(distancia);
  Serial.println(" CM");
  if(distancia<=15)
  {
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
  }
  if(distancia>15&&distancia<25)
  {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,LOW);
  }
  if(distancia>25)
  {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,HIGH);
  }


}
