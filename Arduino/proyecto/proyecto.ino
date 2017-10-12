#include <Adafruit_NeoPixel.h>

char sz[100]; //Cantidad de caracteres que entran para poder hacer split

//Defino los leds para funcionalidades de semaforo y oficial
int ledRojoI = 12;
int ledRojoD = 2;
int ledVerdeI = 3;
int ledVerdeD = 4;
int ledOficialI = 5;
int ledOficialD = 6;


//Colores para pintar en los leds
short red1   = 0;
short green1 = 0;
short blue  = 0;
short red2   = 0;
short green2 = 0;
short red3   = 0;
short green3 = 0;

//contadores si inician de izquierda 
int counterBridge11 = 9;
int counterBridge21 = 0;
int counterBridge31 = 0;

//contadores si inician en la derecha
int counterBridge12 = 0;
int counterBridge22 = 0;
int counterBridge32 = 0;

//variables que se definen para utilizar los pines para los leds
Adafruit_NeoPixel stripBridge1 = Adafruit_NeoPixel(10, 10, NEO_GRB + NEO_KHZ800); //Number of leds, Pin, constants of the library
Adafruit_NeoPixel stripBridge2 = Adafruit_NeoPixel(10, 9, NEO_GRB + NEO_KHZ800); //Number of leds, Pin, constants of the library
Adafruit_NeoPixel stripBridge3 = Adafruit_NeoPixel(10, 8, NEO_GRB + NEO_KHZ800); //Number of leds, Pin, constants of the library

//el string que recibe el dato
String recieve = "";

boolean flagIniciar = false;

//variable spara el puente uno
int type1 = 0;
int pos1 = 0;
int large1 = 0;
int direccion1 = 0;

//variable spara el puente dos
int type2 = 0;
int pos2 = 0;
int large2 = 0;
int direccion2 = 0;

//variable spara el puente tres
int type3 = 0;
int pos3 = 0;
int large3 = 0;
int direccion3 = 0;

int getColorRED(int tipo){
  int valor = 0;
  if (tipo == 0 || tipo == 1){
     valor = 255;
  }
  else{
     valor == 0;
  }
  return valor;
}

int getColorGREEN(int tipo){
  int valor = 0;
  if (tipo == 0 || tipo == 2){
     valor = 255;
  }
  else{
     valor == 0;
  }
  //Serial.println("validando verde");
  //Serial.println(valor);
  return valor;
}

void izquierda1(){
  digitalWrite(ledVerdeI, HIGH);
  digitalWrite(ledVerdeD, LOW);
  digitalWrite(ledRojoI, LOW);
  digitalWrite(ledRojoD, HIGH);
  
  stripBridge1.setPixelColor(pos1,red1,green1,blue); //Coloca los colores en en el led counterBridges; 
  stripBridge1.setPixelColor(pos1+1,0,0,0);
  stripBridge1.show();
  //delay(1000);
  
  if(pos1 == 0){
    pos1 = large1;
  }
}

void derecha1(){
  digitalWrite(ledVerdeI, LOW);
  digitalWrite(ledVerdeD, HIGH);
  digitalWrite(ledRojoD, LOW);
  digitalWrite(ledRojoI, HIGH);
  stripBridge1.setPixelColor(pos1,red1,green1,blue); //Coloca los colores en en el led counterBridges; 
  stripBridge1.setPixelColor(pos1-1,0,0,0);
  stripBridge1.show();
  
  if(pos1 == large1){
    pos1 = 0;
  }
}



void izquierda2(){
  digitalWrite(ledOficialD, LOW);
  digitalWrite(ledOficialI, HIGH);
  stripBridge2.setPixelColor(pos2,red2,green2,blue); //Coloca los colores en en el led counterBridges; 
  stripBridge2.setPixelColor(pos2+1,0,0,0);
  stripBridge2.show();
  //delay(1000);
  if(pos2 == 0){
    pos2 = large2;
  }
}

void derecha2(){
  digitalWrite(ledOficialI, LOW);
  digitalWrite(ledOficialD, HIGH);
  stripBridge2.setPixelColor(pos2,red2,green2,blue); //Coloca los colores en en el led counterBridges; 
  stripBridge2.setPixelColor(pos2-1,0,0,0);
  stripBridge2.show();
  
  if(pos2 == large2){
    pos2 = 0;
  }
}


void izquierda3(){
  stripBridge3.setPixelColor(pos3,red3,green3,blue); //Coloca los colores en en el led counterBridges; 
  stripBridge3.setPixelColor(pos3+1,0,0,0);
  stripBridge3.show();
  //delay(1000);
  if(pos3 == 0){
    pos3 = large3;
  }
}

