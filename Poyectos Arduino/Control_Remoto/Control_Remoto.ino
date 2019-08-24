#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>


int ledR = 12;
int ledG = 13;

int irPin = 6;

IRrecv receptor(irPin);

decode_results codigo;


void setup()
{
  Serial.begin(9600);
  
  receptor.enableIRIn();
  
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
}



void loop()
{
  if(receptor.decode(&codigo))
  {
    Serial.println(codigo.value, HEX);
    receptor.resume();  
  }
  
  switch(codigo.value)
  {
    case 0xFF30CF://1
    
      digitalWrite(ledR, HIGH);
      digitalWrite(ledG, LOW);
      break;
        
    case 0xFF18E7://2
    
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, HIGH);
      break;
      
    case 0xFF7A85://3
    
      digitalWrite(ledR, HIGH);
      digitalWrite(ledG, HIGH);
      break;
      
    case 0xFF10EF://4
    
      digitalWrite(ledR, HIGH);
      digitalWrite(ledG, HIGH);
      delay(1000);
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, LOW);
      delay(1000);
      break;
      
    case 0xFF4AB5://8
    
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, LOW);
        break;
  }
  delay(100); 
}
