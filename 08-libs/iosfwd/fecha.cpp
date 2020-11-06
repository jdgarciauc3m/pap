#include "fecha.h"
#include <iostream>

std::ostream & 
operator<<(std::ostream & os, const fecha & f) {
  os << "Fecha: ";
  //...
  return os;
}

std::istream & 
operator>>(std::istream & is, fecha & f) {
  // ...
  return is;
}
