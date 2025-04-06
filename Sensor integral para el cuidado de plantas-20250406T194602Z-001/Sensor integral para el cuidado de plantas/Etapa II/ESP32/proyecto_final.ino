#include <Arduino.h>
#include <U8x8lib.h>
#include<ESP8266WiFi.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
#include <DFRobot_SHT20.h>
#include <BH1750.h>
#define sensorPin A0
#define A D7
#define B D6
 int menu=1;
   void modo1();
   void modo2();
   void informacion();
   void ayuda();


U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE); //constructor oled
BH1750 GY302;
DFRobot_SHT20 sht20;
//LiquidCrystal_I2C lcd (0x27, 16, 2);

/* Degree symbol:
byte Degree[] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
*/
/*void pre(void)
{
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);    
  u8x8.clear();

  u8x8.inverse();
  u8x8.print(" Sensor Integral ");
  u8x8.setFont(u8x8_font_chroma48medium8_r);  
  u8x8.noInverse();
  u8x8.setCursor(0,1);
}
void draw_bar(uint8_t c, uint8_t is_inverse)
{  
  uint8_t r;
  u8x8.setInverseFont(is_inverse);
  for( r = 0; r < u8x8.getRows(); r++ )
  {
    u8x8.setCursor(c, r);
    u8x8.print(" ");
  }*/
//}
void setup() {
  int i;
  Serial.begin(9600);
  Wire.begin();
   u8x8.begin();
   pinMode(D7, INPUT);
   pinMode(D6, INPUT);

  
 // lcd.begin(16,2);                          // Init LCD 16x02
  // Create a custom character:
  /*lcd.createChar(0, Degree);*/
  u8x8.clear();
//  u8x8.backlight();
u8x8.setFont(u8x8_font_chroma48medium8_r); 
//u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);

 // if(digitalRead(D6)==HIGH){
  u8x8.setCursor(1,0);
  u8x8.print("                ");
   u8x8.setCursor(1,1);
  u8x8.print("                ");
     u8x8.setCursor(1,2);
  u8x8.print("                ");
   u8x8.setCursor(1,3);
  u8x8.print("    SENSOR      ");
   u8x8.setCursor(1,4);
  u8x8.print("   INTEGRAL     ");
  u8x8.setCursor(1,5);
  u8x8.print(" PARA PLANTAS   ");
   u8x8.setCursor(1,6);
  u8x8.print("                ");
  u8x8.setCursor(1,7);
  u8x8.print("                ");
   u8x8.setCursor(1,7);
  u8x8.print("                ");
 
  delay(3000);
 
  //delay(10000);
  u8x8.clear();

  sht20.initSHT20();                         // Init SHT20 Sensor
    delay(100);
    sht20.checkSHT20();  
    GY302.begin();                           // Init GY302 Sensor

}


