#ifndef light_h
#define light_h

#include <Arduino.h>

class Light
{
  protected:
    int _pin;
    int _cLevel;
    int _tLevel;
  public:
    Light(int pin);
    virtual void Setup();
    virtual void Update();
    virtual void On();
    virtual void Off();
    virtual void Toggle();
};

Light::Light(int pin)
{
  _pin = pin;
  _cLevel = -1;
  _tLevel = 0;
}

void Light::Setup()
{
   pinMode(_pin, OUTPUT);
}

void Light::Update()
{
  if (_cLevel != _tLevel)
  {
    _cLevel = _tLevel;
    analogWrite(_pin, _cLevel);
  }
}

void Light::On()
{
  _tLevel = 1;
}

void Light::Off()
{
  _tLevel = 0;
}

void Light::Toggle()
{
  if (_cLevel == 0)
     On();
   else
     Off();
}

#endif
