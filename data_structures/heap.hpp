#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>
#include <iostream>
#include "../std_ext.hpp"

class Heap {
public:
  explicit Heap(){};

  int size() {
    return elements.size();
  }

  void insert(int element) {
    elements.push_back(element);
  }

  int peek() const {
    return elements.front();
  }

  int pop() {
    int root = peek();
    elements.erase(elements.begin());
    return root;
  }

protected:
  std::vector<int> elements;

  static int parent_node(int index) {
    return (index-1) / 2;
  }

  static int left_child(int index) {
    return (index*2) + 1;
  }

  static int right_child(int index) {
    return (index*2) + 2;
  }

  bool is_root_node(int index) {
    return index == 0;
  }

  bool is_leaf_node(int index) {
    return left_child(index) >= size();
  }

  friend std::ostream& operator<<(std::ostream &os, Heap &h) {
    return os << h.elements;
  };
};

#endif
