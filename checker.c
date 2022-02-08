#include <stdio.h>
#include <assert.h>
#include "checker.h"



int temperature_range (float temperature)
{
   if(temperature < 0 || temperature > 45) 
   {
       printf("Temperature out of range!\n");
      return 0;
   }
      return 1;
}
  
int soc_range(float soc)
{
  if(soc < 20 || soc > 80) 
  {
    printf("State of Charge out of range!\n");
    return 0;
}
   return 1;
  
  int chargerate_range (float chargeRate)
  {
    if(chargeRate > 0.8)
    {
      printf("Charge Rate out of range!\n");
      return 0;
    }
      return 1;
}


int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
