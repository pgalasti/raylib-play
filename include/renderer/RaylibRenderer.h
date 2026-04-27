#ifndef GPLAY_RAYLIB_RENDERER_H
#define GPLAY_RAYLIB_RENDERER_H

#include "renderer/Renderer.h"
#include "renderer/Model.h"

namespace GPlay::Renderer {

class RaylibRenderer : public Renderer {
public:
  RaylibRenderer();
  ~RaylibRenderer(); 

   void StartFrame(const StartFrameOptions& options = {});
   void EndFrame(const EndFrameOptions& options = {});

   void DrawText(const TextOptions& options = {});
   void DrawModel(const Model&, const DrawOptions& options = {});
};


} // GPlay::Renderer namespace

#endif // GPLAY_RAYLIB_RENDERER_H
