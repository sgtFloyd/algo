#include "data_structures/min_heap.cpp"

int main (int argc, char *argv[])
{
  MinHeap h;
  h.insert(10);
  h.insert(8);
  h.insert(6);
  h.insert(4);
  h.insert(2);
  h.insert(0);
  std::cout << h << std::endl;
  return 0;
}
