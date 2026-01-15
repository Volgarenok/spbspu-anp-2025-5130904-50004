#ifndef INT_ARRAY_H
#define INT_ARRAY_H
#include <cstddef>

namespace alekseev {
  struct Int_array {
    Int_array();
    Int_array(const Int_array & rhs);
    Int_array & operator=(const Int_array & rhs);
    Int_array(Int_array && rhs) noexcept;
    Int_array & operator=(Int_array && rhs) noexcept;

    Int_array(size_t s);

    ~Int_array();

    void add(int a) noexcept;
    int get(size_t id) const;
    size_t number() const noexcept;
    size_t size() const noexcept;

    private:
      int * data_;
      size_t counter_;
      size_t size_;
  };
}
#endif
