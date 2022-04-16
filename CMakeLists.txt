cmake_minimum_required(VERSION 3.21)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled2 main.cpp Model.cpp Model.h View.cpp View.h Presenter.cpp Presenter.h LinkedList.h SnakeFragment.cpp SnakeFragment.h Fruit.cpp Fruit.h)
