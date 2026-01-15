#include "sequence_analyzer.hpp"

void zinovev::SequenceAnalyzer::operator()() const
{
  doOutput();
}

void zinovev::SequenceAnalyzer::operator()(int x)
{
  doProcess(x);
}
