#include <stdio.h>
#include <assert.h>


/* MACROS */
#define TEMP_MIN            0
#define TEMP_MAX            45
#define SOC_MIN             20
#define SOC_MAX             80
#define CHARGERATE_MIN      0.0
#define CHARGERATE_MAX      0.8


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

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
   int status ;
    
   status = (temperature_range(temperature)) && (soc_range(soc)) && (chargerate_range(chargeRate)) ;
   return (status);
}
   
int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
