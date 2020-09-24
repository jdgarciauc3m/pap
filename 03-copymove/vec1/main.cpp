#include "vector.h"

int main() {
  using namespace std;

  vector v{5};
  v.pon(2,5.0);
  v.pon(4,3.5);

  cout << v << endl;
}
