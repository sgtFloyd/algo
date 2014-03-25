#include <iostream>
#include "data_structures/heap.h"

using namespace std;

int main(){
  Heap h;
  h.insert(5); cout << h << endl;
  h.insert(7); cout << h << endl;
  h.insert(2); cout << h << endl;
  h.insert(6); cout << h << endl;
  h.insert(4); cout << h << endl;
  h.insert(2); cout << h << endl;
  h.insert(2); cout << h << endl;
  h.insert(8); cout << h << endl;
  h.insert(9); cout << h << endl;
  h.insert(5); cout << h << endl;
  h.pop(); cout << h << endl;
  h.pop(); cout << h << endl;
  h.pop(); cout << h << endl;
  h.pop(); cout << h << endl;
  return 0;
}
