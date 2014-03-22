#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <vector>
#include <iostream>

class MaxHeap
{
  std::vector<int> elements;
public:
  MaxHeap();
  void insert(int);
  int peek();
  int pop();
  std::string to_str();

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

  friend std::ostream & operator<<(std::ostream&, MaxHeap&);
};

#endif