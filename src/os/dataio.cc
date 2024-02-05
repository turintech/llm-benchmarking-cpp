#include "dataio.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

std::string
OsDataIo::CatFile() {
  std::ifstream file;
  file.open("data\\hello.txt");

  if (!file.is_open()) {
    std::cerr << "Failed to open file" << std::endl;
  }

  std::stringstream buffer;
  buffer << file.rdbuf();

  file.close();
  return buffer.str();
}

void
OsDataIo::CastIntToLongArray(const int *inputArray, long *outputArray, size_t length) {
  size_t intSize = length * 4;
  std::memcpy(outputArray, inputArray, intSize);
}
