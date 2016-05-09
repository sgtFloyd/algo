#ifndef MAX_HEAP_HPP
#define MAX_HEAP_HPP

#include "heap.hpp"

template <class T>
class MaxHeap : public Heap<T> {
protected:
  // Declare as a dependent name, to avoid using this-> everywhere
  // See: stackoverflow.com/a/4643295/261152
  using Heap<T>::elements;

public:
  using Heap<T>::Heap;

  void insert(T element) {
    elements.push_back(element);
    trickle_up(this->size()-1);
  }

  T pop() {
    T root = this->peek();
    elements[0] = elements.back();
    elements.pop_back();
    trickle_down(0);
    return root;
  }

private:
  int max_child(int index) {
    if( this->right_child(index) < this->size() &&
          elements[this->right_child(index)] > elements[this->left_child(index)] )
      return this->right_child(index);
    else
      return this->left_child(index);
  }

  void trickle_up(int index) {
    if( !this->is_root_node(index) ) {
      int parent = this->parent_node(index);
      if( elements[index] > elements[parent] ) {
        std::swap(elements[index], elements[parent]);
        trickle_up(parent);
      }
    }
  }

  void trickle_down(int index) {
    if( !this->is_leaf_node(index) ) {
      int child = max_child(index);
      if( elements[index] < elements[child] ) {
        std::swap(elements[index], elements[child]);
        trickle_down(child);
      }
    }
  }

};

#endif
