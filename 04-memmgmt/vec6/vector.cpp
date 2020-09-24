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
  std::copy(l.begin(), l.end(), vec.get());
}

vector::vector(const vector & v) :
  tam{v.tam},
  vec{new double[v.tam]}
{
  std::copy(v.vec.get(), v.vec.get() + v.tam, vec.get());
}

vector & vector::operator=(const vector & v) {
  std::unique_ptr<double[]> aux{new double[v.tam]};
  std::copy(v.vec.get(), v.vec.get() + v.tam, aux.get());
  std::swap(vec,aux);
  tam = v.tam;
  return *this;
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

