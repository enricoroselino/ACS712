#include <LibPrintf.h>

#define sampelData 100
#define pin A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  arusSensor();
  delay(2000);
}

void arusSensor(){
  /*
   * Multiplier Value : 5A = 0.185, 20A = 0.100, 30A = 0.066
   * offset value is typically in 2.5 range
   */
  unsigned long sensorRead;
  float voltageMean, current,
  offset = 0,
  multiplier = 0.1;
  sensorRead = 0;
  analogRead(pin);
  for(int i = 0; i < sampelData; i++){
    sensorRead += analogRead(pin);
  }
  voltageMean = ((sensorRead / (float)sampelData) * (5.0 / 1024.0)) - offset;
  current = voltageMean / multiplier;
  //printf("Change offset to = %.5f \n", abs(0 - voltageMean)); //Calibrate when the sensor not connected
  printf("ADC Voltage = %f", voltageMean);
  printf("\nArus = %f A\n",current);
}
