#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T>
class DynamicArray {
protected:
  int capacity = 10;
  T* ptr = new T[capacity]();

public:
  explicit DynamicArray(){};

  T& operator[](int index) {
    if( index >= capacity ) {
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
    for(int i=0; i<a.capacity; i++) {
      if(i != 0) os << ", ";
      os << a[i];
    }
    os << "]";
    return os;
  };

private:
  void resize() {
    int new_capacity = capacity * 1.5;
    T* new_ptr = new T[new_capacity]();
    for(int i=0; i<capacity; i++) {
      *(new_ptr + i) = *(ptr + i);
    }
    delete[] ptr;
    ptr = new_ptr;
    capacity = new_capacity;
  }
};

#endif
