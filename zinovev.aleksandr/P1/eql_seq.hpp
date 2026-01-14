#ifndef EQL_SEQ_HPP
#define EQL_SEQ_HPP

#include <cstddef>
#include "sequence_analyzer.hpp"

namespace zinovev
{
  class EQL_SEQ: public SequenceAnalyzer
  {
  public:
    EQL_SEQ() = default;

  private:
    void doOutput() const override;
    void doProcess(int x) override;

    int max_ = 0;
    size_t eql_seq_ = 0;
  };
}

#endif
