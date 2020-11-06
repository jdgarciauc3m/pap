#include <iosfwd>

class fecha {
public:
  // ...
  friend std::ostream & 
  operator<<(ostream & os, const fecha & f);

  friend std::istream & 
  operator>>(std::istream & is, fecha & f);
};
