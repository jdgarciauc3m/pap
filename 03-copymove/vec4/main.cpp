#include "vector.h"

int main() {
  using namespace std;

  vector v1(5);
  v1.pon(2,5.0);
  v1.pon(4,3.5);

  vector v2{v1};
  v2.pon(0, 1.0);
  v1 = v2;
  
  cout << "v1: (" << v1 << ")" << endl;
  cout << "v2: (" << v2 << ")" << endl;
}
