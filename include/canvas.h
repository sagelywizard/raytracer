#ifndef CANVAS_H_
#define CANVAS_H_

#include <memory>

#include "tuple.h"

class Canvas {
 public:
  explicit Canvas(unsigned int width, unsigned int height)
      : width_(width), height_(height) {
    buffer_ = std::make_unique<Color[]>(width * height);
  };
  Canvas canvas(const Canvas& canvas) = delete;

  void setPixel(const Color& color, unsigned int x, unsigned int y);

  const Color& getPixel(unsigned int x, unsigned int y) const;

  unsigned int getWidth() const;

  unsigned int getHeight() const;

 private:
  unsigned int width_;
  unsigned int height_;
  std::unique_ptr<Color[]> buffer_;
};

#endif
