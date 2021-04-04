#include "canvas.h"

#include "tuple.h"

void Canvas::setPixel(const Tuple& color, unsigned int x, unsigned int y) {
  buffer_[y * width_ + x] = color;
}

const Tuple& Canvas::getPixel(unsigned int x, unsigned int y) const {
  return buffer_[y * width_ + x];
}

unsigned int Canvas::getWidth() const { return width_; }

unsigned int Canvas::getHeight() const { return height_; }
