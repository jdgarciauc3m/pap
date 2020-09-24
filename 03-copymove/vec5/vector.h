#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class vector {
public:
  vector() : tam{0}, vec{nullptr} {}
  explicit vector(int n);
  vector(std::initializer_list<double> l);

  ~vector() { delete[] vec; }

  vector(const vector & v);
  vector & operator=(const vector & v);

  vector(vector && v);
  vector & operator=(vector && v);

  int tamanyo() const { return tam; }

  double obten(int i) const { return vec[i]; }
  void pon(int i, double x) { vec[i] = x; }

private:
  unsigned long tam;
  double * vec;
};

std::ostream & operator<<(std::ostream & fs, const vector & v);
std::istream & operator>>(std::istream & fe, vector & v);

inline void intercambia(vector & v, vector & w) {
  vector aux{v};
  v = w;
  w = aux;
}

#endif