void loop() {

 int select=digitalRead(B);
 if(digitalRead(A)==HIGH){
  if(menu>=4){
    menu=0;
    }
    menu++;
    delay(100);
    } 
 if(select==HIGH){
  //select=0;
  switch (menu){
  case 1:            
                      modo1();
                      menu=1;
                      u8x8.clear();
                      delay(500);
                      
  break;
  case 2:             menu=1;
                      modo2();
                      menu=2;
                      u8x8.clear();
                      delay(500);
                      
  break;
  case 3:             informacion();
                       menu=3;
                       u8x8.clear();
                       delay(500);
 break;
  //default;
 }
 
 }
 u8x8.setFont(u8x8_font_chroma48medium8_r);
 //u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
 switch (menu){
  case 1:      
                      u8x8.setCursor(0,1);
                      u8x8.inverse();
                      u8x8.print(" Modo global");
                      u8x8.setCursor(0,3);
                      u8x8.noInverse();
                      u8x8.print(" Modo individual");
                      u8x8.setCursor(0,5);
                      u8x8.noInverse();
                      u8x8.print(" Acerca de ");
  break;
  case 2:             u8x8.setCursor(0,1);
                      u8x8.noInverse();
                      u8x8.print(" Modo global");
                      u8x8.setCursor(0,3);
                      u8x8.inverse();
                      u8x8.print(" Modo individual");
                      u8x8.setCursor(0,5);
                      u8x8.noInverse();
                      u8x8.print(" Acerca de");
  break;
  case 3 :            u8x8.setCursor(0,1);
                      u8x8.noInverse();
                      u8x8.print(" Modo global");
                      u8x8.setCursor(0,3);
                      u8x8.noInverse();
                      u8x8.print(" Modo individual");
                      u8x8.setCursor(0,5);
                      u8x8.inverse();
                      u8x8.print(" Acerca de");
  break;
 // default;
}

}
void modo1(){
  u8x8.clear();
  u8x8.setCursor(1,0);
  u8x8.print("Hum ");
  //u8x8.print(humd);
  u8x8.setCursor(13,0);
  u8x8.print(" %  ");
  u8x8.setCursor(1,2);
  u8x8.print("Luz ");
  //u8x8.print(temp1);
  u8x8.setCursor(13,2);
  u8x8.print(" Lx  ");
  u8x8.setCursor(1,4);
  u8x8.print("T.Sus ");
  //u8x8.print(lux);
  u8x8.setCursor(13,4);
   u8x8.print(" C  ");
   u8x8.setCursor(1,6);
  u8x8.print("T.Amb ");
  //u8x8.print(lux);
  u8x8.setCursor(13,6);
   u8x8.print(" C  ");
   
  do{

 //u8x8.clear();
//mediciones por i2c
  float humd = sht20.readHumidity();          // Read Humidity
  float temp1 = sht20.readTemperature();       // Read Temperature
  uint16_t lux = GY302.readLightLevel();      // Read Light
   
   int reading = analogRead(sensorPin);       //lee lo que hay en pin analógico A0

    // Convert the reading into voltage:
    float voltage = reading * (3300 / 1023);

    // Convert the voltage into the temperature in degree Celsius:
    float temp2 = voltage / 10;  
// Get a reading from the temperature sensor lm35:
 // int reading = analogRead(sensorPin);       //lee lo que hay en pin analógico A0

  // Convert the reading into voltage:
//  float voltage = reading * (5000 / 1024);

  // Convert the voltage into the temperature in degree Celsius:
 // float temp2 = voltage / 10;
 
 //Pasamos a mostrar los datos en lcd

  u8x8.setCursor(7,0);
  //u8x8.print("Hum: ");
  u8x8.print(humd);
  //u8x8.print(" %");
  u8x8.setCursor(10,2);
  u8x8.print("  ");
  u8x8.setCursor(8,2);
  //u8x8.print("Temp: ");
  u8x8.print(lux);
  //u8x8.print(" C");
  u8x8.setCursor(7,4);
  //u8x8.print("Luz: ");
  u8x8.print(temp1);
   u8x8.setCursor(7,6);
  //u8x8.print("Luz: ");
  u8x8.print(temp2);
   //u8x8.print(" Lx");
 
  delay(500);
}while(digitalRead(B)==0);
  }
  
