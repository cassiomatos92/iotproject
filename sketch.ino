#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // Corrigido o nome da classe

#include "HX711.h"
HX711 scale;

float Valor;  // Tipo alterado para float, pois o retorno de get_units() é um float
int Peso;

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  scale.begin(13, 14);
  lcd.setCursor(0, 0);
  lcd.print("Inicializando..."); 
  delay(1000);
  Serial.println("Célula de carga");
}

void loop() {
  Valor = scale.get_units();  // Corrigido o erro de atribuição
  Peso = map((int)Valor, 0, 2100, 0, 5000); // Convertendo o valor para inteiro antes de mapear
  Serial.println(Peso);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Célula de carga");
  lcd.setCursor(0, 1);
  lcd.print(Peso);
  
  delay(1000); // Aguarda 1 segundo antes de repetir
}