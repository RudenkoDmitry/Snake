//
// Created by 79994 on 14.04.2022.
//

#include "windows.h"
#include "View.h"
void View::print() {

  system("cls");
  for (int i = 0; i < model->GetSize(); i++) {
    for (int j = 0; j < model->GetSize(); j++) {
      cout << model->GetField()[i][j];
    }
    cout << '\n';
  }
}
View::View(Model *model) {
  this->model=model;
}
