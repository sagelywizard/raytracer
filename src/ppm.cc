// Portable Pixmap (PPM) file writer module

#include <cmath>
#include <fstream>

#include "canvas.h"

void writePPMFile(const Canvas& canvas, std::ostream& ppm_file) {
  // Writes PPM file header
  ppm_file << "P3\n";
  ppm_file << canvas.getWidth() << " " << canvas.getHeight() << "\n";
  ppm_file << "255\n";

  float maximum = 0.0;
  float minimum = 0.0;
  for (unsigned int y = 0; y < canvas.getHeight(); y++) {
    for (unsigned int x = 0; x < canvas.getWidth(); x++) {
      const Tuple& pixel = canvas.getPixel(x, y);
      for (const float& pixel_color :
           {pixel.getX(), pixel.getY(), pixel.getZ()}) {
        if (pixel_color > maximum) {
          maximum = pixel_color;
        }
        if (pixel_color < minimum) {
          minimum = pixel_color;
        }
      }
    }
  }

  int current_line_length = 0;
  for (unsigned int y = 0; y < canvas.getHeight(); y++) {
    for (unsigned int x = 0; x < canvas.getWidth(); x++) {
      const Tuple& tuple = canvas.getPixel(x, y);
      for (const float& pixel : {tuple.getX(), tuple.getY(), tuple.getZ()}) {
        int pixel_value = 0;
        if (abs(minimum - maximum) > 1e-4) {
          pixel_value = lround(255 * ((pixel - minimum) / (maximum - minimum)));
        }
        int pixel_length = std::to_string(pixel_value).length();
        if (current_line_length + pixel_length + 1 > 70) {
          ppm_file << "\n" << pixel_value;
          current_line_length = pixel_length;
        } else {
          ppm_file << " " << pixel_value;
          current_line_length += (pixel_length + 1);
        }
      }
    }
  }
}
