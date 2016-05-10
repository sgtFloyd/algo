#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T>
class DynamicArray {
protected:
  int size = 10;
  T* ptr = new T[size];

public:
  explicit DynamicArray(){};

  T& operator[](int index) {
    if( index >= size ) {
      resize();
      return (*this)[index];
    }
    else
      return *(ptr + index);
  }

protected:
  friend std::ostream&
  operator<<(std::ostream &os, DynamicArray &a) {
    os << "[";
    for(int i=0; i<a.size; i++) {
      if(i != 0) os << ", ";
      os << a[i];
    }
    os << "]";
    return os;
  };

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
