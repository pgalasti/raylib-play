#ifndef G_LEVEL_H
#define G_LEVEL_H

#include "GDefines.h"
#include "core/Event.h"

#include <string>
#include <memory>
#include <queue>

namespace GPlay::Game {

using namespace GPlay::Core;

class Level {
  std::string name;

protected:
  std::queue<Event>* m_pEventQueue;

public:
  Level(const std::string& name, std::queue<Event>* pEventQueue) : name{name}, m_pEventQueue {pEventQueue} {}
  virtual ~Level(){}

  virtual void Init() = 0;
  virtual void Load(/**Maybe some resource?**/) = 0;
  virtual bool IsReady() const = 0;
  virtual void UpdateState(double deltaTime) = 0;
  virtual void End(bool status) = 0; 

  std::string_view GetName() const { return name; }

};

} // GPlay::Game namespace
#endif // G_LEVEL_H guard
