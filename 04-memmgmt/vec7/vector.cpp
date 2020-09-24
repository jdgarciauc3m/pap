#include "vector.h"
#include <algorithm> // std::copy

vector::vector(int n) :
  tam{(n>0)?static_cast<unsigned long>(n):0},
  total{tam},
  vec{new double[n]{}} // Inicia todos a 0.0
{
}

vector::vector(std::initializer_list<double> l) :
  tam{l.size()},
  total{tam},
  vec{new double[l.size()]} // No inicia
{
  std::copy(l.begin(), l.end(), vec.get());
}

vector::vector(const vector & v) :
  tam{v.tam},
  total{v.tam},
  vec{new double[v.tam]}
{
  std::copy(v.vec.get(), v.vec.get() + v.tam, vec.get());
}

vector & vector::operator=(const vector & v) {
  std::unique_ptr<double[]> aux{new double[v.tam]};
  std::copy(v.vec.get(), v.vec.get() + v.tam, aux.get());
  std::swap(vec,aux);
  tam = v.tam;
  total = tam;
  return *this;
}

void vector::reserva(int n) {
  if (n>0 && static_cast<unsigned long>(n)>total) {
    std::unique_ptr<double[]> aux{new double[n]};
    std::copy(vec.get(), vec.get() + tam, aux.get());
    std::swap(vec,aux);
    total = n;
  }
}

void vector::redimensiona(int n) {
  reserva(n);
  std::fill_n(vec.get() + tam, n-tam, 0.0);
  tam = n;
}

void vector::agrega_final(double x) {
  constexpr int tam_inicial {8};
  constexpr double factor {1.8}; // o 2.0

  if (total == 0) { // Está vacío
    reserva(tam_inicial);
  }
  else if (tam == total) { // Está lleno
    reserva(factor * total);
  }
  vec[tam++] = x;
}

std::ostream & operator<<(std::ostream & fs, const vector & v) {
  for (unsigned long i=0; i<v.tamanyo(); ++i) {
    fs << v[i] << ' ';
  }
  return fs;
}

std::istream & operator>>(std::istream & fe, vector & v) {
  unsigned long i=0;
  while ((i<v.tamanyo()) && (fe >> v[i++])) { }
  return fe;
}

