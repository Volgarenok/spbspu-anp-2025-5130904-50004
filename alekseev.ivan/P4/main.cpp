#include <iostream>
#include <cstddef>
#include "string_actions.h"


namespace alekseev {
  char * str_inp(std::istream & inp, size_t & length);
}

int main()
{
  char * user_string = nullptr;
  size_t length = 0;
  char * removed_latin_letters = nullptr;
  char * excluded_second = nullptr;
  try {
    user_string = alekseev::str_inp(std::cin, length);
    removed_latin_letters = reinterpret_cast<char *>(malloc(sizeof(char) * (length + 1)));
    excluded_second = reinterpret_cast<char *>(malloc(sizeof(char) * (length + 1)));
  } catch (std::bad_alloc & e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
  const char * second = "abc";
  alekseev::exc_scd(user_string, length, second, 3, excluded_second);
  std::cout << excluded_second << "\n";
  // alekseev::lat_rmv(user_string, length, removed_latin_letters);
  // std::cout << removed_latin_letters << "\n";
}
