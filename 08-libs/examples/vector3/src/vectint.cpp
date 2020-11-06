#include "vectint.h"
#include <algorithm>
#include <iterator>

namespace dcl {

vectint::vectint(int n) :
  capacity_{n},
  size_{n},
  buffer_{std::make_unique<int[]>(n)}
{}

vectint::vectint(const vectint & v) :
  capacity_{v.capacity_},
  size_{v.size_},
  buffer_{std::make_unique<int[]>(size_)}
{
  std::copy_n(v.buffer_.get(), v.size_, buffer_.get());
}

vectint & vectint::operator=(const vectint & v) {
  buffer_ = std::make_unique<int[]>(v.size_);
  capacity_ = v.capacity_;
  size_ = v.size_;
  std::copy_n(v.buffer_.get(), v.size_, buffer_.get());
  return *this;
}

void vectint::resize(int n) {
  if (n>capacity_) reserve(n);
  if (n>size_) {
    std::fill_n(buffer_.get()+size_, buffer_.get()+n, 0);
  }
  size_ = n;
}

void vectint::reserve(int n) 
{
  if (n <= capacity_) return;
  auto buf = std::make_unique<int[]>(n);
  std::copy_n(buffer_.get(), size_, buf.get());
  capacity_ = n;
}

std::ostream & operator<<(std::ostream & os, const vectint & v)
{
  std::copy(v.buffer_.get(), v.buffer_.get()+v.size_,
    std::ostream_iterator<int>{os, " "});
  return os;
}

} // Namespace
