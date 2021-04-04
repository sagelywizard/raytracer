#include "canvas.h"

#include "gtest/gtest.h"
#include "ppm.h"
#include "tuple.h"

TEST(canvasTest, canvasSize) {
  const unsigned int width = 20;
  const unsigned int height = 30;
  Canvas canvas(width, height);
  EXPECT_EQ(canvas.getWidth(), width);
  EXPECT_EQ(canvas.getHeight(), height);
}

TEST(canvasTest, newCanvasIsAllBlack) {
  const unsigned int width = 30;
  const unsigned int height = 20;
  Canvas canvas(width, height);
  for (unsigned int x = 0; x < width; x++) {
    for (unsigned int y = 0; y < height; y++) {
      const Tuple pixel = canvas.getPixel(x, y);
      ASSERT_EQ(pixel.getX(), 0);
      ASSERT_EQ(pixel.getY(), 0);
      ASSERT_EQ(pixel.getZ(), 0);
    }
  }
}

TEST(canvasTest, setPixel) {
  const unsigned int width = 30;
  const unsigned int height = 20;
  Canvas canvas(width, height);
  Tuple new_pixel(1, 1, 1, 0);
  canvas.setPixel(new_pixel, 10, 10);
  for (unsigned int x = 0; x < width; x++) {
    for (unsigned int y = 0; y < height; y++) {
      const Tuple pixel = canvas.getPixel(x, y);
      if (x == 10 && y == 10) {
        ASSERT_EQ(pixel.getX(), 1);
        ASSERT_EQ(pixel.getY(), 1);
        ASSERT_EQ(pixel.getZ(), 1);
      } else {
        ASSERT_EQ(pixel.getX(), 0);
        ASSERT_EQ(pixel.getY(), 0);
        ASSERT_EQ(pixel.getZ(), 0);
      }
    }
  }
}

TEST(canvasTest, checkPPMHeader) {
  const unsigned int width = 30;
  const unsigned int height = 20;
  Canvas canvas(width, height);
  std::ostringstream ppm_file;
  writePPMFile(canvas, ppm_file);
  std::string ppm_string = ppm_file.str();
  ASSERT_EQ(ppm_string.rfind("P3\n30 20\n255\n", 0), 0);
}

TEST(canvasTest, checkPPMBody) {
  const unsigned int width = 5;
  const unsigned int height = 4;
  Canvas canvas(width, height);
  std::ostringstream ppm_file;
  Tuple white_pixel(10, 10, 10, 0);
  Tuple half_green_pixel(0, 5, 0, 0);
  Tuple quarter_blue_pixel(0, 0, 2.5, 0);

  canvas.setPixel(white_pixel, 0, 0);
  canvas.setPixel(half_green_pixel, 1, 1);
  canvas.setPixel(white_pixel, 0, 2);
  canvas.setPixel(quarter_blue_pixel, 4, 3);

  writePPMFile(canvas, ppm_file);
  std::string ppm_string = ppm_file.str();
  std::string output =
      "255 255 255 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 128 0 0 0 0 0 0 0 0 0 0\n"
      "255 255 255 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 64";
  ASSERT_EQ(ppm_string.substr(12, ppm_string.length()), output);
}
