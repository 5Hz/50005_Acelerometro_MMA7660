/******************************************************************
** Código creado en Electrónica 5Hz                              **
** www.5hz-electronica.com                                       **
** Por:                                                          **
** Basado en el código de: autorcillo original                   **
** Descripción del código:                                       **
**                                                               **
** Ejemplo para el acelerómetro MMA7660                          **
**                                                               **
*******************************************************************
Conexiones:
UNO   MMA7660

3.3V  VCC
GND   GND
*/


#include <Wire.h>
#include <MMA7660.h>

void setup()
{
  Serial.begin(9600);  //Configura la velocidad de transmision
  MMA7660.init();      //Llama la libreria del sensor
}

void loop()
{
  int x,y,z;                        // Se declaran las variables
  delay(100);                       // Retraso de 100 milisegundos
  MMA7660.getValues(&x,&y,&z);      // Funcion de la libreria que lee los valores de los ejes
  Serial.print("x: ");              
  Serial.print(x);                  // Imprime el valor del eje x
  Serial.print(" y: ");
  Serial.print(y);                  // Imprime el valor del eje y
  Serial.print(" z: ");
  Serial.println(z);                // Imprime el valor del eje z

}
