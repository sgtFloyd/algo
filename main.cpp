#include <iostream>
#include "data_structures/max_heap.h"

using namespace std;

int main(){
  MaxHeap h;
  h.insert(5);
  cout << h << endl;
  h.insert(7);
  cout << h << endl;
  h.insert(2);
  cout << h << endl;
  h.insert(6);
  cout << h << endl;
  h.pop();
  cout << h << endl;
  h.pop();
  cout << h << endl;
  return 0;
}
