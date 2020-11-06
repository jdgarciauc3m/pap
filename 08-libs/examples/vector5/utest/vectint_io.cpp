#include "vectint.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(vectint_io, empty)
{
  dcl::vectint v{5};
  for (int i=0;i<5;++i) {
    v[i] = i+1;
  }
  std::ostringstream os;
  os << v;
  EXPECT_EQ("1 2 3 4 5 ", os.str());
}

