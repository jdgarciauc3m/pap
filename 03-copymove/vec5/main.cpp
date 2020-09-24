#include "vector.h"

int main() {
  using namespace std;

  vector v1{1.0, 2.0, 3.0};
  vector v2{2.5, 3.5};
  intercambia(v1,v2);
  
  cout << "v1: (" << v1 << ")" << endl;
  cout << "v2: (" << v2 << ")" << endl;
}
