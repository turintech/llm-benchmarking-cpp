#include <cstddef>
#include <iostream>

#include "os/dataio.h"
#include "os/winheader.h"

void
_winheader() {
  std::cout << "Windows Header" << std::endl;
  std::cout << "--------------" << std::endl;

  OsWinHeader::ShowMessage("Hello World!");
}

void
_dataio() {
  std::cout << "Data Input / Output" << std::endl;
  std::cout << "-------------------" << std::endl;

  std::string output = OsDataIo::CatFile();
  std::cout << "CAT: " << output << std::endl;

  const size_t SIZE = 4;
  const int intArray[SIZE] = {0, 1, 2, 3};
  long longArray[SIZE] = {0};
  OsDataIo::CastIntToLongArray(intArray, longArray, SIZE);
  std::cout << "Int array casted to long array:" << std::endl;
  for (size_t i = 0; i < SIZE; ++i) {
    std::cout << "longArray[" << i << "] = " << longArray[i] << std::endl;
  }
}

int
main(int argc, char **argv) {
  _winheader();
  _dataio();
  return 0;
}
