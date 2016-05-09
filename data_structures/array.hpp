#ifndef ARRAY_H
#define ARRAY_H

template <class T>
class Array {
protected:
  int size = 10;
  T* ptr = new T[size];

public:
  explicit Array(){};

  T& operator[](int index) {
    if( index >= size ) {
      resize();
      return (*this)[index];
    }
    else
      return *(ptr + index);
  }

private:
  void resize() {
    int new_size = size * 1.5;
    T* new_ptr = new T[new_size];
    for(int i=0; i<size; i++) {
      *(new_ptr + i) = *(ptr + i);
    }
    delete[] ptr;
    ptr = new_ptr;
    size = new_size;
  }
};

#endif
