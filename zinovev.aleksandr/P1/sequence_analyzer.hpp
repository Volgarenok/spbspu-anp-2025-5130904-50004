#ifndef SEQUENCE_ANALYZER_HPP
#define SEQUENCE_ANALYZER_HPP

namespace zinovev
{
  class SequenceAnalyzer
  {
  public:
    void operator()() const;
    void operator()(int x);
    virtual ~SequenceAnalyzer() = default;

  protected:
    SequenceAnalyzer() = default;
    SequenceAnalyzer(const SequenceAnalyzer&) = default;
    SequenceAnalyzer(SequenceAnalyzer&&) = default;
    SequenceAnalyzer& operator=(const SequenceAnalyzer&) = default;
    SequenceAnalyzer& operator=(SequenceAnalyzer&&) = default;

  private:
    virtual void doOutput() const = 0;
    virtual void doProcess(int x) = 0;
  };
}

#endif
