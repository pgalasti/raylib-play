#ifndef G_LEVEL_H
#define G_LEVEL_H

#include "GDefines.h"
#include "core/Event.h"
#include "core/EventBus.h"
#include "core/EntityManager.h"

#include <string>
#include <memory>
#include <queue>

namespace GPlay::Game {

using namespace GPlay::Core;

class Level {
  std::string name;

protected:
  EventBus*      m_pEventBus;
  EntityManager* m_pEntityManager;
  EntityID       m_ballId       {-1};
  int            m_screenWidth  {0};
  int            m_screenHeight {0};

public:
  Level(const std::string& name, EventBus* pEventBus, EntityManager* pEntityManager)
      : name{name}, m_pEventBus{pEventBus}, m_pEntityManager{pEntityManager} {}
  virtual ~Level(){}

  virtual void Init()                           = 0;
  virtual void Load(/**Maybe some resource?**/) = 0;
  virtual bool IsReady() const                  = 0;
  virtual void UpdateState(double deltaTime)    = 0;
  virtual void End(bool status)                 = 0;

  void SetBallId(EntityID id)            { m_ballId = id; }
  void SetScreenDimensions(int w, int h) { m_screenWidth = w; m_screenHeight = h; }

  std::string_view GetName() const { return name; }

};

} // GPlay::Game namespace
#endif // G_LEVEL_H guard
