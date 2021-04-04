#include "canvas.h"

#include "gtest/gtest.h"
#include "tuple.h"

TEST(canvasTest, emptyCanvas) {
  const unsigned int width = 20;
  const unsigned int height = 20;
  Canvas canvas(width, height);
  EXPECT_EQ(canvas.getWidth(), width);
  EXPECT_EQ(canvas.getHeight(), height);
}
