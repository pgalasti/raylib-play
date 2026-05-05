#ifndef GPLAY_BALL_ENTITY_H
#define GPLAY_BALL_ENTITY_H

#include "GDefines.h"
#include "core/Entity.h"
#include "renderer/Renderer.h"
#include "core/Vector.h"

#include <memory>

namespace GPlay::Game {

struct Ball : public Entity {

  Ball(const EntityPos& position, EntityID id, float radius)
    : Entity(id, "Ball", position, makeModel(position, radius)),
      isInMotion{false}, speed{0.0f}, direction{0, 0} {
    GLOG("Creating ball")
  }

  void update(float deltaTime) {
    if(isInMotion) {
      SetPosition({position.x + direction.x * speed * deltaTime,
                   position.y + direction.y * speed * deltaTime});
    }
  }

  void draw(GPlay::Renderer::Renderer* pRenderer) {
    if(!visible) return;

    pRenderer->DrawModel(*m_Model, {});
  }

  void SetMoving(bool moving)         { isInMotion = moving; }
  void SetSpeed(float s)              { speed = s; }
  void SetDirection(float x, float y) { direction.x = x; direction.y = y; }

  GPlay::Core::Vector2D<float> GetDirection() const { return direction; }
  float                        GetSpeed()     const { return speed; }

private:

  bool isInMotion;
  float speed;
  GPlay::Core::Vector2D<float> direction;

  static std::unique_ptr<RadiusModel> makeModel(const EntityPos& position, float radius) {
    auto model = std::make_unique<RadiusModel>();
    model->shape    = Shape::Circle;
    model->rgbColor = 0xFF0000FF;
    model->xStart   = position.x;
    model->yStart   = position.y;
    model->radius   = radius;
    return model;
  }

};

} // GPlay::Game namespace

#endif // GPLAY_BALL_ENTITY_H guard
