#include "canvas.h"

#include "tuple.h"

void Canvas::setPixel(const Tuple& color, unsigned int x, unsigned int y) {
  buffer_[y * width_ + x] = color;
}

unsigned int Canvas::getWidth() const { return width_; }

unsigned int Canvas::getHeight() const { return height_; }
