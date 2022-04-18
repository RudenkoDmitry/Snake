//
// Created by 79994 on 14.04.2022.
//
#include <chrono>
#include "View.h"
#include "Model.h"
#ifndef UNTITLED2__PRESENTER_H_
#define UNTITLED2__PRESENTER_H_

class Presenter {
 private:
  Model *model;
  View *view;
  long  timer;
 public:
  static void drawThread(Model &model, int &dx, int &dy);
  Presenter(int size);
  long timeNow();
  //JS TOP
   int run();
};

#endif //UNTITLED2__PRESENTER_H_
