#include "array.h"
#include <iostream>

int main() {
  using namespace std;
  using bcd::array;

  array<int,16> v1;
  array<double,8> v2 {1.0, 2.0};

  for (int i=0; i<v1.tamanyo(); ++i) {
    cout << v1[i] << " , ";
  }
  cout << endl;

  for (int i=0; i<v2.tamanyo(); ++i) {
    cout << v2[i] << " , ";
  }
  cout << endl;
}
