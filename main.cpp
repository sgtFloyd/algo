#include <iostream>
#include "data_structures/heap.h"

using namespace std;

int main(){
  Heap h;
  cout << h.getElements() << endl;
  h.setElements(123);
  cout << h.getElements() << endl;
  return 0;
}
