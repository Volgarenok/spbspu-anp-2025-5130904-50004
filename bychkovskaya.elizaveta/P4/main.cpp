#include <iostream>
#include <cctype>
#include <iomanip>

char * create(size_t size) 
{
  char * array = nullptr;
  array = reinterpret_cast< char * >(malloc(sizeof(char) * size));
  return array;
}

char * getline(std::istream & in)
{
  size_t count = 1;
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws) {
    in >> std::noskipws;
  }
  char * data = create(count + 1);
  in >> data[0];
  ++count;
  while (!in.eof() && !in.bad()) {
    char * tmp = create(count + 1);
    for (size_t i = 0; i < count - 1; ++i) {
      tmp[i] = data[i];
    }
    in >> tmp[count - 1];
    free(data);
    data = tmp;
    ++count;
  }
  data[count-2] = '\0';
  if (is_skipws) {
    in >> std::skipws;
  }
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