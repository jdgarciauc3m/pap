#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm> // std::copy
#include <memory>

namespace bcd { // Biblioteca de Contenedores para Docencia

template <typename T>
class vector {
public:
  vector() : tam{0}, total{0}, vec{nullptr} {}
  explicit vector(int n);
  vector(std::initializer_list<T> l);

  vector(const vector &);
  vector & operator=(const vector &);

  vector(vector &&) = default;
  vector & operator=(vector &&) = default;

  T operator[](int i) const { return vec[i]; }
  T & operator[](int i) { return vec[i]; }

  unsigned long tamanyo() const { return tam; }
  unsigned long capacidad() const { return total; }

  void reserva(int n);
  void redimensiona(int n);
  void agrega_final(const T & x);

private:
  unsigned long tam;
  unsigned long total;
  std::unique_ptr<T[]> vec;
};

template <typename T>
vector<T>::vector(int n) :
  tam{(n>0)?static_cast<unsigned long>(n):0},
  total{tam},
  vec{new T[n]{}} // Inicia todos a 0.0
{
}

template <typename T>
vector<T>::vector(std::initializer_list<T> l) :
  tam{l.size()},
  total{tam},
  vec{new T[l.size()]} // No inicia
{
  std::copy(l.begin(), l.end(), vec.get());
}

template <typename T>
vector<T>::vector(const vector & v) :
  tam{v.tam},
  total{v.tam},
  vec{new T[v.tam]}
{
  std::copy(v.vec.get(), v.vec.get() + v.tam, vec.get());
}

template <typename T>
vector<T> & vector<T>::operator=(const vector & v) {
  std::unique_ptr<T[]> aux{new T[v.tam]};
  std::copy(v.vec.get(), v.vec.get() + v.tam, aux.get());
  std::swap(vec,aux);
  tam = v.tam;
  total = tam;
  return *this;
}

template <typename T>
void vector<T>::reserva(int n) {
  if (n>0 && static_cast<unsigned long>(n)>total) {
    std::unique_ptr<T[]> aux{new T[n]};
    std::copy(vec.get(), vec.get() + tam, aux.get());
    std::swap(vec,aux);
    total = n;
  }
}

template <typename T>
void vector<T>::redimensiona(int n) {
  reserva(n);
  std::fill_n(vec.get() + tam, n-tam, T{});
  tam = n;
}

template <typename T>
void vector<T>::agrega_final(const T & x) {
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

template <typename T>
std::ostream & operator<<(std::ostream & fs, const vector<T> & v) {
  for (unsigned long i=0; i<v.tamanyo(); ++i) {
    fs << v[i] << ' ';
  }
  return fs;
}

template <typename T>
std::istream & operator>>(std::istream & fe, vector<T> & v) {
  unsigned long i=0;
  while ((i<v.tamanyo()) && (fe >> v[i++])) { }
  return fe;
}

} // Namespace

#endif
