#include "light.h"
#include "dlight.h"

Light main = Light(4);
DimmableLight bulk = DimmableLight(5);
DimmableLight wall = DimmableLight(6);
Light column = Light(7);

Light lights[4] = { main, bulk, wall, column };

//Setup States
void setup()
{
  for (int i=0; i<4; i++)
    lights[i].Setup();
    
  main.On();
  bulk.On();
  wall.Off();
  column.On();
}



void loop() 
{
  //main.Off();
  wall.SetTarget(127);
  //wall.On();
  //wall.AdjustTarget(10);
  
  // Update
  for (int i=0; i<4; i++)
  {
    lights[i].Update();
  }
}


