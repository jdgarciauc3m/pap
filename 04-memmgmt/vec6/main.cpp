#include "vector.h"

int main() {
  using namespace std;

  vector v1{1.0, 2.0, 3.0};
  vector v2{2.5, 3.5};
  vector v3{v1};
  std::swap(v1,v2);
  
  cout << "v1: (" << v1 << ")" << endl;
  cout << "v2: (" << v2 << ")" << endl;
  cout << "v3: (" << v3 << ")" << endl;
}
