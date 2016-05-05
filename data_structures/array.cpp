#include "array.h"

template <class T>
T& Array<T>::operator[](int index)
{
  if( index >= size )
  {
    resize();
    return (*this)[index];
  }
  else
    return *(ptr + index);
}

template <class T>
void Array<T>::resize()
{
  int new_size = size * 1.5;
  T* new_ptr = new T[new_size];
  for(int i=0; i<size; i++)
  {
    *(new_ptr + i) = *(ptr + i);
  }
  ptr = new_ptr;
  size = new_size;
}
