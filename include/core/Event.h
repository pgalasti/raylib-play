#ifndef GPLAY_EVENT_H
#define GPLAY_EVENT_H

#include "core/Entity.h"

#include <variant>

namespace GPlay::Core {

struct EntityMovementEvent   { 
  float x, y; 

  EntityMovementEvent(float x, float y) : x{x}, y{y} {} 
};
// Other event types here


using Event = std::variant<EntityMovementEvent>; // Add new types here.

} // GPlay::Core namespace


#endif // GPLAY_EVENT_H guard
