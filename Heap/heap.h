#ifndef HEAP_H
#define HEAP_H
#include <iostream>

using namespace std;

class heap {
 public:
  heap();
  void addNum(int num);
  int remove();
  void moveUp(int index);
  void moveDown(int index);

  int parent(int index);
  int left(int index);
  int right(int index);

 private:
  int* heap_arr = new int[101];
};

#endif
