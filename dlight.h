#ifndef dlight_h
#define dlight_h

#include "light.h"

class DimmableLight : public Light
{
  private:
    void AdjustCurrent(int adjustment);
    void SetCurrent(int current);
  public:
    DimmableLight(int pin);
    virtual void Update();
    void On();
    void Off();
    void AdjustTarget(int adjustment);
    void SetTarget(int target);
};

DimmableLight::DimmableLight(int pin) : Light(pin)
{
}

void DimmableLight::AdjustCurrent(int adjustment)
{
  int newCurrent = _cLevel + adjustment;
  
  if (adjustment > 0)
    SetCurrent(min(_tLevel, newCurrent));
  else
    SetCurrent(max(_cLevel, newCurrent)); 
}

void DimmableLight::SetCurrent(int current)
{
  if (current >= 0)
    _cLevel = min(current, 255);
  else
    _cLevel = 0;
}

void DimmableLight::AdjustTarget(int adjustment)
{
  int newTarget = _tLevel + adjustment;
  SetTarget(newTarget);
}

void DimmableLight::SetTarget(int target)
{
  if (target >= 0)
    _tLevel = min(target, 255);
  else
    _tLevel = 0;
}

void DimmableLight::Update()
{
  if (_cLevel = -1)
  {
    SetCurrent(_tLevel);
    analogWrite(_pin, _cLevel);
  }
  else if (_tLevel < _cLevel)
  {
    AdjustCurrent(-10);
    analogWrite(_pin, _cLevel);
  }
  else if (_tLevel > _cLevel)
  {
    AdjustCurrent(+10);
    analogWrite(_pin, _cLevel);
  }
}

void DimmableLight::On()
{
  SetTarget(255);
}

void DimmableLight::Off()
{
  SetTarget(0);
}

#endif


