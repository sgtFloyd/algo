#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP

#include "ordered_heap.hpp"

template <class T>
class MinHeap : public OrderedHeap<T> {
private:
  bool compare_significance(int index_a, int index_b) {
    return this->elements[index_a] < this->elements[index_b];
  }
};

#endif
