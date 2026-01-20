#include "mon_dec.hpp"
#include <limits>
#include <algorithm>

pozdeev::MonotoneDecreasing::MonotoneDecreasing():
  m_maxLength(0),
  m_currentLength(0),
  m_lastValue(std::numeric_limits< int >::min())
{}

void pozdeev::MonotoneDecreasing::operator()(int number)
{
  if (number <= m_lastValue) {
    m_currentLength++;
  } else {
    m_currentLength = 1;
  }
  if (m_currentLength > m_maxLength) {
    m_maxLength = m_currentLength;
  }
  m_lastValue = number;
}

size_t pozdeev::MonotoneDecreasing::operator()() const
{
  return m_maxLength;
}
