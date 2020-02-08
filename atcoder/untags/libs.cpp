#include <iostream> 
#include "libs.h"

void load_array_int(int* array, int size) {
  for (int i = 0; i < size; i++) std::cin >> array[i];
}

template<typename T>
void print(T const &input) {
  copy(input.cbegin(), input.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
}
