#include <stdio.h>
#include <jansson.h>

int main(){

  FILE *jsonFile;
  json_t *object;
  json_error *error;

  jsonFile = fopen("/User/azhir/sensors/testlogs/sensor.json", "r");
  
  object = json_loadf (jsonFile, 0, error);

