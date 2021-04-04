#ifndef PPM_H_
#define PPM_H_

#include <fstream>

#include "canvas.h"

void writePPMFile(const Canvas& canvas, std::ostream& ppm_file);

#endif  // PPM_H_
