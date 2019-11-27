#include <iostream> 
#include "libs.h"

void load_array_int(int* array, int size) {
  for (int i = 0; i < size; i++) std::cin >> array[i];
}

