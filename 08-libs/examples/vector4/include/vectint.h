#ifndef DCL_VECTINT_H
#define DCL_VECTINT_H

#include <memory>

namespace dcl { // Dummy Container Library

class vectint {
public:
  vectint() : capacity_{0}, size_{0}, buffer_{nullptr} {}
  vectint(int n);

  vectint(const vectint & v);
  vectint & operator=(const vectint & v);

  int & operator[](int i) { return buffer_[i]; }
  int operator[](int i) const { return buffer_[i]; }

  int capacity() const { return capacity_; }
  int size() const { return size_; }

  void reserve(int n);
  void resize(int n);

  friend std::ostream & operator<<(std::ostream & os, const vectint & v);

private:
  int capacity_;
  int size_;
  std::unique_ptr<int[]> buffer_;
};

} // end dcl namespace

#endif
