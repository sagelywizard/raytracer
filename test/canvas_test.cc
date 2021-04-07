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
      const Color pixel = canvas.getPixel(x, y);
      ASSERT_EQ(pixel[0], 0);
      ASSERT_EQ(pixel[1], 0);
      ASSERT_EQ(pixel[2], 0);
    }
  }
}

TEST(canvasTest, setPixel) {
  const unsigned int width = 30;
  const unsigned int height = 20;
  Canvas canvas(width, height);
  float pixel_rgb[3] = {1.0, 1.0, 1.0};
  Color new_pixel(pixel_rgb);
  canvas.setPixel(new_pixel, 10, 10);
  for (unsigned int x = 0; x < width; x++) {
    for (unsigned int y = 0; y < height; y++) {
      const Color pixel = canvas.getPixel(x, y);
      if (x == 10 && y == 10) {
        ASSERT_EQ(pixel[0], pixel_rgb[0]);
        ASSERT_EQ(pixel[1], pixel_rgb[1]);
        ASSERT_EQ(pixel[2], pixel_rgb[2]);
      } else {
        ASSERT_EQ(pixel[0], 0.0f);
        ASSERT_EQ(pixel[1], 0.0f);
        ASSERT_EQ(pixel[2], 0.0f);
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
  float white_rgb[3] = {10, 10, 10};
  Color white_pixel(white_rgb);
  float half_green_rgb[3] = {0, 5, 0};
  Color half_green_pixel(half_green_rgb);
  float quarter_blue_rgb[3] = {0, 0, 2.5};
  Color quarter_blue_pixel(quarter_blue_rgb);

  canvas.setPixel(white_pixel, 0, 0);
  canvas.setPixel(half_green_pixel, 1, 1);
  canvas.setPixel(white_pixel, 0, 2);
  canvas.setPixel(quarter_blue_pixel, 4, 3);

  writePPMFile(canvas, ppm_file);
  std::string ppm_string = ppm_file.str();
  std::string output =
      "255 255 255 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 128 0 0 0 0 0 0 0 0 0 0\n"
      "255 255 255 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 64\n";
  ASSERT_EQ(ppm_string.substr(11, ppm_string.length()), output);
}
