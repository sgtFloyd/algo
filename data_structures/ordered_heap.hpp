#ifndef ORDERED_HEAP_HPP
#define ORDERED_HEAP_HPP

#include "heap.hpp"

// Abstract class encapsulating shared logic between implementations of ordered heaps.
template <class T>
class OrderedHeap : public Heap<T> {
protected:
  // Declare as a dependent name, to avoid using this-> everywhere
  // See: stackoverflow.com/a/4643295/261152
  using Heap<T>::elements;

public:
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

protected:
  int significant_child(int index) {
    int right_child = this->right_child(index);
    int left_child = this->left_child(index);

    if( this->is_balanced_node(index) &&
          compare_significance(right_child, left_child) )
      return right_child;
    else
      return left_child;
  }

  void trickle_up(int index) {
    if( !this->is_root_node(index) ) {
      int parent = this->parent_node(index);
      if( compare_significance(index, parent) ) {
        std::swap(elements[index], elements[parent]);
        trickle_up(parent);
      }
    }
  }

  void trickle_down(int index) {
    if( !this->is_leaf_node(index) ) {
      int child = this->significant_child(index);
      if( compare_significance(child, index) ) {
        std::swap(elements[index], elements[child]);
        trickle_down(child);
      }
    }
  }

private:
  // Pure virtual function to be defined by inheriting classes
  virtual bool compare_significance(int, int) = 0;
};

#endif
