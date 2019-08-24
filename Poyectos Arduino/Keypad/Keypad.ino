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

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  tecla = teclado.getKey();
  if(tecla!=NO_KEY)
  {
    clave[i]=tecla;
    i++;
    Serial.println(tecla);
    if(i==4)
    {
      if(clave[0]==pasword[0]&&clave[1]==pasword[1]&&clave[2]==pasword[2]&&clave[3]==pasword[3])
      //if(strcmp(clave,pasword)==0)
      {
        Serial.println("PASWORD CORRECTA");
        delay(2000);
        i=0;
      }
      else
      {
        i=0;
        Serial.println("PASWORD INCORRECTA");
      }
    }
  }
}
