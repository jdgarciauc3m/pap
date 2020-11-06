#include "vectint.h"
#include <iostream>

int main() {
  using namespace std;
  using namespace dcl;

  vectint v{5};
  v[2] = 5;
  
  vectint w{v};
  w[1] = 3;
  w.resize(4);

  cout << "v: " << v << endl;
  cout << "w: " << w << endl;

  swap(v,w);

  cout << endl << "Swap" << endl;
  cout << "v: " << v << endl;
  cout << "w: " << w << endl;

  return 0;
}
