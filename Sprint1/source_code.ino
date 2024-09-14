#include "LiquidCrystal.h"
LiquidCrystal lcd(8,7,6,5,4,3);

int driverPin1 = 13; //input motor
int driverPin2 = 12; //input motor
int driverEnable = 11; // input PWM for driving motor

int temperatureSensor = 1;
int luminositySensor = 2;
int humiditySensor = 11;

int outVal = 0;// output value for PWM

bool temperaturesFavorable = false;


void setup() {
  pinMode(driverPin1, OUTPUT);
  pinMode(driverPin2, OUTPUT);
  pinMode(driverEnable, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  int tmpSensorValue = analogRead(temperatureSensor);
  float voltagem = tmpSensorValue * 4.68;
  voltagem /= 1024.0;
  float temperatura = (voltagem - 0.5) * 100;
  
  int umidade = analogRead(humiditySensor);
  
  int LDR = analogRead(luminositySensor);
  
  if(temperatura >= 20 && temperatura <= 30 && LDR <= 500 && LDR >= 100 && umidade >= 400 && umidade <= 700){
    outVal = 255;
    temperaturesFavorable = true;
    lcd.setCursor(0,0);
    lcd.print("Condicoes");
    lcd.setCursor(0,1);
    lcd.print("Favoraveis");      
  } else {
    lcd.clear();
    outVal = 100;
    temperaturesFavorable = false;
    lcd.setCursor(0,0);
    lcd.print("Condicoes");
    lcd.setCursor(0,1);
    lcd.print("Desfavoraveis");
  }
  
  delay(1000);
  lcd.clear();
  
  Serial.println("T" + (String)temperatura);
  Serial.println("L" + (String)LDR);
  Serial.println("U" + (String)umidade);
  
  if (temperaturesFavorable) {
    //acionar o motor
    driveMotor(outVal);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Acelerando");
    lcd.setCursor(0,1);
    lcd.print("O Motor");
  } else {
    driveMotor(outVal);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Velocidade");
    lcd.setCursor(0,1);
    lcd.print("Reduzida");
  }
  
  delay(1000);
  lcd.clear();
  
  //Showing temperature
  if(temperatura >= 20 && temperatura <= 30){
    lcd.setCursor(0,0);
    lcd.print("Temperatura OK");
    //temperaturesFavorable = true; // Temperaturas favoráveis
    delay(1000);
    lcd.clear();
  }
  else if (temperatura > 30){
    lcd.setCursor(0,0);
    lcd.print("ATENCAO:");
    lcd.setCursor(0,1);
    lcd.print("Temp. ALTA");
    delay(1000);
    lcd.clear();
  }
  else {
   lcd.setCursor(0,0);
    lcd.print("ATENCAO:");
    lcd.setCursor(0,1);
    lcd.print("Temp. BAIXA");
    delay(1000);
    lcd.clear();
  }
  
  lcd.setCursor(0,1);
  lcd.print("Temp. =");
  lcd.setCursor(9,1);
  lcd.print(temperatura);
  delay(1000);
  lcd.clear();
  
  //showing luminosity
  if(LDR >= 100 && LDR <= 500){
    lcd.setCursor(0,0);
    lcd.print("Visibilidade OK");
  } else{
    lcd.setCursor(0,0);
    lcd.print("ATENCAO: Baixa");
    lcd.setCursor(0,1);
    lcd.print("Visibilidade");
  }
  delay(1000);
  lcd.clear();
  
  //Showing Humidity
  if(umidade <= 500){
    lcd.setCursor(0,0);
    lcd.print("Umidade BAIXA");
    lcd.setCursor(0,1);
    lcd.print("Umidade = ");
    lcd.setCursor(11, 1);
    lcd.print(umidade/10);
    lcd.setCursor(12, 1);
    lcd.print("%");
  }else if (umidade > 500 && umidade <= 650){
    lcd.setCursor(0,0);
    lcd.print("Umidade OK");
    lcd.setCursor(0,1);
    lcd.print("Umidade = ");
    lcd.setCursor(11, 1);
    lcd.print(umidade/10);
    lcd.setCursor(13, 1);
    lcd.print("%");
  }
  else {
   lcd.setCursor(0,0);
   lcd.print("Umidade ALTA");
    lcd.setCursor(0,1);
    lcd.print("Umidade = ");
    lcd.setCursor(11, 1);
    lcd.print(umidade/10);
    lcd.setCursor(13, 1);
    lcd.print("%");
  }
  
  delay(1000);
  lcd.clear();
}

void driveMotor(int speed) {
  // Definir a direção do motor (opcional, dependendo da sua configuração)
  digitalWrite(driverPin1, LOW); // Pra trás
  digitalWrite(driverPin2, HIGH); // Pra frente
  
  // Controlar a velocidade do motor usando PWM
  analogWrite(driverEnable, speed);
}
