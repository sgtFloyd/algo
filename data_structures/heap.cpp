#include "heap.h"

Heap::Heap(){} // constructor

void Heap::insert(int element)
{
  elements.push_back(element);
}

int Heap::peek() const
{
  return elements.front();
}

int Heap::pop()
{
  int root = peek();
  elements.erase(elements.begin());
  return root;
}

std::string Heap::to_str() const
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

int Heap::parent_node(int i){ return (i-1) / 2; }
int Heap::left_child(int i){ return (i*2) + 1; }
int Heap::right_child(int i){ return (i*2) + 2; }

bool Heap::is_root_node(int i){ return i == 0; }
bool Heap::is_leaf_node(int i)
{
  return left_child(i) >= elements.size();
}

std::ostream & operator<<(std::ostream &os, Heap& h)
{
  return os << h.to_str();
}
