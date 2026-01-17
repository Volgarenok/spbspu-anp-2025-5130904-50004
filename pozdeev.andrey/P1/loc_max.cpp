#include "loc_max.hpp"
#include <stdexcept>

pozdeev::LocalMax::LocalMax():
  m_countResult(0),
  m_elementsCount(0),
  m_left(0),
  m_middle(0)
{}

void pozdeev::LocalMax::operator()(int number)
{
  m_elementsCount++;
  if (m_elementsCount == 1) {
    m_left = number;
  } else if (m_elementsCount == 2) {
    m_middle = number;
  } else {
    if (m_left < m_middle && m_middle > number) {
      m_countResult++;
    }
    m_left = m_middle;
    m_middle = number;
  }
}

size_t pozdeev::LocalMax::operator()() const
{
  if (m_elementsCount == 0) {
    throw std::logic_error("Sequence is empty");
  }
  return m_countResult;
}
