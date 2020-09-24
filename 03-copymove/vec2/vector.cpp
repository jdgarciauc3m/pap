#include "vector.h"
#include <algorithm> // std::copy

vector::vector(int n) :
  tam{(n>0)?static_cast<unsigned long>(n):0},
  vec{new double[n]{}} // Inicia todos a 0.0
{
}

vector::vector(std::initializer_list<double> l) :
  tam{l.size()},
  vec{new double[l.size()]} // No inicia
{
  std::copy(l.begin(), l.end(), vec);
}

std::ostream & operator<<(std::ostream & fs, const vector & v) {
  for (int i=0; i<v.tamanyo(); ++i) {
    fs << v.obten(i) << ' ';
  }
  return fs;
}

std::istream & operator>>(std::istream & fe, vector & v) {
  int i=0;
  double x;
  while ((i<v.tamanyo()) && (fe >> x)) {
    v.pon(i++, x);
  }
  return fe;
}

