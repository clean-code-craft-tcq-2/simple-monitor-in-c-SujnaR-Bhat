#include <stdio.h>
#include <assert.h>


/* MACROS */
#define TEMP_MIN            0
#define TEMP_MAX            45
#define SOC_MIN             20
#define SOC_MAX             80
#define CHARGERATE_MIN      0.0
#define CHARGERATE_MAX      0.8

void PrintOnConsole( char message[]){
  printf(" %s is out of range!\n", message);
}

/* Check for temerature within range */
int temperature_range (float temperature)
{
   if(temperature < TEMP_MIN || temperature > TEMP_MAX) 
   {
       PrintOnConsole("Temperature");
      return 0;
   }
      return 1;
}
  

/* check for soc within range */
int soc_range(float soc)
{
  if(soc < SOC_MIN || soc > SOC_MAX) 
  {
    PrintOnConsole("State of Charge");
    return 0;
  }
   return 1;
}
  
/* chekc for chargerate within range */
 int chargerate_range (float chargeRate)
  {
     if(chargeRate > CHARGERATE_MAX)
    {
      PrintOnConsole("Charge Rate ");
      return 0;
    }
      return 1;
  }

/* detect if battery is ok and return status  */
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
  assert(!batteryIsOk(55, 30, 0.9));
   assert(!batteryIsOk(90, 65, 0.5));
}
