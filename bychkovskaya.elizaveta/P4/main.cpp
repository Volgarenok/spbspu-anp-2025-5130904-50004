#include <iostream>
#include <cctype>

char * create(size_t size) 
{
  char * array = nullptr;
  array = reinterpret_cast< char * >(malloc(sizeof(char) * size));
  return array;
}

char * getline(std::istream & in, size_t & size)
{
  char * data = create(size + 1);
  std::cin >> data[0];
  ++size;
  while (!in.eof() || !in.bad()) {
    char * tmp = create(size + 1);
    for (size_t i = 0; i < size - 1; ++i) {
      tmp[i] = data[i];
    }
    in >> tmp[size - 1];
    free(data);
    data = tmp;
    ++size;
  }
  data[size-2] = '\0';
  return data;
}

// latrmv()
// {

// }

// excsnd() 
// {

// }

int main()
{
  // size_t size = 1;
}