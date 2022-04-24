//
// Created by 79994 on 16.04.2022.
//

#ifndef UNTITLED2__FRUIT_H_
#define UNTITLED2__FRUIT_H_

class Fruit {
 public:
  Fruit();
  int getx();
  int gety();
  int getScore();
  void setScore(int score);
  void setRandomValues(int size);
 private:
  int x;
  int y;
  int score;
};

#endif //UNTITLED2__FRUIT_H_
