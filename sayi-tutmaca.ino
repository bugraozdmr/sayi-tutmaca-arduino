#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>


Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);   //pcd8544 uretici

void setup() {
  //Initialize Display
  pinMode(A0,INPUT);
  display.begin();
  display.clearDisplay();   //bu yapılmazsa basta cikan yildiz surekli cikar
  // you can change the contrast around to adapt the display for the best viewing!
  display.setContrast(100);
}
int randint=random(0,1023);
void loop() {
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.println("-analog deger-");
  display.println("--------------");    //14 karakter alabiliyor
  display.setTextSize(2);
  display.print("  ");
  display.println(analogRead(A0));
  display.setTextSize(1);

  if(analogRead(A0)<randint){
    display.println("");
    display.println("sayidan kucuk");
  }else if(analogRead(A0)>randint){
    display.println("");
    display.println("sayidan buyuk");
  }else{
    display.println("");
    display.println("sayiyi buldun");
  }
  display.display();
  delay(100);
  display.clearDisplay();

}
