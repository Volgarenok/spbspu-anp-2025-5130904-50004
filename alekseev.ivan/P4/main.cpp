#include <iostream>
#include <cstddef>
#include <iomanip>
#include "string_actions.h"


namespace alekseev {
  char * get_line(std::istream & inp, size_t & size);
  char * resize_alloc(const char * old_str, size_t old_size, size_t new_size);
}


int main()
{
  char * user_string = nullptr;
  size_t length = 0;
  user_string = alekseev::get_line(std::cin, length);
  if (user_string == nullptr) {
    if (!std::cin) {
      std::cerr << "std::cin failed" << "\n";
    } else {
      std::cerr << "Memory allocation error!" << "\n";
    }
    return 1;
  }


  char * excluded_second = reinterpret_cast< char * >(malloc(sizeof(char) * (length + 1)));
  if (!excluded_second) {
    std::cerr << "Memory allocation error!" << "\n";
    free(user_string);
    return 1;
  }
  const char * second = "abc";
  size_t length_result = 0;
  alekseev::exc_scd(user_string, second, excluded_second, &length_result);
  std::cout << excluded_second << "\n";
  free(excluded_second);

  char * removed_latin_letters = reinterpret_cast< char * >(malloc(sizeof(char) * (length + 1)));
  if (!removed_latin_letters) {
    std::cerr << "Memory allocation error!" << "\n";
    free(user_string);
    return 1;
  }
  alekseev::lat_rmv(user_string, removed_latin_letters, &length_result);
  std::cout << removed_latin_letters << "\n";
  free(removed_latin_letters);

  free(user_string);
}


char * alekseev::get_line(std::istream & inp, size_t & size)
{
  size_t capacity = 10;
  char * result = reinterpret_cast< char * >(malloc(sizeof(char) * capacity));
  if (!result) {
    return nullptr;
  }

  bool is_skipws = inp.flags() & std::ios_base::skipws;
  if (is_skipws) {
    inp >> std::noskipws;
  }

  char current_char = ' ';
  size = 0;
  inp >> current_char;
  while (current_char != '\n' && inp) {
    if (++size == capacity - 1) {
      char * temp = resize_alloc(result, capacity, capacity + 10);
      free(result);
      if (!temp) {
        return nullptr;
      }
      capacity += 10;
      result = temp;
    }
    result[size - 1] = current_char;
    inp >> current_char;
  }
  if (!size || !inp) {
    free(result);
    return nullptr;
  }
  char * temp = resize_alloc(result, capacity, size + 1);
  free(result);
  if (!temp) {
    return nullptr;
  }
  result = temp;
  result[size] = '\0';

  if (is_skipws) {
    inp >> std::skipws;
  }
  return result;
}


char * alekseev::resize_alloc(const char * old_str, size_t old_size, size_t new_size)
{
  char * result = reinterpret_cast< char * >(malloc(sizeof(char) * new_size));
  if (result) {
    const size_t size = old_size < new_size ? old_size : new_size;
    for (size_t i = 0; i < size; ++i) {
      result[i] = old_str[i];
    }
  }
  return result;
}
