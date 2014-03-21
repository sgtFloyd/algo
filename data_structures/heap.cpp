#include "heap.h"

Heap::Heap()
{
}

void Heap::setElements(int* new_elements)
{
  elements = new_elements;
}

int* Heap::getElements()
{
  return elements;
}
