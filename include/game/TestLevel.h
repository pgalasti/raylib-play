#ifndef G_LEVEL_TEST
#define G_LEVEL_TEST

#include "GDefines.h"
#include "game/Level.h"

#include "g-lib/util/IDGenerator.h"

namespace GPlay::Game {

class TestLevel : public Level {

  // Ugly. Should have own class shared across levels/systems
  GLib::Util::IDGenerator<int> m_EntityIDGenerator {1};

public:
  TestLevel(const std::string& name, std::queue<Event>* pEventQueue) 
	  : Level{name, pEventQueue} {}
  ~TestLevel(){}

  void Init()                        override;
  void Load()                        override;
  bool IsReady() const               override;
  void UpdateState(double deltaTime) override;
  void End(bool status)              override; 

};

} // GPlay::Game namespace
#endif // G_LEVEL_TEST guard
