// LezioniCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class animal{
  int weight;
  double speed;

public:
  animal(int w, double s) : weight(w), speed(s) {}

  animal(const animal& a) : weight(a.weight), speed(a.speed) {}

  int get_weight()
  {
    return weight;
  }

  virtual void eat(const animal& a)
  {
    weight += a.weight;
  }
  
};

class dog: public animal
{

};

int main()
{
}

