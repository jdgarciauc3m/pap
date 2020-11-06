#include "vectint.h"
#include <gtest/gtest.h>

class vectint_sizing : public ::testing::Test {
protected:
  vectint_sizing() {
    for (int i=0;i<4;++i) {
      v[i] = i+1;
    }
  }

  bool content_ok() const;

  dcl::vectint v{4};
};

bool vectint_sizing::content_ok() const {
  for (int i=0;i<4;++i) {
    if (v[i] != i+1) return false;
  }
  for (int i=4;i<v.size();++i) {
    if (v[i] != 0) return false;
  }
  return true;
}

TEST_F(vectint_sizing, reserve_grow)
{
  v.reserve(50);
  EXPECT_EQ(4, v.size());
  EXPECT_EQ(50, v.capacity());
  EXPECT_TRUE(content_ok());
}

TEST_F(vectint_sizing, reserve_shrink)
{
  v.reserve(2);
  EXPECT_EQ(4, v.size());
  EXPECT_EQ(4, v.capacity());
  EXPECT_TRUE(content_ok());
}

TEST_F(vectint_sizing, resize_grow_over_capacity)
{
  v.reserve(6);
  v.resize(8);
  EXPECT_EQ(8, v.size());
  EXPECT_EQ(8, v.capacity());
  EXPECT_TRUE(content_ok());
}

TEST_F(vectint_sizing, resize_grow_under_capacity)
{
  v.reserve(6);
  v.resize(5);
  EXPECT_EQ(5, v.size());
  EXPECT_EQ(6, v.capacity());
  EXPECT_TRUE(content_ok());
}

TEST_F(vectint_sizing, resize_shrink)
{
  v.reserve(6);
  v.resize(2);
  EXPECT_EQ(2, v.size());
  EXPECT_EQ(6, v.capacity());
  EXPECT_EQ(1, v[0]);
  EXPECT_EQ(2, v[1]);
}
