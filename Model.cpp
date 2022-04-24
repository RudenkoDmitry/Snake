//
// Created by 79994 on 14.04.2022.
//

#include "Model.h"
#include "Fruit.h"
#include <ctime>

Model::Model(int n) {
  snake.addLast(SnakeFragment{n / 2, n / 2, 0, 1});
  size = n;
  field = new char *[n];
  for (int i = 0; i < n; i++) {
    field[i] = new char[n];
    for (int j = 0; j < n; ++j) {
      field[i][j] = '.';
    }
  }

}
void Model::addFragmentToTail() {
  SnakeFragment tail = snake.getLast()->value;
  snake.addLast(SnakeFragment{abs((tail.x + tail.dx) % size), abs((tail.y + tail.dy) % size), tail.dx, tail.dy});

}
void Model::addFruitToField() {

  Fruit fruit;

  fruit.setRandomValues(size);
  field[fruit.gety()][fruit.getx()] = 'F';
  //ddSnakeToField();
}
//void Model::addSnakeToField() {
//fillField();

//  for (int i = 0; i < snake.getSize(); ++i) {
//    SnakeFragment fragment = snake.getForIndex(i)->value;
//    field[fragment.y][fragment.x] = (i == 0 ? '%' : '8');
//
//
//  }
//}
//void Model::fillField() {
//  for (int i = 0; i < size; ++i) {
//    for (int j = 0; j < size; ++j) {
//      field[i][j] = '.';
//
//    }
//  }
// }
void Model::addFragmentToHead(int dx, int dy) {

  SnakeFragment head = snake.getFirst()->value;
  SnakeFragment temp = SnakeFragment{(head.x - dx) % size, (head.y - dy) % size, dx, dy};

  if (temp.x < 0) { temp.x = size - 1; }
  if (temp.y < 0) { temp.y = size - 1; }
  snake.addFirst(temp);

}
void Model::move(int dx, int dy) {

  if (snake.getFirst()->value.x == snake.getForIndex(1)->value.x + snake.getForIndex(1)->value.dx
      && snake.getFirst()->value.y == snake.getForIndex(1)->value.y + snake.getForIndex(1)->value.dy
      && snake.getSize() > 2) {
    flag = false;
    cout << "Game over" << '\n';
  }

  for (int i = 0; i < snake.getSize(); ++i) {
    SnakeFragment fragment = snake.getForIndex(i)->value;
    for (int j = i + 1; j < snake.getSize() - 1; ++j) {
      SnakeFragment thisfragment = snake.getForIndex(j)->value;
      if (thisfragment.x == fragment.x && thisfragment.y == fragment.y) {
        flag = false;

        // snake.getFirst()->value.y=size+1;
        cout << "Game over" << '\n';
      }
    }
  }
  if (field[(snake.getFirst()->value.y - dy) % size < 0 ? size - 1 :
            (snake.getFirst()->value.y - dy) % size][(snake.getFirst()->value.x
      - dx) % size < 0 ? size - 1 : (snake.getFirst()->value.x
      - dx) % size] == 'F') {
    addFragmentToTail();
    field[(snake.getFirst()->value.y - snake.getFirst()->value.dy) % size][(snake.getFirst()->value.x
        - snake.getFirst()->value.dx) % size] = '.';
    score += 10;
    addFruitToField();
  } else {
//    int count = 0;
//
//    for (int i = 0; i < size; i++) {
//      for (int j = 0; j < size; j++) {
//        if (field[i][j] == 'F') { count++; }
//      }
//
//    }
//    if (count == 0) {
//      addFragmentToTail();
//      field[(snake.getFirst()->value.y - snake.getFirst()->value.dy) % size][(snake.getFirst()->value.x
//          - snake.getFirst()->value.dx) % size] = '.';
//      addFruitToField();
//    }
  }
  field[snake.getLast()->value.y][snake.getLast()->value.x] = '.';
  field[snake.getFirst()->value.y][snake.getFirst()->value.x] = '8';
  addFragmentToHead(dx, dy);
  snake.del(snake.getSize() - 1);
  field[snake.getFirst()->value.y][snake.getFirst()->value.x] = '%';

}
char **Model::GetField() const {
  return field;
}
int Model::GetSize() const {
  return size;
}

//if (field[(snake.getFirst()->value.y - snake.getFirst()->value.dy) % size < 0 ? size - 1 :
//(snake.getFirst()->value.y - snake.getFirst()->value.dy) % size][(snake.getFirst()->value.x
//- snake.getFirst()->value.dx) % size < 0 ? size - 1 : (snake.getFirst()->value.x
//- snake.getFirst()->value.dx) % size] == 'F') {
//addFragmentToTail();
//field[(snake.getFirst()->value.y - snake.getFirst()->value.dy) % size][(snake.getFirst()->value.x
//- snake.getFirst()->value.dx) % size] = '.';
//addFruitToField();
//}