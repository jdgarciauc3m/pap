#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>

class vector {
public:
  vector() : tam{0}, total{0}, vec{nullptr} {}
  explicit vector(int n);
  vector(std::initializer_list<double> l);

  vector(const vector &);
  vector & operator=(const vector &);

  vector(vector &&) = default;
  vector & operator=(vector &&) = default;

  double operator[](int i) const { return vec[i]; }
  double & operator[](int i) { return vec[i]; }

  unsigned long tamanyo() const { return tam; }
  unsigned long capacidad() const { return total; }

  void reserva(int n);
  void redimensiona(int n);
  void agrega_final(double x);

private:
  unsigned long tam;
  unsigned long total;
  std::unique_ptr<double[]> vec;
};

std::ostream & operator<<(std::ostream & fs, const vector & v);
std::istream & operator>>(std::istream & fe, vector & v);

#endif
