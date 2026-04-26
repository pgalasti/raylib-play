#ifndef EVENT_BUS_H
#define EVENT_BUS_H

#include "GDefines.h"
#include "Event.h"
#include "g-lib/util/IDGenerator.h"

#include <queue>
#include <functional>
#include <unordered_map>

namespace GPlay::Core {

using SubscriberID = int;

using EventQueue = std::queue<Event>;

class EventBus {
  EventQueue m_EventQueue;
  GLib::Util::IDGenerator<SubscriberID> m_SubscriberIdGen{1, 1};

  // Ugly. Needs to be typedef'd and moved to own class at some point
  std::unordered_map<EventType, std::vector<std::function<void(const Event&)>>> m_HandlerMap;

public:

  template <typename EvType>
  SubscriberID Subscribe(std::function<void(const EvType&)> callback) {
    m_HandlerMap[EvType::type].push_back(
      [callback = std::move(callback)](const Event& e) { callback(std::get<EvType>(e)); }
    );

    // Need to tie this to the event handler some how. Maybe when I refactor that ugly map
    SubscriberID id = m_SubscriberIdGen.GetNextId();
    return id;
  }

  void Unsubscribe(SubscriberID id);
  void Publish(const Event& event);

  void Invoke();

  void Clear();
  std::size_t Size() const noexcept;
};

}; // GPlay::Core namespace

#endif //EVENT_BUS_H guard

