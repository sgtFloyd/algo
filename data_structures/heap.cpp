#include "heap.h"

Heap::Heap()
{
}

void Heap::insert(int element)
{
  elements.push_back(element);
}

int Heap::peek()
{
  return elements.back();
}

int Heap::pop()
{
  int last_val = peek();
  elements.pop_back();
  return last_val;
}
