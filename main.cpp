#include <iostream>
#include "data_structures/heap.h"

using namespace std;

int main(){
  Heap h;
  cout << h.getElements()[0] << endl;
  int elements[] = {5,6};
  h.setElements(elements);
  cout << h.getElements()[0] << endl;
  return 0;
}
