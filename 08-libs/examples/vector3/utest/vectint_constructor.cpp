#include "vectint.h"
#include <gtest/gtest.h>

TEST(vectint_constructor, empty)
{
  dcl::vectint v;
  EXPECT_EQ(0, v.size());
  EXPECT_EQ(0, v.capacity());
}

TEST(vectint_constructor, sized)
{
  dcl::vectint v{10};
  EXPECT_EQ(10, v.size());
  EXPECT_EQ(10, v.capacity());
}
