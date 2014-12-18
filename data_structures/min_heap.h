#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "heap.h"

class MinHeap : public Heap
{
public:
  using Heap::Heap;
  void insert(int);
  int pop();

private:
  int min_child(int);
  void trickle_up(int);
  void trickle_down(int);
};

#endif
