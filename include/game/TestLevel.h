#ifndef G_LEVEL_TEST
#define G_LEVEL_TEST

#include "GDefines.h"
#include "game/Level.h"
#include "core/EventBus.h"
#include "core/EntityManager.h"

namespace GPlay::Game {

class TestLevel : public Level {

  GPlay::Core::EntityManager m_EntityManager;
  EntityID playerId;

public:
  TestLevel(const std::string& name, EventBus* pEventBus) : Level{name, pEventBus} {
    playerId = m_EntityManager.RegisterEntity<Player>(EntityPos{0, 266}, 32.0f);
  }
  ~TestLevel(){}

  void Init()                        override;
  void Load()                        override;
  bool IsReady() const               override;
  void UpdateState(double deltaTime) override;
  void End(bool status)              override; 

};

} // GPlay::Game namespace
#endif // G_LEVEL_TEST guard
