#ifndef DYN_ARRAY
#define DYN_ARRAY
#include <cassert>

template <typename T> class dynamic_array {
private:
  int size{ 0 };
  int max_size{ 5 };
  T* array_holder { new T[max_size] };
public:
  ~dynamic_array() { delete[] array_holder; };
  T& operator[](int index);
  void add(T data);
  int get_size() { return size; };
};

template <typename T> T& dynamic_array<T>::operator[](int index) {
  assert(index < size);
  return array_holder[index];
}

template <typename T> void dynamic_array<T>::add(T data) {
  if (max_size < size + 1) {
    max_size *= 2;
    T* temp { new T[max_size] };
    for (int i = 0; i < size; i++)
      temp[i] = array_holder[i];
    delete[] array_holder;
    array_holder = temp;
  } 
  array_holder[size] = data;
  size++;
}

#endif
