#include "game/TestLevel.h"

using namespace GPlay::Game;

void TestLevel::Init() {
}

void TestLevel::Load() {

}

bool TestLevel::IsReady() const {
  return true;
}

void TestLevel::UpdateState(double deltaTime) {

  static float x {0};
  x += (deltaTime*500);

  int idInt {m_EntityIDGenerator.GetNextId()};
  EntityID id {static_cast<EntityID>(idInt)};  
  m_pEventQueue->emplace(EntityMovementEvent{id, x, 10.0f});
  GLOG("entity id: ")
  GLOG(id)
}
  
void TestLevel::End(bool status) {

}
