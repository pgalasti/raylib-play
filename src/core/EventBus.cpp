#include "core/EventBus.h"

using namespace GPlay::Core;

void EventBus::Publish(const Event& event) {
  m_EventQueue.emplace(event);
}

void EventBus::Unsubscribe(SubscriberID id) {
  // Do nothing for now.
}

void EventBus::Invoke() {
  while (!m_EventQueue.empty()) {
    Event event = m_EventQueue.front();
    m_EventQueue.pop();

    EventType type = std::visit(
      [](const auto& ev) { return std::decay_t<decltype(ev)>::type; }, event
    );

    auto it = m_HandlerMap.find(type);
    if (it != m_HandlerMap.end()) {
      for (auto& handler : it->second)
        handler(event);
    }
  }
}

void EventBus::Clear() {
  GLOG("Clearing event queue. Current size: ")
  GLOG(m_EventQueue.size())
  
  while(!m_EventQueue.empty())
    m_EventQueue.pop();
}

std::size_t EventBus::Size() const noexcept {
  return m_EventQueue.size();
}
