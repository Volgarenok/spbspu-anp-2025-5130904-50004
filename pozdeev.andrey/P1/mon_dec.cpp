#include "mon_dec.hpp"

pozdeev::MonotoneDecreasing::MonotoneDecreasing() :
  m_maxLength(0),
  m_currentLength(0),
  m_lastValue(0),
  m_isFirst(true)
{}

void pozdeev::MonotoneDecreasing::operator()(int number)
{
  if (m_isFirst) {
    m_currentLength = 1;
    m_maxLength = 1;
    m_lastValue = number;
    m_isFirst = false;
  } else {
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
}

size_t pozdeev::MonotoneDecreasing::getResult() const
{
  return m_maxLength;
}
