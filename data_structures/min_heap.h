#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <vector>
#include <sstream>

class MinHeap
{
public:
  MinHeap();
  void insert(int);
  int peek() const;
  int pop();
  std::string to_str() const;

private:
  std::vector<int> elements;

  int parent_node(int);
  int left_child(int);
  int right_child(int);
  int min_child(int);

  bool is_root_node(int);
  bool is_leaf_node(int);

  void trickle_up(int);
  void trickle_down(int);

  friend std::ostream & operator<<(std::ostream&, MinHeap&);
};

#endif
