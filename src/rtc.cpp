#include <rtc.h>

void initRTXC()
{
    //tft.println("Initializing RTC...");

  if (! rtc.begin()) 
  {
    //tft.print("RTC");
    //tft.setTextColor(ST77XX_RED);
    //tft.print("FAIL\n");
    //tft.setTextColor(ST77XX_BLUE);

    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (! rtc.initialized() || rtc.lostPower()) 
  {
    Serial.println("RTC is NOT initialized, set the time.");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));         // Sets the RTC with an explicit date & time
  }

  rtc.start();

  // PCF8523 Calibration Coefficients
  // https://www.nxp.com/docs/en/application-note/AN11247.pdf
  float drift = 0;                   // seconds plus or minus over observation period - set to 0 to cancel previous calibration.
  float period_sec = (7 * 86400);     // total observation period in seconds (86400 = seconds in 1 day:  7 days = (7 * 86400) seconds )
  float deviation_ppm = (drift / period_sec * 1000000); //  deviation in parts per million (μs)
  float drift_unit = 4.34;            // use with offset mode PCF8523_TwoHours
  // float drift_unit = 4.069; //For corrections every min the drift_unit is 4.069 ppm (use with offset mode PCF8523_OneMinute)
  int offset = round(deviation_ppm / drift_unit);
  // rtc.calibrate(PCF8523_TwoHours, offset);   // Un-comment to perform calibration once drift (seconds) and observation period (seconds) are correct
  // rtc.calibrate(PCF8523_TwoHours, 0);        // Un-comment to cancel previous calibration
  Serial.print("Offset is ");  Serial.println(offset); // Print to control offset


  //tft.print("RTC - ");
  //tft.setTextColor(ST77XX_GREEN);
  //tft.print("PASS\n");
  //tft.setTextColor(ST77XX_BLUE);
  Serial.print("RTC - PASS\n");
}