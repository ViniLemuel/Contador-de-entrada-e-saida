#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2);

const int sensorentrada = 2;
const int sensorsaida = 3;
int contador = 0;
int buttonState1 = 0;
int buttonState2 = 0;

void setup() {
  lcd.init(); 
  pinMode (sensorentrada,INPUT_PULLUP);
  pinMode (sensorsaida,INPUT_PULLUP);  
  Serial.begin(9600);  
}
void loop() {
  buttonState1 = digitalRead(sensorentrada);
  buttonState2 = digitalRead(sensorsaida);
  lcd.setCursor(0, 0);
  lcd.print("Quantidade de");
  lcd.setCursor(0, 1);
  lcd.print("pessoas");

  if (buttonState1 == HIGH){     
    contador++;
    delay(250);
  
    Serial.println(contador);
    delay(500);
  
    lcd.setCursor(8, 1);
    lcd.print(contador);
    lcd.setCursor(0, 0);
    lcd.setCursor(8, 1);
} if (buttonState2 == LOW){     
    contador--;
    delay(250);
  
    Serial.println(contador);
    delay(500);
    
    lcd.setCursor(8, 1);
    lcd.print(contador);
    lcd.setCursor(0, 0);
    lcd.setCursor(8, 1);     
 }
}
