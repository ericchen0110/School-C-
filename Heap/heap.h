#ifndef HEAP_H
#define HEAP_H
#include <iostream>

using namespace std;

class heap {
 public:
  heap();
  void addNum(int num);
  int remove();
  bool moveUp(int index);
  void moveDown(int index);
  void display(int locaiton, int space);

  int parent(int index);
  int left(int index);
  int right(int index);

  int* get_arr();
 private:
  int* heap_arr = new int[101];
  int get_min(int i, int count);
};

#endif
