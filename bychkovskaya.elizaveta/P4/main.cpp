#include <iostream>
#include <cctype>
#include <iomanip>
#include <fstream>

char * create(size_t size) 
{
  char * array = nullptr;
  array = reinterpret_cast< char * >(malloc(sizeof(char) * size));
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
  char * data = create(size + 1);
  if (in >> elem && elem != '\n') {
    data[0] = elem;
  }
  ++size; 
  while (in >> elem && elem != '\n') {
    char * tmp = create(size + 1); 
    for (size_t i = 0; i < size - 1; ++i) {    
      tmp[i] = data[i]; 
    }
    tmp[size - 1] = elem;
    // if (in >> elem && elem != '\0' && elem != '\n')  {   
      free(data);
      data = tmp;
      ++size;
    // }  
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
      if (str1[i] == str2[j]) {
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
  size_t size1 = 0;
  size_t size2 = 0;
  std::cout << "\n" << "Удалить латинкские буквы" << "\n";
  std::cout << "Введите строку" << "\n";
  char * str = getline(std::cin, size);
  char * result = create(size);
  latrmv(str, result);
  std::cout << "\n" << result;
  std::cout << "\n" << "Удалить повторяющиеся в двух строках символы" << "\n";
  std::cout << "\n" << "Введите первую строку" << "\n";
  char * str1 = getline(std::cin, size1);
  std::cout << "\n" << size1 << "\n";
  std::cout << "\n" << "Введите вторую строку" << "\n";
  char * str2 = getline(std::cin, size2);
  std::cout << "\n" << size2 << "\n";
  char * result12 = create(size1);
  excsnd(str1, str2, result12);
  std::cout << "\n";
  std::cout << result12 << "\n";
  free(str1);
  free(str2);
}