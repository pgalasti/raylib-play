#include "game/TestLevel.h"

#include <raylib.h> // Remove this once we have entity coordinates setup

using namespace GPlay::Game;

void TestLevel::Init() {
  m_pEventBus->Subscribe<EntityMovementEvent>([](const EntityMovementEvent& e) {
    
    // Change this to actual entity coordinates. For now just render
    // until that system is setup
    Vector2 deltaCircle = { e.x, 800.0f/3.0f };
    DrawCircleV(deltaCircle, 32, RED);
  });
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
  m_pEventBus->Publish(EntityMovementEvent{id, x, 10.0f});
  GLOG("entity id: ")
  GLOG(id)
}
  
void TestLevel::End(bool status) {

}
