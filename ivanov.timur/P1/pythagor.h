#ifndef PYTHAGOR_H
#define PYTHAGOR_H
struct Pythagor {
  Pythagor(int a0, int b0, int c0);

  void next(int e);
  bool operator()() const;

private:
  int a;
  int b;
  int c;
};
#endif
