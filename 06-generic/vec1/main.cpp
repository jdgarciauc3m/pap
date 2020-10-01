#include "vector.h"

int main() {
  using namespace std;
  using bcd::vector; // En vez de std::vector

  vector<double> v1{1.5, 2.5, 3.5};
  vector<string> v2{"Daniel", "Carlos" };
  vector<int> v3{};
  v1.redimensiona(5);
  v2.agrega_final("Maria");
  v3 = {1, 2, 3};
  
  cout << "v1: (" << v1 << ")" << endl;
  cout << "v2: (" << v2 << ")" << endl;
  cout << "v3: (" << v3 << ")" << endl;
}
