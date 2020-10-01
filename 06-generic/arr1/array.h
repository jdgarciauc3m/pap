#ifndef ARRAY_H
#define ARRAY_H

namespace bcd {

template <typename T, int N>
struct array {
  T vec[N];

  T & operator[](int i) { return vec[i]; }
  const T & operator[](int i) const { return vec[i]; }

  int tamanyo() const { return N; }
};

}

#endif
