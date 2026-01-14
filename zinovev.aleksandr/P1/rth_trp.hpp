#ifndef RTH_TRP_HPP
#define RTH_TRP_HPP

#include <cstddef>
#include <stdexcept>
#include "sequence_analyzer.hpp"

namespace zinovev
{
  class RTH_TRP: public SequenceAnalyzer
  {
  public:
    RTH_TRP() = default;

  private:
    void doOutput() const override;
    void doProcess(int x) override;

    int a_ = 0, b_ = 0, c_ = 0;
    size_t pth_trp_ = 0;
  };
}

#endif
