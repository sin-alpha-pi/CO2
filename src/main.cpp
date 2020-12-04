#include <Arduino.h>
#include <Wire.h>
#include "SparkFun_SCD30_Arduino_Library.h" 
SCD30 sensor;

void setup()
{
  Serial.begin(115200);
  Wire.begin(4, 5);
  if (sensor.begin(Wire, false) != true)
  {
    Serial.println("not detected");
    while (1);
  }
}

void loop(){
  if (Serial.available()){
    if (Serial.readStringUntil('\n') == "cal"){
      Serial.println("CALIBRATION");
      sensor.setAltitudeCompensation(409);
      sensor.setAmbientPressure(1003);
      sensor.setForcedRecalibrationFactor(400);
    }
  }
    
  if (sensor.dataAvailable()){
    Serial.println(sensor.getCO2());
  }
}