#ifndef __OS_DATAIO_H__
#define __OS_DATAIO_H__

#include <cstddef>
#include <string>
#include <windows.h>

namespace OsDataIo {

std::string CatFile();
void CastIntToLongArray(const int *inputArray, long *outputArray, size_t length);

}   // namespace OsDataIo

#endif   // ! __OS_DATAIO_H__
