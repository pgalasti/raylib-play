#ifndef GPLAY_MODEL_H
#define GPLAY_MODEL_H

#include <cstdint>

namespace GPlay::Renderer {

enum class Shape {
  Point,
  Line,
  Circle,
  Triangle,
  Rectangle
};

// Could get fancy with this later
//using RGBColor = std::bitset<32>;

using RGBColor = std::uint32_t;

struct Model {

  virtual ~Model(){}

  RGBColor rgbColor {0x00000000};
  Shape shape       {Shape::Point};
  float xStart;
  float yStart;
};

struct RadiusModel : public Model {
  float radius;
};

struct PolygonModel : public Model {
  float xEnd;
  float yEnd;
};


} // GPlay::Renderer namespace

#endif // GPLAY_MODEL_H
