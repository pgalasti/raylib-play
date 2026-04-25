#ifndef GPLAY_EVENT_H
#define GPLAY_EVENT_H

#include "core/Entity.h"

#include <variant>

namespace GPlay::Core {

struct BlankPayload {};
struct EntityMovementPayload {
  EntityID entity;
  float x;
  float y;
};

class Event {

public:
  
  Event(EntityMovementPayload payload) : m_Payload{std::move(payload)} {} 

  template <typename T>
  Event(T data) : m_Payload {std::move(data)} {}

  const EntityMovementPayload& payload() const noexcept { return m_Payload; }

private:
  EntityMovementPayload m_Payload;
};

} // GPlay::Core namespace


#endif // GPLAY_EVENT_H guard
