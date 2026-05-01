#ifndef GPLAY_RENDERER_H
#define GPLAY_RENDERER_H

#include "renderer/Model.h"

namespace GPlay::Renderer {

struct StartFrameOptions {
};

struct EndFrameOptions {
};

struct TextOptions {
  std::string text;
  float       posX;
  float       posY;
  int         fontSize;
  int         colorHex;
};

struct DrawOptions {

};

class Renderer {
public:

  virtual ~Renderer() {}

  virtual void StartFrame(const StartFrameOptions&)         = 0;
  virtual void EndFrame(const EndFrameOptions&)             = 0;

  virtual void DrawText(const TextOptions&)                 = 0;
  virtual void DrawModel(const Model&, const DrawOptions&)  = 0;
};


} // GPlay::Renderer namespace

#endif // GPLAY_RENDERER_H
