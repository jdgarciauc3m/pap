#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>

class vector {
public:
  vector() : tam{0}, vec{nullptr} {}
  explicit vector(int n);
  vector(std::initializer_list<double> l);

  vector(const vector &);
  vector & operator=(const vector &);

  vector(vector &&) = default;
  vector & operator=(vector &&) = default;

  int tamanyo() const { return tam; }

  double obten(int i) const { return vec[i]; }
  void pon(int i, double x) { vec[i] = x; }

private:
  unsigned long tam;
  std::unique_ptr<double[]> vec;
};

std::ostream & operator<<(std::ostream & fs, const vector & v);
std::istream & operator>>(std::istream & fe, vector & v);

#endif
