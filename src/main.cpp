#include <Arduino.h>
#include "SPI.h"
#include <Adafruit_Circuit_Playground.h>




#define READ_REG 0x80
#define INC_REG 0x40
#define AX_REG 0x28
#define STATUS_REG 0x27
#define CFG1_REG 0x20
#define WHO_AM_I 0x0F
#define CS D8
#define lock_pin PB7


volatile uint8_t g_passwordset = 0;
volatile unin16_t g_password = {};




void setup() {
  // initiating buttons on board
  DDRD &= ~(1<<PD4);
  DDRF &= ~(1<<PF6);
  PORTD &= ~(1<<PD4);
  PORTD &= ~(1<<PF6);


 
  DDRB |= (1<<PB4)|
  //CS pin for SPI enables
  (1<<lock_pin);
  //initiating output pin for lock control
  PORTB &= ~(1<<lock_pin);
  //initially unlock




  Serial.begin(9600);
  SPI.begin();


  PORTB |= (1<<PB4);
  SPI.transfer(CFG1_REG);
  SPI.transfer(0b00100111);
  //running in normal mode 10hz
  PORTB &= ~(1<<PB4);




  CircuitPlayground.setPixelColor(0, 255,   0,   0);
  CircuitPlayground.setPixelColor(1, 128, 128,   0);
  CircuitPlayground.setPixelColor(2,   0, 255,   0);
  CircuitPlayground.setPixelColor(3,   0, 128, 128);
  CircuitPlayground.setPixelColor(4,   0,   0, 255);
   
  CircuitPlayground.setPixelColor(5, 0xFF0000);
  CircuitPlayground.setPixelColor(6, 0x808000);
  CircuitPlayground.setPixelColor(7, 0x00FF00);
  CircuitPlayground.setPixelColor(8, 0x008080);
  CircuitPlayground.setPixelColor(9, 0x0000FF);


  delay(500)


  CircuitPlayground.clearPixels();
}


void loop() {
  // put your main code here, to run repeatedly:
  if
}


void RecordPassword(){
  passwordset = 0;
  while(~passwordset){
  delay(20);
  digitalWrite(8,LOW);
  SPI.transfer(AX_REG | READ_REG | INC_REG);
  int8_t res = SPI.transfer(0xFF);
  int8_t res2 = SPI.transfer(0xFF);
  int16_t result = (res2 <<8) | res;
   Serial.print(">X:");
  Serial.println(result);
 
  res = SPI.transfer(0xFF);
  res2 = SPI.transfer(0xFF);
  result = (res2 <<8) | res;
    Serial.print(">Y:");
  Serial.println(result);
  res = SPI.transfer(0xFF);
  res2 = SPI.transfer(0xFF);
  result = (res2 <<8) | res;
    Serial.print(">Z:");
  Serial.println(result);
  if PIN()
  }
}



