#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>
#include "../std_ext.h"

class Heap
{
public:
  Heap(){};
  void insert(int);
  int peek() const;
  int pop();

protected:
  std::vector<int> elements;

  int parent_node(int);
  int left_child(int);
  int right_child(int);

  bool is_root_node(int);
  bool is_leaf_node(int);

  friend std::ostream& operator<<(std::ostream&, Heap&);
};

#endif
