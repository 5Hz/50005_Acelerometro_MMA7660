#include <Wire.h>
#include <MMA7660.h> //incluir libreria en carpeta libraries de arduino

int x,y,z; //variables para los valores de cada eje
int barx, bary, barz;

void setup()
{
  Serial.begin(9600);
  MMA7660.init();
  Serial.println("*****************************************************");
  Serial.println("***********  Electronica 5Hz presenta:  *************");
  Serial.println("*** programa de prueba del acelerometro MMA7660  ****");
  Serial.println("*****************************************************");
}

void loop()
{
  menu();
  while(Serial.available() == 0){}
  switch (Serial.read())
  {
    case '1':
      Serial.println("presiona * para salir");
      do
      {
        MMA7660.getValues(&x,&y,&z);
        printx(map(x, -90, 90, 0, 20));
        Serial.print("x: ");
        Serial.println(x);
        delay(100);
      }while(Serial.read() != '*');
    break;
    case '2':
      Serial.println("presiona * para salir");
      do
      {
        MMA7660.getValues(&x,&y,&z);
        printy(map(y, -90, 90, 0, 20));
        Serial.print("y: ");
        Serial.println(y);
        delay(100);
      }while(Serial.read() != '*');
    break;
    case '3':
      Serial.println("presiona * para salir");
      do
      {
        MMA7660.getValues(&x,&y,&z);
        printz(map(z, -90, 90, 0, 20));
        Serial.print("z: ");
        Serial.println(z);
        delay(100);
      }while(Serial.read() != '*');
    break;
    default:
      Serial.println("ese no es un eje D: elige otro");
    break;
  }
}

void printx(int barx)
{
  do
  {
    Serial.print("-");
    barx--;
  }while(barx>0);
}

void printy(int bary)
{
  do
  {
    Serial.print("-");
    bary--;
  }while(bary>0);
}

void printz(int barz)
{
  do
  {
    Serial.print("-");
    barz--;
  }while(barz>0);
}

void menu()
{
  Serial.println("que eje quieres medir?");
  Serial.println("1.- x");
  Serial.println("2.- y");
  Serial.println("3.- z");
}
