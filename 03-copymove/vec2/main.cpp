#include "vector.h"

int main() {
  using namespace std;

  vector v1;
  cout << "v1: (" << v1 << ")" << endl;

  vector v2(5);
  v2.pon(2,5.0);
  v2.pon(4,3.5);
  cout << "v2: (" << v2 << ")" << endl;

  vector v3{1, 2, 3};
  cout << "v3: (" << v3 << ")" << endl;
}
