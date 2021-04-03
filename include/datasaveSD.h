/********************************************************* 
  Adafruit Datalogger SD Card
  ********************************************************/

#include <SD.h>                   

// SD Card
Sd2Card card;
SdVolume volume;
SdFile root;
File dataFile;
String dash = " - ";
String slash = "/";
String csv = ", ";
const int chipSelect = 10;
char filename[] = "LOGGER00.txt";