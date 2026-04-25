#ifndef G_LEVEL_TEST
#define G_LEVEL_TEST

#include "GDefines.h"
#include "game/Level.h"

namespace GPlay::Game {

class TestLevel : public Level {
 
public:
  TestLevel(const std::string& name, std::queue<Event>* pEventQueue) : Level{name, pEventQueue} {}
  ~TestLevel(){}

  void Init() override;
  void Load() override;
  bool IsReady() const override;
  void UpdateState(double deltaTime) override;
  void End(bool status) override; 

};

} // GPlay::Game namespace
#endif // G_LEVEL_TEST guard
