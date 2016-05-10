#ifndef MAX_HEAP_HPP
#define MAX_HEAP_HPP

#include "ordered_heap.hpp"

template <class T>
class MaxHeap : public OrderedHeap<T> {
private:
  bool compare_significance(int index_a, int index_b) {
    return this->elements[index_a] > this->elements[index_b];
  }
};

#endif
