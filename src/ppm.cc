// Portable Pixmap (PPM) file writer module

#include <cmath>
#include <fstream>

#include "canvas.h"
#include "tuple.h"

void writePPMFile(const Canvas& canvas, std::ostream& ppm_file) {
  // Writes PPM file header
  ppm_file << "P3\n";
  ppm_file << canvas.getWidth() << " " << canvas.getHeight() << "\n";
  ppm_file << "255\n";

  float maximum = 0.0;
  float minimum = 0.0;
  for (unsigned int y = 0; y < canvas.getHeight(); y++) {
    for (unsigned int x = 0; x < canvas.getWidth(); x++) {
      const Color& pixel = canvas.getPixel(x, y);
      for (const float& pixel_color : {pixel[0], pixel[1], pixel[2]}) {
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
  // TODO(bbastian) simplify this by turning canvas into an iterator
  for (unsigned int y = 0; y < canvas.getHeight(); y++) {
    for (unsigned int x = 0; x < canvas.getWidth(); x++) {
      const Color& pixel_color = canvas.getPixel(x, y);
      for (const float& pixel :
           {pixel_color[0], pixel_color[1], pixel_color[2]}) {
        int pixel_value = 0;
        if (std::fabs(minimum - maximum) > 1e-4) {
          pixel_value = lround(255 * ((pixel - minimum) / (maximum - minimum)));
        }
        int pixel_length = std::to_string(pixel_value).length();
        if (current_line_length == 0) {
          ppm_file << pixel_value;
          current_line_length += (pixel_length + 1);
        } else if (current_line_length + pixel_length + 1 > 70) {
          ppm_file << "\n" << pixel_value;
          current_line_length = pixel_length;
        } else {
          ppm_file << " " << pixel_value;
          current_line_length += (pixel_length + 1);
        }
      }
    }
  }
  // Apparently some ppm viewers require that the last line is a newline
  ppm_file << "\n";
}
