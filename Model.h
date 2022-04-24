//
// Created by 79994 on 14.04.2022.
//

#ifndef UNTITLED2_MODEL_H
#define UNTITLED2_MODEL_H
using namespace std;
#include "LinkedList.h"
#include <ctime>
#include "Fruit.h"
class Model {
 private:

  struct SnakeFragment {
    int x;
    int y;
    int dx;
    int dy;

  };
  //Fruit fruit;
  //void fillField();
  LinkedList<SnakeFragment> snake;
  //void addSnakeToField();

  char **field;
  int size = 0;


 public:
  bool flag = true;
  //void addSnakeToField();
  void addFragmentToTail();
  void addFruitToField();
  int score=0;

  void addFragmentToHead(int dx, int dy);
  void move(int dx, int dy);
  Model(int n);

  char **GetField() const;
  int GetSize() const;

};

#endif //UNTITLED2_MODEL_H
