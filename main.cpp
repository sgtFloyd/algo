#include <iostream>
#include "data_structures/heap.h"

using namespace std;

int main(){
  Heap h;
  h.insert(5);
  cout << h.peek() << endl;
  h.insert(2);
  cout << h.pop() << endl;
  cout << h.peek() << endl;
  return 0;
}
