#include "Pth_trp.h"


alekseev::Pth_trp::Pth_trp() : Property(), k(0), data(new int[3])
{
}


void alekseev::Pth_trp::update(int a)
{
  data[0] = data[1];
  data[1] = data[2];
  data[2] = a;
  int cat1 = data[0], cat2 = data[1], hyp = data[2];
  if (cat1 > hyp) {
    int t = cat1;
    cat1 = hyp;
    hyp = t;
  }
  if (cat2 > hyp) {
    int t = cat2;
    cat2 = hyp;
    hyp = t;
  }
  k += (cat1 * cat1 + cat2 * cat2 == hyp * hyp);
}


size_t alekseev::Pth_trp::value() const
{
  return k;
}


char * alekseev::Pth_trp::my_name()
{
  return new char[8]{'P', 't', 'h', '_', 't', 'r', 'p', 0};
}
