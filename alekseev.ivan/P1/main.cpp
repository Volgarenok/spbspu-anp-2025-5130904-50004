#include <iostream>
#include "Property.h"
#include "Counter.h"
#include "Pth_trp.h"
#include "Sum_dup.h"


namespace alekseev {
  Property * make(int n);
  Property ** make_multiple(size_t k);
  void delete_multiple(size_t k, Property ** massive);
}


int main()
{
  constexpr size_t NUM_OF_PROPS = 3;
  alekseev::Property ** properties = alekseev::make_multiple(NUM_OF_PROPS);
  int a = 0;
  std::cin >> a;
  while (a && std::cin) {
    for (size_t i = 0; i < NUM_OF_PROPS; ++i) {
      (*properties[i])(a);
    }
    std::cin >> a;
  }
  if (!std::cin) {
    std::cout << "Not a sequence of numbers" << "\n";
    alekseev::delete_multiple(NUM_OF_PROPS, properties);
    return 1;
  }

  bool flag = true;
  for (size_t i = 1; i < NUM_OF_PROPS; i++) {
    if (properties[i]->countered()) {
      std::cout << properties[i]->name() << ": " << (*properties[i])() << "\n";
    } else {
      std::cout << "Cannot counter " << properties[i]->name() << "\n";
      flag = false;
    }
  }
  delete_multiple(NUM_OF_PROPS, properties);
  if (!flag) {
    return 2;
  }
}


alekseev::Property * alekseev::make(int n)
{
  if (n == 0) {
    return new Counter();
  }
  if (n == 1) {
    return new Pth_trp();
  }
  if (n == 2) {
    return new Sum_dup();
  }
  return nullptr;
}


alekseev::Property ** alekseev::make_multiple(size_t k)
{
  Property ** result = new Property *[k];
  for (size_t i = 0; i < k; ++i) {
    try {
      result[i] = make(i);
    } catch (...) {
      delete_multiple(i, result);
      throw;
    }
  }
  return result;
}


void alekseev::delete_multiple(size_t k, Property ** massive)
{
  for (size_t i = 0; i < k; ++i) {
    delete massive[i];
  }
  delete[] massive;
}
