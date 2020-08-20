//Open Source
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE); //ENDEREÇO DO I2C E DEMAIS INFORMAÇÕES

int Led = 8;
int shock = 2;
int buzzer = 3;
int val;

void setup () {
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
  pinMode (Led, OUTPUT);
  pinMode (shock, INPUT); 
  pinMode (buzzer, OUTPUT);
}

void loop () {
  Serial.println("OBJETO: ");
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("OBJETO: "); //IMPRIME O TEXTO NO DISPLAY LCD
  
  val = digitalRead (shock);
  if (val == HIGH ) {
    digitalWrite(Led, HIGH);
    tone(buzzer, 1000, 1000);
    Serial.println("FORA DA POSICAO");
    lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
    lcd.print("FORA DA POSICAO     "); //IMPRIME O TEXTO NO DISPLAY LCD
  } else { 
    digitalWrite (Led, LOW);
    noTone(buzzer);
    Serial.println("NA POSICAO CORRETA");
    lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
    lcd.print("NA POSICAO CORRETA"); //IMPRIME O TEXTO NO DISPLAY LCD
    delay (500);
  }
}
