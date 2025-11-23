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

// latrmv()
// {

// }

//взять первую строку и каждый ее символ сравнить с каждым символом второй строки (два фора)
//в новый массив длина которого равна длине первой строки записать те символы который не встречаются во второй строке

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
}

int main()
{
  size_t size1 = 0;
  size_t size2 = 0;
  std::cout << "\n" << "Введите первую строку" << "\n";
  char * str1 = getline(std::cin, size1);
  std::cout << "\n" << size1 << "\n";
  std::cout << "\n" << "Введите вторую строку" << "\n";
  char * str2 = getline(std::cin, size2);
  std::cout << "\n" << size2 << "\n";
  char * result = create(size1);
  excsnd(str1, str2, result);
  std::cout << "\n";
  std::cout << result << "\n";
  free(str1);
  free(str2);
}