#ifndef G_LEVEL_H
#define G_LEVEL_H

#include "GDefines.h"
#include "core/Event.h"
#include "core/EventBus.h"

#include <string>
#include <memory>
#include <queue>

namespace GPlay::Game {

using namespace GPlay::Core;

class Level {
  std::string name;

protected:
  EventBus* m_pEventBus;

public:
  Level(const std::string& name, EventBus* pEventBus) 
	  : name{name}, m_pEventBus{pEventBus} {}
  virtual ~Level(){}

  virtual void Init()                           = 0;
  virtual void Load(/**Maybe some resource?**/) = 0;
  virtual bool IsReady() const                  = 0;
  virtual void UpdateState(double deltaTime)    = 0;
  virtual void End(bool status)                 = 0; 

  std::string_view GetName() const { return name; }

};

} // GPlay::Game namespace
#endif // G_LEVEL_H guard
