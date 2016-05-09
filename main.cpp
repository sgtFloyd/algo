#include <iostream>
#include "data_structures/dynamic_array.hpp"

int main (int argc, char *argv[])
{
  DynamicArray<int> a;
  a[0] = 44;
  a[31] = 55;
  std::cout << a[31] << std::endl;
  return 0;
}
