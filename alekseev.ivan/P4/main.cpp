#include <iostream>
#include <cstddef>
#include <iomanip>
#include "string_actions.h"


namespace alekseev {
  char * str_inp(std::istream & inp, size_t & length);
  char * resize_alloc(char * old_str, size_t old_size, size_t new_size);
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
  std::cout << user_string << "\n" << length << "\n";
  char * excluded_second = reinterpret_cast<char *>(malloc(sizeof(char) * (length + 1)));
  if (!excluded_second) {
    std::cerr << "Memory allocation error!" << "\n";
    free(user_string);
    return 1;
  }
  const char * second = "abc";
  alekseev::exc_scd(user_string, length, second, 3, excluded_second);
  free(excluded_second);
  std::cout << excluded_second << "\n";

  // char * removed_latin_letters = reinterpret_cast<char *>(malloc(sizeof(char) * (length + 1)));
  // if (!removed_latin_letters) {
  //   std::cerr << "Memory allocation error!" << "\n";
  //   free(user_string);
  //   return 1;
  // }
  // alekseev::lat_rmv(user_string, length, removed_latin_letters);
  // std::cout << removed_latin_letters << "\n";
}


char * alekseev::str_inp(std::istream & inp, size_t & length)
{
  size_t size = 10;
  char * result = reinterpret_cast<char *>(malloc(sizeof(char) * size));
  if (!result) {
    throw std::bad_alloc();
  }

  bool is_skipws = inp.flags() & std::ios_base::skipws;
  if (is_skipws) {
    inp >> std::noskipws;
  }

  char current_char = ' ';
  length = 0;
  inp >> current_char;
  while (current_char != '\n' && inp) {
    result[length++] = current_char;
    if (length == size - 1) {
      char * temp = resize_alloc(result, size, size + 10);
      if (!temp) {
        free(result);
        throw std::bad_alloc();
      }
      result = temp;
    }
    inp >> current_char;
  }
  char * temp = resize_alloc(result, size, length);
  if (!temp) {
    free(result);
    throw std::bad_alloc();
  }
  result = temp;
  result[length] = '\0';

  if (is_skipws) {
    inp >> std::skipws;
  }

  return result;
}


char * alekseev::resize_alloc(char * old_str, size_t old_size, size_t new_size)
{
  char * result = reinterpret_cast<char *>(malloc(sizeof(char) * new_size));
  if (result) {
    const size_t size = old_size < new_size ? old_size : new_size;
    for (size_t i = 0; i < size; i++) {
      result[i] = old_str[i];
    }
    free(old_str);
  }
  return result;
}
