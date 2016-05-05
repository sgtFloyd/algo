#ifndef ARRAY_H
#define ARRAY_H

template <class T> class Array
{
public:
  explicit Array(){};
  T& operator[](int i);

protected:
  int size = 10;

private:
  T* ptr = new T[size];
  void resize();
};

#endif
