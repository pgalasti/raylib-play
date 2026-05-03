#ifndef GPLAY_EVENT_H
#define GPLAY_EVENT_H

#include "core/Entity.h"

#include <variant>

namespace GPlay::Core {

enum class EventType {

  EntityMovement,
  BallCreate
  // Add new ones here
};

struct EntityMovementEvent   {

  static constexpr EventType type = EventType::EntityMovement;

  EntityID entityId;  
  float x, y; 

  EntityMovementEvent(EntityID id, float x, float y) : entityId{id}, x{x}, y{y} {} 
};
struct BallCreateEvent {

  static constexpr EventType type = EventType::BallCreate;

  EntityID entityId;
  EntityPos position;
  float radius;
  float dirX, dirY;
  float speed;

  BallCreateEvent(EntityID id, const EntityPos& position, float radius, float dirX, float dirY, float speed)
    : entityId{id}, position{position}, radius{radius}, dirX{dirX}, dirY{dirY}, speed{speed} {}
};
// Other event types here


using Event = std::variant<EntityMovementEvent, BallCreateEvent>; // Add new types here.

} // GPlay::Core namespace


#endif // GPLAY_EVENT_H guard
