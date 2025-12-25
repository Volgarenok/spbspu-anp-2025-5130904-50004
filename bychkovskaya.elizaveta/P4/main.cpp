#include <iostream>
#include <cctype>
#include <iomanip>
#include <fstream>

char * create(size_t size) 
{
  char * array = reinterpret_cast< char * >(malloc(sizeof(char) * size));
  return array;
}

char * getline(std::istream & in, size_t & size)
{
  char elem = '\0';
  size = 1; 
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws) {
    in >> std::noskipws;
  }
  char * data = create(1);
  if (data == nullptr) {
    throw std::runtime_error("Not enough memory");
  }
  while (in >> elem && elem != '\n') {
    char * tmp = create(size + 1); 
    if (tmp == nullptr) {
      free(data);
      throw std::runtime_error("Not enough memory");
    }
    for (size_t i = 0; i < size - 1; ++i) {    
      tmp[i] = data[i]; 
    }
    tmp[size - 1] = elem;  
    free(data);
    data = tmp;
    ++size;
  }
  if (in.eof() || in.bad()) {
    free(data);
    throw std::invalid_argument("Input failed");
  }
  data[size-1] = '\0';  
  if (is_skipws) {
    in >> std::skipws;
  }
  return data;
}

void latrmv(const char * str, char * result)
{
  size_t k = 0;
  for (size_t i = 0; str[i] != '\0'; ++i) {
    if (!std::isalpha(str[i])) {
      result[k] = str[i];
      ++k;
    }
  }
result[k] = '\0';
}


void excsnd(const char * str1, const char * str2, char * result) 
{
  size_t countRepeat = 0;
  size_t k = 0;
  for (size_t i = 0; str1[i] != '\0'; ++i) {
    countRepeat = 0;
    for (size_t j = 0; str2[j] != '\0'; ++j) {
      if (str1[i] == str2[j] && str1[i] != ' ') {
        ++countRepeat;
      }
    }
    if (countRepeat == 0) {
      result[k] = str1[i];
      ++k;
    }
  }
  result[k] = '\0';
}

int main()
{
  size_t size = 0;
  char * str = nullptr;
  const char * str2 = "abc";
  try {
    str = getline(std::cin, size);
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
  char * result = create(size);
  if (result == nullptr) {
    std::cerr << "Not enough memory" << "\n";
    free(str);
    return 1;
  }
  latrmv(str, result);
  std::cout << result << "\n"; 
  free(result);
  char * result2 = create(size);
  if (result2 == nullptr) {
    std::cerr << "Not enough memory";
    free(str);
    return 1;
  }
  excsnd(str, str2, result2);
  std::cout << result2 << "\n";
  free(str);
  free(result2);
}