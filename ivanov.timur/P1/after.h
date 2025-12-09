#ifndef AFTER_H
#define AFTER_H
struct After {
  After(int e0);

  void next(int e1);
  size_t operator()() const;

private:
  int elem;
  size_t count = 0;
};
#endif
