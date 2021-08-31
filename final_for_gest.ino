#include<Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(115200);
}
void loop(){
  
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  

    if(AcX>13000&&AcX<20000)
    {
    Serial.println("Hello Sir Good Evening");   //gesture 1
   delay(3000);
      }
    if(AcY>14000&&AcY<16500)
    {
    Serial.println("We have done some work on this"); //gesture 2
  delay(3000);
    }
    if(AcY>-17000&&AcY<-13500)
    {
    Serial.println("Do you have any questions");    //gesture 3
 delay(3000);
    }
    if(AcX>-15500&&AcX<-13500)
    {
    Serial.println("We will gladly answer them all"); //gesture 4
  delay(3000);
     }
    
    if(AcX>11000&&AcX<20000&&AcY>4000&&AcY<12000)
    {
    Serial.println("It was a nice experience");   //gesture 5
   delay(3000);
      }
    if(AcX>10000&&AcX<20000&&AcY>-11000&&AcY<-5000)
    {
     Serial.println("Hope to work on this in future again");  //gesture 6
   delay(3000);
      }
    if(AcX>-15500&&AcX<-11500&&AcY>8000&&AcY<15000)
    {
     Serial.println("Thanks for all the guidance and support"); //gesture 7
  delay(3000);
      }
     if(AcX>-15000&&AcX<-9500&&AcY>-12000&&AcY<-4000)
    {
    Serial.println("Hope you have liked our effort");   //gesture 8
    delay(3000);
    }
    if(AcZ>-18000&&AcZ<-13000&&AcX>-1000&&AcX<4000)
    {
    Serial.println("Thankyou");   //gesture 9
   delay(3000);
     }
     
  delay(333);
}