void derecha3(){
  stripBridge3.setPixelColor(pos3,red3,green3,blue); //Coloca los colores en en el led counterBridges; 
  stripBridge3.setPixelColor(pos3-1,0,0,0);
  stripBridge3.show();
  
  if(pos3 == large3){
    pos3 = 0;
  }
}

//Agrega a una lista las variables que entran y luego se le son asignadas
void obtener(String str){
  int indexAnt = 0;
  int contador = 0;
  String token[12];
  for (int i = 0; i < str.length(); i++) {
    if (recieve.substring(i, i+1) == ";") {
      token[contador] = str.substring(indexAnt, i);
      indexAnt = i+1;
      contador++;
    }
    if(i == str.length() -1){
      token[contador] = str.substring(indexAnt, i);
    }
  }
  contador = 0;
  indexAnt = 0;
  
  type1 = token[0].toInt();
  pos1 = token[1].toInt();
  large1 = token[2].toInt();
  direccion1 = token[3].toInt();

  type2 = token[4].toInt();
  pos2 = token[5].toInt();
  large2 = token[6].toInt();
  direccion2 = token[7].toInt();

  type3 = token[8].toInt();
  pos3 = token[9].toInt();
  large3 = token[10].toInt();
  direccion3 = token[11].toInt();

}


void setup() {
  
  Serial.begin(9600);     // abre el puerto serial 9600 bps
  Serial.setTimeout(10);
        
  stripBridge1.begin(); //Inicializa los leds
  stripBridge2.begin();
  stripBridge3.begin();
        
  stripBridge1.setBrightness(3); //Para no encandilarse
  stripBridge2.setBrightness(3); //Para no encandilarse
  stripBridge3.setBrightness(3); //Para no encandilarse 
      
  stripBridge1.show(); //Muestra los leds
  stripBridge2.show();
  stripBridge3.show();  
  
  pinMode(ledRojoI, OUTPUT);
  pinMode(ledRojoD, OUTPUT);
  pinMode(ledVerdeI, OUTPUT);
  pinMode(ledVerdeD, OUTPUT);
  pinMode(ledOficialI, OUTPUT);
  pinMode(ledOficialD, OUTPUT);
}

void loop() {
  stripBridge1.setPixelColor(pos1,0,0,0);
  stripBridge2.setPixelColor(pos2,0,0,0);
  stripBridge3.setPixelColor(pos3,0,0,0);
  if (Serial.available() > 0) {
    recieve = Serial.readString();
    obtener(recieve);
    flagIniciar = true;
    
    
    
    if(flagIniciar==true){
    green1 = getColorGREEN(type1);
    red1 = getColorRED(type1);
    green2 = getColorGREEN(type2);
    red2 = getColorRED(type2);
    green3 = getColorGREEN(type3);
    red3 = getColorRED(type3);
   }
   if(direccion1 == 11){
     izquierda1();
   }
   if(direccion1 == 12){
      derecha1();
   }
   if(direccion2 == 21){
     izquierda2();
   }
   if(direccion2 == 22){
      derecha2();
   }
   if(direccion3 == 31){
     izquierda3();
   }
   if(direccion3 == 32){
      derecha3();
   }
  }
  
  /*Serial.print("la variabel es: ");
  Serial.println(type1);
  Serial.print("la variabel es: ");
  Serial.println(pos1);
  Serial.print("la variabel es: ");
  Serial.println(large1);
  Serial.print("la variabel es: ");
  Serial.println(direccion1);
  Serial.println("********************");
  Serial.print("la variabel es: ");
  Serial.println(type2);
  Serial.print("la variabel es: ");
  Serial.println(pos2);
  Serial.print("la variabel es: ");
  Serial.println(large2);
  Serial.print("la variabel es: ");
  Serial.println(direccion2);
  Serial.println("********************");
  Serial.print("la variabel es: ");
  Serial.println(type3);
  Serial.print("la variabel es: ");
  Serial.println(pos3);
  Serial.print("la variabel es: ");
  Serial.println(large3);
  Serial.print("la variabel es: ");
  Serial.println(direccion3);
  Serial.println("********************");*/
  stripBridge1.setPixelColor(pos1,0,0,0);
  stripBridge2.setPixelColor(pos2,0,0,0);
  stripBridge3.setPixelColor(pos3,0,0,0);
  
  
   delay(1000);
}



