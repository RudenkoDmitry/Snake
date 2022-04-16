//
// Created by 79994 on 16.04.2022.
//

#include "Fruit.h"
#include <iostream>

Fruit::Fruit() {
  x=0;
  y=0;
}
int Fruit::getx() {
  return x;
}
int Fruit::gety() {
  return y;
}
void Fruit::setRandomValues(int size) {
  x=rand()%size;
  y=rand()%size;
}