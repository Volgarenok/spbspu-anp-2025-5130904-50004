#ifndef PROPERTY_H
#define PROPERTY_H
#include <cstddef>

struct Property {
  void operator()(int a);
  size_t operator()() const;
  char * name();

  virtual ~Property();

  private:
    size_t k;
    int * data;

    virtual void update(int a);
    virtual void value();
    virtual char * my_name();
};
#endif