#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "heap.h"
#include <vector>
#include <sstream>

class MaxHeap : public Heap
{
public:
  MaxHeap();
  void insert(int);
  int pop();

private:
  int max_child(int);
  void trickle_up(int);
  void trickle_down(int);
};

#endif
