#include<iostream>
#include<iomanip>
#include<cctype>

namespace ivanov {
  struct Line {
    char * content;
    size_t size;
    Line();
    Line(const Line &l);
    ~Line();
    Line & operator=(const Line l);
    Line & operator+(const Line l);
    void next(char s);
    void space_cleaner() noexcept;
    void rmv(size_t id) noexcept;

    size_t get_size() const noexcept;
    void get_line() const noexcept;
    char get(size_t id) const noexcept;
    bool find(char x) const noexcept;

    void del_latinus() noexcept;

    Line get_letters() const;
  };
}

void get_line(std::istream & in, ivanov::Line & data) {
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws) {
    in >> std::noskipws;
  }
  char tmp;
  in >> tmp;
  while (tmp != '\n') {
    data.next(tmp);
    in >> tmp;
  }
  if (is_skipws) {
    in >> std::skipws;
  }
}

int main() {
  using ivanov::Line;
  Line l = Line();
  get_line(std::cin, l);
  l.space_cleaner();
  l.get_line();
  return 0;
}

ivanov::Line::Line(const Line &l): content(new char[l.get_size()]), size(l.get_size())
{
  for (size_t i = 0; i < l.get_size(); ++i) {
    content[i] = l.get(i);
  }
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
ivanov::Line &ivanov::Line::operator+(const Line l) {
  char * tmp = new char[get_size() + l.get_size() - 1];
  for (size_t i = 0; i < get_size() - 1; ++i) {
    tmp[i] = get(i);
  }
  for (size_t i = get_size() - 1; i < get_size() + l.get_size() - 1; ++i) {
    tmp[i] = l.get(i - get_size() + 1);
  }
  delete[] content;
  content = tmp;
  size += l.get_size();
  return *this;
}

size_t ivanov::Line::get_size() const noexcept {
  return size;
}
char ivanov::Line::get(size_t id) const noexcept {
  return content[id];
}
bool ivanov::Line::find(char x) const noexcept {
  for (size_t i = 0; i < get_size(); ++i) {
    if (get(i) == x) {
      return true;
    }
  }
  return false;
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
    std::cout << tmp[i];
  }
  for (size_t i = id + 1; i < get_size(); ++i) {
    tmp[i - 1] = get(i);
    std::cout << tmp[i - 1];
  }
  delete[] content;
  content = tmp;
  size--;
}
void ivanov::Line::get_line() const noexcept {
  for (size_t i = 0; i < get_size(); ++i) {
    std::cout << get(i);
  }
  std::cout << "\n";
}

void ivanov::Line::space_cleaner() noexcept{
  bool flag = false;
  Line tmp = Line();
  for (size_t i = 0; i < get_size(); ++i) {
    if (get(i) == ' ' && flag) {
      flag = false;
      tmp.next(get(i));
    }
    if (flag) {
      tmp.next(get(i));
    }
    if (!flag && get(i) != ' ') {
      flag = true;
      tmp.next(get(i));
    }
  }
  *this = tmp;
}
void ivanov::Line::del_latinus() noexcept {
  for (size_t i = 0; i < get_size(); ++i) {
    if (isalpha(get(i))) {
      std::cout << i << std::endl;
      rmv(i);
    }
  }
}

ivanov::Line ivanov::Line::get_letters() const {
  Line tmp = Line();
  char x = 'A';
  for (size_t c = 0; c < 26; ++c) {
    if (find(x)) {
      tmp.next(x);
    }
  }
  x+=6;
  for (size_t c = 0; c < 26; ++c) {
    if (find(x)) {
      tmp.next(x);
    }
  }
  return tmp;
}

