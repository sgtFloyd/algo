#ifndef STD_EXT_HPP
#define STD_EXT_HPP

#include <iostream>
#include <vector>

template<class T>
std::ostream& operator<<(std::ostream &os, std::vector<T> &v)
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
