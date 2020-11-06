#include "vectint.h"
#include <gtest/gtest.h>

TEST(vectint_copy, copy_construct)
{
  dcl::vectint v{4};
  v[0] = 1; v[3] = 42;
  dcl::vectint w{v};
  EXPECT_EQ(4, w.size());
  EXPECT_EQ(4, w.capacity());
  EXPECT_EQ(1, w[0]);
  EXPECT_EQ(0, w[1]);
  EXPECT_EQ(0, w[2]);
  EXPECT_EQ(42, w[3]);
}

TEST(vectint_copy, copy_assign)
{
  dcl::vectint v{4};
  v[0] = 1; v[3] = 42;
  dcl::vectint w{10};
  w = v;
  EXPECT_EQ(4, w.size());
  EXPECT_EQ(4, w.capacity());
  EXPECT_EQ(1, w[0]);
  EXPECT_EQ(0, w[1]);
  EXPECT_EQ(0, w[2]);
  EXPECT_EQ(42, w[3]);
}
