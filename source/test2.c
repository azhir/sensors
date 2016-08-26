#include <stdio.h>
#include <time.h>
#include <jansson.h>

int main(){

//opening our json file
  FILE *jsonFile;							 //we created a pointer called jsonFile for the file
  jsonFile = fopen ("/home/am2141/sensors/testlogs/sensor.json", "r");
//checking for error
  if (jsonFile == NULL) fprintf (stderr, "can't open file for reading\n");


//now we shall create an object to place the information in

}
