#include<iostream>
#include<iomanip>
#include<cctype>

size_t get_line(std::istream & in, char * data, size_t size) {
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws) {
    in >> std::noskipws;
  }
  size_t i = 0;
  for (; i < size; ++i) {
    in >> data[i];
  }
  data[i] = 0;
  if (is_skipws) {
    in >> std::skipws;
  }
  return i;
}

namespace ivanov {
  struct Line {
    char * content;
    size_t size;
    Line();
    ~Line();
    Line & operator=(const Line l);
    void next(char s);
    void space_cleaner();
    void rmv(size_t id) noexcept;

    size_t get_size() const noexcept;
    void get_line() const noexcept;
    char get(size_t id) const noexcept;

    void del_latinus();

    char * get_letters();
  };
  char * unite_letters(char * letters1, char * letters2);
}

int main() {
  return 0;
}

ivanov::Line::Line(): content(new char[1]), size(1)
{
  content[0] = 0;
}
ivanov::Line::~Line() {
  delete[] content;
}
ivanov::Line &ivanov::Line::operator=(const Line l) {
  char * tmp = new char[l.get_size()];
  for (size_t i = 0; i < l.get_size(); ++i) {
    tmp[i] = l.get(i);
  }
  delete[] content;
  content = tmp;
  size = l.get_size();
  return *this;
}

size_t ivanov::Line::get_size() const noexcept {
  return size;
}
char ivanov::Line::get(size_t id) const noexcept {
  return content[id];
}
void ivanov::Line::next(char s) {
  char * tmp = new char[get_size() + 1];
  for (size_t i = 0; i < get_size() - 1; ++i) {
    tmp[i] = get(i);
  }
  tmp[get_size() - 1] = s;
  tmp[get_size()] = 0;
  delete[] content;
  content = tmp;
  size++;
}
void ivanov::Line::rmv(size_t id) noexcept {
  char * tmp = new char[get_size() - 1];
  for (size_t i = 0; i < id; ++i) {
    tmp[i] = get(i);
  }
  for (size_t i = id + 1; i < get_size(); ++i) {
    tmp[i - 1] = get(i);
  }
  delete[] content;
  content = tmp;
  size--;
}
void ivanov::Line::get_line() const noexcept {
  for (size_t i = 0; i < get_size(); ++i) {
    std::cout << get(i) << " ";
  }
  std::cout << "\n";
}

void ivanov::Line::space_cleaner() {
  bool flag = false;
  for (size_t i = 0; i < get_size(); ++i) {
    if (!flag && get(i) != ' ') {
      flag = true;
    }
    if (!flag) {
      rmv(i);
    }
    if (get(i) == ' ' && flag) {
      flag = false;
    }
  }
}
void ivanov::Line::del_latinus() {
  for (size_t i = 0; i < get_size(); ++i) {
    if (isalpha(get(i))) {
      rmv(i);
    }
  }
}


