#ifndef EQLSEQ_HPP
#define EQLSEQ_HPP

namespace kuchukbaeva
{
  struct EqlSeq {
    EqlSeq();
    void operator()(int v);
    size_t res() const;
    bool has() const;
  private:
    size_t max_, cur_, cnt_;
    int last_;
  };
}

#endif

