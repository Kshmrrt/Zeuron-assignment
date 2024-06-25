#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  // Initialize MPU6050
  Serial.println("Initializing MPU6050...");
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_16G)) {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
  
  Serial.println("MPU6050 ready.");
}

void loop() {
  Vector rawAccel = mpu.readRawAccel();
  Vector normAccel = mpu.readNormalizeAccel();
  
  // Print raw and normalized accelerometer data
  Serial.print("Raw Accel X: "); Serial.print(rawAccel.XAxis);
  Serial.print(" Y: "); Serial.print(rawAccel.YAxis);
  Serial.print(" Z: "); Serial.print(rawAccel.ZAxis);
  Serial.print("\tNorm Accel X: "); Serial.print(normAccel.XAxis);
  Serial.print(" Y: "); Serial.print(normAccel.YAxis);
  Serial.print(" Z: "); Serial.println(normAccel.ZAxis);
  
  delay(100); // Adjust delay as needed for your application
}
