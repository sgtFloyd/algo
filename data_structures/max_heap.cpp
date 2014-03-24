#include "max_heap.h"

MaxHeap::MaxHeap(){} // constructor

void MaxHeap::insert(int element)
{
  elements.push_back(element);
  trickle_up(elements.size()-1);
}

int MaxHeap::peek() const
{
  return elements.front();
}

int MaxHeap::pop()
{
  int root = peek();
  elements[0] = elements.back();
  elements.pop_back();
  trickle_down(0);
  return root;
}

std::string MaxHeap::to_str() const
{
  std::ostringstream ss;
  ss << "[";
  for(int i=0; i<elements.size(); i++)
  {
    if( i != 0 ) ss << ", ";
    ss << elements[i];
  }
  ss << "]";
  return ss.str();
}

int MaxHeap::parent_node(int i){ return (i-1) / 2; }
int MaxHeap::left_child(int i){ return (i*2) + 1; }
int MaxHeap::right_child(int i){ return (i*2) + 2; }
int MaxHeap::max_child(int i)
{
  if( right_child(i) < elements.size() &&
        elements[right_child(i)] > elements[left_child(i)] )
    return right_child(i);
  else
    return left_child(i);
}

bool MaxHeap::is_root_node(int i){ return i == 0; }
bool MaxHeap::is_leaf_node(int i)
{
  return left_child(i) >= elements.size();
}

void MaxHeap::trickle_up(int i)
{
  if( !is_root_node(i) )
  {
    int parent = parent_node(i);
    if( elements[i] > elements[parent] )
    {
        std::swap(elements[i], elements[parent]);
        trickle_up(parent);
    }
  }
}

void MaxHeap::trickle_down(int i)
{
  if( !is_leaf_node(i) )
  {
    int child = max_child(i);
    if( elements[i] < elements[child] )
    {
      std::swap(elements[i], elements[child]);
      trickle_down(child);
    }
  }
}

std::ostream & operator<<(std::ostream &os, MaxHeap& h)
{
  return os << h.to_str();
}
