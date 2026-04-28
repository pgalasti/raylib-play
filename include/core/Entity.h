#ifndef GPLAY_ENTITY_H
#define GPLAY_ENTITY_H

#include "GDefines.h"
#include "renderer/Renderer.h"

#include <cstddef>
#include <memory>
#include <string>

namespace GPlay::Core {

using namespace GPlay::Renderer;

using EntityID = int;

struct EntityPos {
  float x, y;
};

struct Entity {
protected:
  EntityID id;
  std::string name;

  EntityPos position;
  bool visible;
  std::unique_ptr<Model> m_Model;

public:
  Entity(EntityID id, const std::string& name, const EntityPos& position, std::unique_ptr<Model> model)
	  : id{id}, name{name}, position{position}, visible{false}, m_Model{std::move(model)} {}
  virtual ~Entity() {}

  virtual void update(float deltaTime)          = 0;
  virtual void draw(GPlay::Renderer::Renderer*) = 0;

  EntityID         GetID()       const noexcept { return id;       }
  std::string_view GetName()     const noexcept { return name;     }
  EntityPos        GetPosition() const noexcept { return position; }
  bool             IsVisible()   const noexcept { return visible;  }
  void             SetVisible(bool visibility) noexcept { visible = visibility; }
  void             SetPosition(const EntityPos& pos) noexcept {
    position = pos;
    m_Model->xStart = pos.x;
    m_Model->yStart = pos.y;
  }
  const Model&     GetModel()    const noexcept { return *m_Model; }

};

constexpr EntityID PlayerID {0};

struct Player : public Entity {

  Player(const EntityPos& position, float radius) 
	  : Entity(PlayerID, "Player", position, makeModel(position, radius)) {
    GLOG("Creating player")
  }
  ~Player(){}

  void update(float deltaTime) {
  }

  void draw(GPlay::Renderer::Renderer* pRenderer) {
    if(!visible) return;

    pRenderer->DrawModel(*m_Model, {});
  }

private:
  static std::unique_ptr<RadiusModel> makeModel(const EntityPos& position, float radius) {
    auto m = std::make_unique<RadiusModel>();
    m->shape  = Shape::Circle;
    m->xStart = position.x;
    m->yStart = position.y;
    m->radius = radius;
    return m;
  }
};

} // GPlay::Core namespace

#endif // GPLAY_ENTITY_H guard
