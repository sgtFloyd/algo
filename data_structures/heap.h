#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap
{
  std::vector<int> elements;
public:
  Heap();
  void insert(int);
  int peek();
  int pop();
};

#endif
