#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <iostream>

namespace pozdeev {

  char * removeExtraSpaces(char * destination, const char * source);

  char * removeLatin(char * destination, const char * source);

  bool checkStream(std::istream & stream);

}

#endif
