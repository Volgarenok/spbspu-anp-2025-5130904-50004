#include <iostream>
#include <cctype>
#include <iomanip>

char * create(size_t size) 
{
  char * array = nullptr;
  array = reinterpret_cast< char * >(malloc(sizeof(char) * size));
  return array;
}

char * getline(std::istream & in, size_t & size)
{
  size = 1; 
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws) {
    in >> std::noskipws;
  }
  char * data = create(size + 1);
  in >> data[0];
  ++size; 
  while (in) {
    char * tmp = create(size + 1); 
    for (size_t i = 0; i < size - 1; ++i) {    
      tmp[i] = data[i]; 
    }
    in >> tmp[size - 1];
    if (in)  {   
      free(data);
      data = tmp;
      ++size;
    }  
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

// excsnd(const char * str1, const char * str2,) 
// {

// }

int main()
{
  size_t size = 0;
  char * data = getline(std::cin, size);
  std::cout << "\n";
  std::cout << size << "\n";
  std::cout << data << "\n";
  free(data);
}