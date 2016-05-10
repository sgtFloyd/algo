#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>
#include <iostream>
#include "../std_ext.hpp"

template <class T>
class Heap {
public:
  explicit Heap(){};

  // Returns the number of elements in the heap.
  int size() {
    return elements.size();
  }

  // Adds a new element at the end of the heap.
  void insert(T element) {
    elements.push_back(element);
  }

  // Returns a reference to the first element in the heap.
  T peek() const {
    return elements.front();
  }

  // Removes and returns the first element in the heap.
  T pop() {
    T root = peek();
    elements.erase(elements.begin());
    return root;
  }

protected:
  std::vector<T> elements;

  // Returns the index of the given node's parent.
  static int parent_node(int index) {
    return (index-1) / 2;
  }

  // Returns the index of the given node's left child.
  static int left_child(int index) {
    return (index*2) + 1;
  }

  // Returns the index of the given node's right child.
  static int right_child(int index) {
    return (index*2) + 2;
  }

  // Returns true if the given node is the root node.
  static bool is_root_node(int index) {
    return index == 0;
  }

  // Returns true if the given node has no children.
  bool is_leaf_node(int index) {
    return left_child(index) >= size();
  }

  // Returns true if the given node has two children.
  bool is_balanced_node(int index) {
    return right_child(index) < size();
  }

  friend std::ostream&
  operator<<(std::ostream &os, Heap &h) {
    return os << h.elements;
  };
};

#endif
