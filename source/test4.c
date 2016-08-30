#include <stdio.h>
#include <jansson.h>

int main(){

  FILE *jsonFile;
  json_t *object;
  json_error_t *error;

  //Opening Document and Creating Object 

 jsonFile = fopen("/User/azhir/sensors/testlogs/sensor.json", "r");
 object = json_loadf (jsonFile, 0, error);



 //Searching through Object for Values

 value = json_object_get (myObject, "Readings");

 json_object_foreach (myObject, key, value){
   fprintf (stdout, "found key %s\n", key);
 }





}
