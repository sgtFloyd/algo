#include "heap.h"

Heap::Heap()
{
  elements = -1;
}

Heap::Heap(int new_elements)
{
  elements = new_elements;
}

void Heap::setElements(int new_elements)
{
  elements = new_elements;
}

int Heap::getElements()
{
  return elements;
}
