//
// Created by 79994 on 14.04.2022.
//

#ifndef UNTITLED2_VIEW_H
#define UNTITLED2_VIEW_H
#include <iostream>
#include "Model.h"

using namespace std;

class View {
 private:
  Model *model;
 public:
  View(Model *model);
  void print();
  //JS ТОП
};

#endif //UNTITLED2_VIEW_H
