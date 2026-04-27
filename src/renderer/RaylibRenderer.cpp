#include "GDefines.h"
#include "renderer/RaylibRenderer.h"
#include "renderer/Model.h"

#include <raylib.h>

using namespace GPlay::Renderer;

RaylibRenderer::RaylibRenderer() {
  GLOG("Creating RaylibRenderer")
}

RaylibRenderer::~RaylibRenderer() {
}

void RaylibRenderer::StartFrame(const StartFrameOptions& options) {
  BeginDrawing();
}

void RaylibRenderer::EndFrame(const EndFrameOptions& options) {
  EndDrawing();
}

void RaylibRenderer::DrawText(const TextOptions& options) {
  ::DrawText(options.text.c_str(), options.posX, options.posY, options.fontSize, LIGHTGRAY);
}

void RaylibRenderer::DrawModel(const GPlay::Renderer::Model& model, const DrawOptions& options) {
  Shape shape = model.shape;
  switch(shape) {
    case Shape::Circle:
      const RadiusModel* circleModel = static_cast<const RadiusModel*>(&model);
      Vector2 circle {circleModel->xStart, circleModel->yStart};
      DrawCircleV(circle, 32, RED);
      break;
  };
}
