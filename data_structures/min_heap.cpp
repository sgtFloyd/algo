#include "min_heap.h"

void MinHeap::insert(int element)
{
  elements.push_back(element);
  trickle_up(size()-1);
}

int MinHeap::pop()
{
  int root = peek();
  elements[0] = elements.back();
  elements.pop_back();
  trickle_down(0);
  return root;
}

int MinHeap::min_child(int i)
{
  if( right_child(i) < size() &&
        elements[right_child(i)] < elements[left_child(i)] )
    return right_child(i);
  else
    return left_child(i);
}

void MinHeap::trickle_up(int i)
{
  if( !is_root_node(i) )
  {
    int parent = parent_node(i);
    if( elements[i] < elements[parent] )
    {
      std::swap(elements[i], elements[parent]);
      trickle_up(parent);
    }
  }
}

void MinHeap::trickle_down(int i)
{
  if( !is_leaf_node(i) )
  {
    int child = min_child(i);
    if( elements[i] > elements[child] )
    {
      std::swap(elements[i], elements[child]);
      trickle_down(child);
    }
  }
}
