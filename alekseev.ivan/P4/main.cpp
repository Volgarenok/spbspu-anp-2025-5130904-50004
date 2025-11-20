#include <iostream>
#include <cstddef>
#include <iomanip>
#include "string_actions.h"


namespace alekseev {
  char * str_inp(std::istream & inp, size_t & length);
}

int main()
{
  char * user_string = nullptr;
  size_t length = 0;
  try {
    user_string = alekseev::str_inp(std::cin, length);
  } catch (std::bad_alloc & e) {
    std::cerr << "Memory allocation error!" << "\n";
    return 1;
  }
  char * excluded_second = reinterpret_cast<char *>(malloc(sizeof(char) * (length + 1)));
  char* removed_latin_letters = reinterpret_cast<char *>(malloc(sizeof(char) * (length + 1)));
  if (!excluded_second) {
    std::cerr << "Memory allocation error!" << "\n";
    free(user_string);
    return 1;
  }
  if (!removed_latin_letters) {
    std::cerr << "Memory allocation error!" << "\n";
    free(user_string);
    free(excluded_second);
    return 1;
  }
  const char * second = "abc";
  alekseev::exc_scd(user_string, length, second, 3, excluded_second);
  std::cout << excluded_second << "\n";
  // alekseev::lat_rmv(user_string, length, removed_latin_letters);
  // std::cout << removed_latin_letters << "\n";
}
