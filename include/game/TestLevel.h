#ifndef G_LEVEL_TEST
#define G_LEVEL_TEST

#include "GDefines.h"
#include "game/Level.h"
#include "core/EventBus.h"
#include "core/EntityManager.h"

namespace GPlay::Game {

class TestLevel : public Level {

  EntityID playerId;

public:
  TestLevel(const std::string& name, EventBus* pEventBus, EntityManager* pEntityManager, EntityID playerId)
      : Level{name, pEventBus, pEntityManager}, playerId{playerId} {
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
