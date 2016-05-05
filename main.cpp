#include <iostream>
#include "data_structures/array.cpp"

int main (int argc, char *argv[])
{
  Array<int> a;
  a[0] = 44;
  a[31] = 55;
  std::cout << a[31] << std::endl;
  return 0;
}
