//
// Created by 79994 on 14.04.2022.
//

#include "Presenter.h"
#include<thread>
#include "windows.h"
#include<conio.h>
#include <ctime>
using namespace std;

void Presenter::drawThread(Model &model, int &dx, int &dy) {
  this_thread::sleep_for(7000ms);
  model.move(dx, dy);
}

Presenter::Presenter(int size) {
  model = new Model(size);
  view = new View(model);

  //Kotlin top

}
long Presenter::timeNow() {
  return
      std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()).time_since_epoch().count();
}
int Presenter::run() {
  bool flag = true;
  while (flag) {
    model->addFragmentToHead(0, 1);
    model->addFragmentToHead(0, 1);
    view->print();
    int dx = 0;
    int dy = 1;
    timer = timeNow();
    model->addFruitToField();
    //std::thread thr(ref(drawThread), ref(model), &dx, &dy);
    while (model->flag != false) {

      if (timeNow() - timer >= 500) {

        model->move(dx, dy);
        //model->addFruitToField();
        //system("cls");
        view->print();
        cout << '\n' << '\n';
        if (_kbhit()) {
          switch (_getch()) {
            case 'w': {
              dx = 0;
              dy = 1;
              break;
            }
            case 's': {
              dx = 0;
              dy = -1;
              break;
            }
            case 'a': {
              dx = 1;
              dy = 0;
              break;
            }
            case 'd': {
              dx = -1;
              dy = 0;
              break;
            }
          }
        }
        timer = timeNow();
      }

    }

    cout << "If you want to restart press 'x'" << '\n' << "If you want to stop the game press 't'" << '\n'<<"Your record of score:   "<<maxScore;
    Sleep(5000);
    if (_kbhit()) {
      switch (_getch()) {
        case 'x': {
          if (model->score>maxScore){
            maxScore=model->score;
          }

          model = new Model(model->GetSize());
          view = new View(model);
          system("cls");
          Sleep(1000);
          cout << '\n' << '\n' << '\n' << '\t' << '\t' << "Game started...";
          Sleep(4000);

          break;
        }
        case 't': {

          cout << "Game over finally" << '\n';
          Sleep(5000);
          flag = false;
          break;
        }
      }

    }
  }
}
//if(!model->flag){
//cout<<"If you want to restart press 'x'"<<'\n';
//if (_kbhit()) {
//switch (_getch()) {
//case 'x': {
//model = new Model(model->GetSize());
//break;
//}
//case 't':{
//break;
//
//}
//}
//
//}
//}
