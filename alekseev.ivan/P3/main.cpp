#include <iostream>

int main(int argc, char ** argv)
{
  for (char ** i = argv; i < argv + argc; ++i) {
    std::cout << *i << "\n";
  }
}
