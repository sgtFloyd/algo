#ifndef MAX_HEAP_HPP
#define MAX_HEAP_HPP

#include "heap.hpp"

class MaxHeap : public Heap {
public:
  using Heap::Heap;

  void insert(int element) {
    elements.push_back(element);
    trickle_up(size()-1);
  }

  int pop() {
    int root = peek();
    elements[0] = elements.back();
    elements.pop_back();
    trickle_down(0);
    return root;
  }

private:
  int max_child(int index) {
    if( right_child(index) < size() &&
          elements[right_child(index)] > elements[left_child(index)] )
      return right_child(index);
    else
      return left_child(index);
  }

  void trickle_up(int index) {
    if( !is_root_node(index) ) {
      int parent = parent_node(index);
      if( elements[index] > elements[parent] ) {
        std::swap(elements[index], elements[parent]);
        trickle_up(parent);
      }
    }
  }

  void trickle_down(int index) {
    if( !is_leaf_node(index) ) {
      int child = max_child(index);
      if( elements[index] < elements[child] ) {
        std::swap(elements[index], elements[child]);
        trickle_down(child);
      }
    }
  }

};

#endif
