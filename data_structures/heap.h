#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap
{
  std::vector<int> elements;
public:
  Heap();
  void insert(int);
  int peek();
  int pop();
  void print_elements();
private:
  int parent_node(int);
  int left_child(int);
  int right_child(int);
  int max_child(int);

  bool is_root_node(int);
  bool is_leaf_node(int);

  void swap(int, int);
  void trickle_up(int);
  void trickle_down(int);
};

#endif
