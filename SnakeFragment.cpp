//
// Created by 79994 on 15.04.2022.
//
#include <iostream>
#include "SnakeFragment.h"
SnakeFragment::SnakeFragment(int size) {
  x=rand()%size;
  y=rand()%size;
}
int SnakeFragment::getx() {
  return x;
}
int SnakeFragment::gety() {
  return y;
}