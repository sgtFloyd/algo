#include <iostream>
#include "data_structures/heap.h"

using namespace std;

int main(){
  Heap h;
  h.setValue(123);
  cout << h.getValue() << endl;
  return 0;
}
