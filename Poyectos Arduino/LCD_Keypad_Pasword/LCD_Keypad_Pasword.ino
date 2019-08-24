#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C pantalla(0x3F,16,2);

#include <Wire.h>
#include <Keypad.h>
#define FILAS 4
#define COLUMNAS 4
char keys [4][4] = {'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};
byte pinesFilas[FILAS] = {9,8,7,6};
byte pinesColumnas[COLUMNAS] = {5,4,3,2};
Keypad teclado = Keypad(makeKeymap(keys), pinesColumnas,pinesFilas,  COLUMNAS,FILAS);
char tecla;
char pasword[] = {"4259"};
char clave[4];
int i=0;
int contador=0;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  pantalla.begin(16,2);
  pantalla.clear();
  pantalla.backlight();
}

void loop()
{
  tecla = teclado.getKey();
  if(contador==0)
  {
    pantalla.clear();
    pantalla.setCursor(0,0);
    pantalla.print("Ingrese Pasword");
    contador++;
  }
  if(tecla!=NO_KEY)
  {
    clave[i]=tecla;
    i++;
    Serial.println(tecla);
    if(i==4)
    {
      if(clave[0]==pasword[0]&&clave[1]==pasword[1]&&clave[2]==pasword[2]&&clave[3]==pasword[3])
      {
        pantalla.clear();
        pantalla.setCursor(0,0);
        pantalla.print("PASWORD CORRECTA");
        Serial.println("PASWORD CORRECTA");
        delay(4000);
        i=0;
        contador=0;
      }
      else
      {
        pantalla.clear();
        pantalla.setCursor(0,0);
        pantalla.print("PASWORD INCORRECTA");
        Serial.println("PASWORD INCORRECTA");
        delay(4000);
        i=0;
        contador=0;
      }
    }
  }
}
