#include <algorithm>
#include <fstream>

#include "canvas.h"
#include "ppm.h"
#include "tuple.h"

constexpr int width = 255;
constexpr int height = 255;

int main(void) {
  Canvas canvas(width, height);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      Tuple pixel(x, y, std::max(width, height), 0);
      canvas.setPixel(pixel, x, y);
    }
  }
  std::ofstream ppm_file("example.ppm");
  writePPMFile(canvas, ppm_file);
  ppm_file.close();
  return 0;
}
