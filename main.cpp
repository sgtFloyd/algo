#include <iostream>
#include "data_structures/heap.h"

using namespace std;

int p(int i){
  cout << i << endl;
}

int main(){
  Heap h;
  h.insert(5); p(h.peek());
  h.print_elements();
  h.insert(7); p(h.peek());
  h.print_elements();
  h.insert(2); p(h.peek());
  h.print_elements();
  h.insert(6); p(h.peek());
  h.print_elements();
  h.pop(); p(h.peek());
  h.print_elements();
  h.pop(); p(h.peek());
  h.print_elements();
  return 0;
}
