#include "Wire.h"       
#include "I2Cdev.h"     
#include "MPU6050.h"    

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

struct MyData {
  byte X;
  byte Y;
};

MyData data;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
}

void loop()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  data.X = map(ax, -17000, 17000, 0, 255 ); // X axis data
  data.Y = map(ay, -17000, 17000, 0, 255);  // Y axis data
  delay(500);
//  Serial.print("Axis X = ");
//  Serial.print(data.X);
//  Serial.print("  ");
//  Serial.print("Axis Y = ");
//  Serial.println(data.Y);
   if (data.Y < 60) { 
    Serial.println("gesture 1");
    }
 if (data.Y > 145) {
  Serial.println("gesture 2");
    }
 if (data.X > 155) {
  Serial.println("gesture 3");
    }
 if (data.X < 80) {
  Serial.println("gesture 4");
    }
 if (data.X > 100 && data.X < 170 && data.Y > 80 && data.Y < 130) {
    Serial.println("gesture 5");
    }

}
