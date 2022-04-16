#include <iostream>
#include "Presenter.h"
#include <ctime>
using namespace std;
int main() {
  srand(time(NULL));
    Presenter *presenter=new Presenter(15);
    presenter->run();

//
    return 0;
}
