#ifndef GPLAY_EVENT_H
#define GPLAY_EVENT_H

#include "core/Entity.h"

#include <variant>

namespace GPlay::Core {

struct EntityMovementEvent   {
  EntityID entityId;  
  float x, y; 

  EntityMovementEvent(EntityID id, float x, float y) : entityId{id}, x{x}, y{y} {} 
};
// Other event types here


using Event = std::variant<EntityMovementEvent>; // Add new types here.

} // GPlay::Core namespace


#endif // GPLAY_EVENT_H guard
