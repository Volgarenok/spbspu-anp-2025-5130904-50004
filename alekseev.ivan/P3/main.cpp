#include <iostream>
#include <fstream>

namespace alekseev {
  bool check_cl_args(int argc, char *argv[]);
}

int main(int argc, char ** argv)
{
  try {
    alekseev::check_cl_args(argc, argv);
  } catch (const std::exception & e) {
    std::cerr << e.what() << "\n";
    return 1;
  }

  char num = argv[1][0];
  std::cout << num << "\n";

}


bool alekseev::check_cl_args(int argc, char * argv[])
{
  if (argc < 4) {
    throw std::invalid_argument("Not enough arguments");
  } else if (argc > 4) {
    throw std::invalid_argument("Too many arguments");
  }
  for (char * i = argv[1]; *i != '\0'; ++i) {
    if (*i < '0' or *i > '9') {
      throw std::invalid_argument("First parameter is not a number");
    }
  }
  char num = argv[1][0];
  if (!(num == '1' || num == '2')) {
    throw std::invalid_argument("First parameter is out of range");
  }
  return true;
}
