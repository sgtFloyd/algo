#include "heap.h"
#include <iostream>

Heap::Heap(){} // constructor

void Heap::insert(int element)
{
  elements.push_back(element);
  trickle_up(elements.size()-1);
}

int Heap::peek()
{
  return elements.front();
}

int Heap::pop()
{
  int root = peek();
  elements[0] = elements.back();
  elements.pop_back();
  trickle_down(0);
  return root;
}

void Heap::print_elements()
{
  std::cout << "[ ";
  for(int i=0; i<elements.size(); i++)
  {
    std::cout << elements[i] << " ";
  }
  std::cout << "]" << std::endl;
}


int Heap::parent_node(int i){ return (i-1) / 2; }
int Heap::left_child(int i){ return (i*2) + 1; }
int Heap::right_child(int i){ return (i*2) + 2; }
int Heap::max_child(int i)
{
  if( right_child(i) <= elements.size() )
  {
    if( elements[right_child(i)] > elements[left_child(i)] )
    {
      return right_child(i);
    }
    else
    {
      return left_child(i);
    }
  }
  else
  {
    return left_child(i);
  }
}

bool Heap::is_root_node(int i){ return i == 0; }
bool Heap::is_leaf_node(int i)
{
  return left_child(i) >= elements.size();
}

void Heap::swap(int i, int j)
{
  int temp = elements[i];
  elements[i] = elements[j];
  elements[j] = temp;
}

void Heap::trickle_up(int i)
{
  if( !is_root_node(i) )
  {
    int parent = parent_node(i);
    if(elements[i] > elements[parent])
    {
        swap(i, parent);
        trickle_up(parent);
    }
  }
}

void Heap::trickle_down(int i)
{
  if( !is_leaf_node(i) )
  {
    int child = max_child(i);
    if( elements[i] < elements[child] )
    {
      swap(i, child);
      trickle_down(child);
    }
  }
}
