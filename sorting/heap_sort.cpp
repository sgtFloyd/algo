#include <vector>
#include "../data_structures/min_heap.h"

class HeapSort
{
public:
  static std::vector<int> sort(std::vector<int> elements)
  {
    MinHeap heap;
    for(int i=0; i<elements.size(); i++)
    {
      heap.insert(elements[i]);
    }

    std::vector<int> sorted;
    for(int i=0; i<heap.size(); i++)
    {
      sorted.push_back(heap.pop());
    }
    return sorted;
  };
};
