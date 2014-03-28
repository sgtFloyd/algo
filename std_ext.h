#ifndef STD_EXT_H
#define STD_EXT_H

#include <iostream>
#include <vector>

template<typename T> std::ostream& operator<<(std::ostream &os, std::vector<T> &v)
{
  os << "[";
  for(int i=0; i<v.size(); i++)
  {
    if(i != 0) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

#endif
