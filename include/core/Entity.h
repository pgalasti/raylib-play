#ifndef GPLAY_ENTITY_H
#define GPLAY_ENTITY_H

#include "GDefines.h"

#include <cstddef>
#include <string>

namespace GPlay::Core {

using EntityID = std::size_t;

struct EntityPos {
  float x, y;
};

struct Entity {
protected:
  EntityID id;
  std::string name;

  EntityPos position;
  bool visible;
  // Model needed

public:
  Entity(EntityID id, const std::string& name, const EntityPos& position) 
	  : id{id}, name{name}, position{position}, visible{false} {}
  virtual ~Entity() {}

  virtual void update(float deltaTime)      = 0;
  virtual void draw()                       = 0;

  EntityID         GetID()       const noexcept { return id;       }
  std::string_view GetName()     const noexcept { return name;     }
  EntityPos        GetPosition() const noexcept { return position; }
  bool             IsVisible()   const noexcept { return visible;  }
  void             SetVisible(bool visibility) noexcept { visible = visibility; }

};

constexpr EntityID PlayerID {0};

struct Player : public Entity {

  Player(const EntityPos& position) : Entity(0, "Player", position) { 
    GLOG("Creating player")    
  }
  ~Player(){}

  void update(float deltaTime) {
  }

  void draw() {
  }
};

} // GPlay::Core namespace

#endif // GPLAY_ENTITY_H guard
