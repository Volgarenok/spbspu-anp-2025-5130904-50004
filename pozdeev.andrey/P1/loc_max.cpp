#include "loc_max.hpp"

pozdeev::LocalMax::LocalMax() :
  m_count(0),
  m_left(0),
  m_middle(0),
  m_hasLeft(false),
  m_hasMiddle(false),
  m_processedAny(false)
{}

void pozdeev::LocalMax::operator()(int number)
{
  m_processedAny = true;
  if (!m_hasLeft) {
    m_left = number;
    m_hasLeft = true;
  } else if (!m_hasMiddle) {
    m_middle = number;
    m_hasMiddle = true;
  } else {
    if (m_left < m_middle && m_middle > number) {
      m_count++;
    }
    m_left = m_middle;
    m_middle = number;
  }
}

size_t pozdeev::LocalMax::getResult() const
{
  return m_count;
}

bool pozdeev::LocalMax::hasResult() const
{
  return m_processedAny;
}
