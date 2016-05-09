#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <vector>
#include "../data_structures/min_heap.hpp"

template <class T>
class HeapSort {
public:
  static std::vector<T> sort(std::vector<T> elements) {
    MinHeap<T> heap;
    for(int i=0; i<elements.size(); i++) {
      heap.insert(elements[i]);
    }

    std::vector<T> sorted;
    for(int i=0; i<heap.size(); i++) {
      sorted.push_back(heap.pop());
    }
    return sorted;
  };
};

#endif
