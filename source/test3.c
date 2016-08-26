#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <math.h>
#include "jansson.h"


int main (){
  json_t *myObject, *myArrayObj, *value;
  json_error_t jsonError;
  const char *key;

  FILE *jsonFile;
  jsonFile = fopen ("/Users/azhir/sensors/testlogs/sensor.json", "r");

  if (jsonFile == NULL) fprintf (stderr, "can't open file for reading\n");

  myObject = json_loadf (jsonFile, 0, &jsonError);
  if (!myObject){
    fprintf (stderr, "%s at line %d in %s\n", jsonError.text, jsonError.line, jsonError.source);
    return -1;
  }

  json_object_foreach (myObject, key, value){
    fprintf (stdout, "found key %s\n", key);
  }

  value = json_object_get (myObject, "Readings");

  fprintf (stdout, " there are %ld readings\n", json_array_size (value));

  myObject = json_object();
  myArrayObj = json_array();

  json_object_set (myObject, "email address", json_string ("am2141@cam.ac.uk"));
  json_object_set (myObject, "room", json_string ("Trojan Room"));
  json_object_set (myObject, "age", json_integer (22));

  json_array_append (myArrayObj, json_string("wombat"));
  json_array_append (myArrayObj, json_string("foo"));
  json_array_append (myArrayObj, myObject);

  json_dumpf (myArrayObj, jsonFile, JSON_ENCODE_ANY);
  fprintf (jsonFile, "\n");
  return 1;
}
