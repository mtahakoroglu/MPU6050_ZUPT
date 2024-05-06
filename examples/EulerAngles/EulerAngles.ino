#include <MPU6050_ZUPT.h>
#include <Servo.h>

Servo motor;
MPU6050 mpu6050(Wire);

void setup() {
  motor.attach(9);
  Serial.begin(57600);
  Wire.begin(100);
  mpu6050.begin(200); // f = 200Hz
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();
  float roll = mpu6050.getAngleX();
  float pitch = mpu6050.getAngleY();
  float yaw = mpu6050.getAngleZ();
  int pwm_signal = map(pitch, 0, 90, 1000, 2000);
  motor.writeMicroseconds(pwm_signal);
  Serial.print("Roll: "); Serial.print(roll);
  Serial.print(" Pitch: "); Serial.print(pitch);
  Serial.print(" Yaw: "); Serial.println(yaw);
}