void modo2 (){
  u8x8.clear();
  do{
    float temp1 = sht20.readTemperature(); 
    float humd = sht20.readHumidity();
    uint16_t lux = GY302.readLightLevel();

    int reading = analogRead(sensorPin);       //lee lo que hay en pin analógico A0

    // Convert the reading into voltage:
    float voltage = reading * (3300 / 1023);

    // Convert the voltage into the temperature in degree Celsius:
    float temp2 = voltage / 10;
    
 // u8x8.clear();
//mediciones por i2c
if(digitalRead(A)==HIGH){
  if(menu>=4){
    menu=0;
    }
    menu++;
    delay(100);
    u8x8.clear();
    } 

     switch (menu){
  case 1:               u8x8.setCursor(0,0);
                        u8x8.inverse(); 
                        u8x8.setFont(u8x8_font_chroma48medium8_r);
                        //u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
                        u8x8.print("    Humedad     "); 
                        u8x8.setCursor(2,3);
                        u8x8.noInverse();
                        u8x8.setFont(u8x8_font_px437wyse700b_2x2_r); //3x6 font
                       u8x8.print(humd); 
                       u8x8.print(" %");
                        delay(200);
  
  break;
  case 2:               u8x8.setCursor(0,0);
                        u8x8.inverse(); 
                        u8x8.setFont(u8x8_font_chroma48medium8_r);
                        //u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
                        u8x8.print("       Luz      "); 
                          u8x8.noInverse();
                        u8x8.setFont(u8x8_font_px437wyse700b_2x2_r);
                        u8x8.setCursor(6,3);
                        u8x8.print("  ");
                        u8x8.setCursor(2,3);
                        u8x8.print(lux);
                        u8x8.setCursor(10,3);
                        u8x8.print("Lx"); 
                        delay(200);
  
  break;
  case 3 :              //float humd = sht20.readHumidity();          // Read Humidity
                        u8x8.setCursor(0,0);
                        u8x8.inverse(); 
                        u8x8.setFont(u8x8_font_chroma48medium8_r);
                        //u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
                        u8x8.print(" Temp. Sustrato "); 
                        u8x8.setCursor(2,3);
                        u8x8.noInverse();
                         
                        u8x8.setFont(u8x8_font_px437wyse700b_2x2_r);//3x6 font
                        u8x8.print(temp1); 
                        u8x8.print(" C");
                        delay(200);
  break;
   case 4 :             //int reading = analogRead(sensorPin);       //lee lo que hay en pin analógico A0

                         // Convert the reading into voltage:
                        //float voltage = reading * (5000 / 1024);

                        // Convert the voltage into the temperature in degree Celsius:
                        //float temp2 = voltage / 10;
                        u8x8.setCursor(0,0);
                        u8x8.inverse(); 
                        u8x8.setFont(u8x8_font_chroma48medium8_r);
                        //u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
                        u8x8.print(" Temp. Ambiente "); 
                        u8x8.setCursor(2,3);
                        u8x8.noInverse();
                        u8x8.setFont(u8x8_font_px437wyse700b_2x2_r); //3x6 font
                        u8x8.print(temp2); 
                        u8x8.print(" C"); 
                        delay(200);
  break;
     }
/*
  float humd = sht20.readHumidity();          // Read Humidity
  float temp1 = sht20.readTemperature();       // Read Temperature
  uint16_t lux = GY302.readLightLevel();      // Read Light
     
// Get a reading from the temperature sensor lm35:
 // int reading = analogRead(sensorPin);       //lee lo que hay en pin analógico A0

  // Convert the reading into voltage:
//  float voltage = reading * (5000 / 1024);

  // Convert the voltage into the temperature in degree Celsius:
 // float temp2 = voltage / 10;
 
 //Pasamos a mostrar los datos en lcd

  u8x8.setCursor(1,0);
  u8x8.inverse(); 
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
 u8x8.print("Humedad"); 
   u8x8.setCursor(1,2);
   u8x8.noInverse();
    u8x8.setFont(u8x8_font_inb33_3x6_n); //3x6 font
  u8x8.print(humd); 
  //u8x8.drawString(" %");
  delay(2000);
  u8x8.clear();
     u8x8.setCursor(1,0);
  u8x8.inverse();
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
 u8x8.print("Temperatura:"); 
   u8x8.setCursor(1,2);
    u8x8.setFont(u8x8_font_inb33_3x6_n);//3x6 font
    u8x8.noInverse();
  u8x8.print(temp1); 
  //u8x8.drawString(" %");
  delay(2000);
  u8x8.clear();
      u8x8.setCursor(1,0);
  u8x8.inverse();
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
 u8x8.print("Luz:"); 
   u8x8.setCursor(1,2);
    u8x8.setFont(u8x8_font_inb33_3x6_n);//3x6 font
     u8x8.noInverse();
  u8x8.print(lux); 
  //u8x8.drawString(" %");
  delay(2000);
  u8x8.clear();*/
  
  }while(digitalRead(B)==0);
  
}
  
void ayuda (){
  
  }
void informacion(){
   u8x8.clear();
   do{
    u8x8.noInverse();
   u8x8.setCursor(0,1);
  u8x8.print(" GRISMEYER 68703");
   u8x8.setCursor(0,2);
  u8x8.print(" MANOLUCOS 74868");
     u8x8.setCursor(1,3);
  u8x8.print("   U.T.N F.R.C  ");
   u8x8.setCursor(1,4);
  u8x8.print("   JUNIO 2022   ");
   u8x8.setCursor(1,5);
  u8x8.print("    VER 1.1     ");
  delay(200);
  }while(digitalRead(B)==0);
  }
