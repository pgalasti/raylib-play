#include "game/TestLevel.h"

#include <raylib.h> // Remove this once we have entity coordinates setup

using namespace GPlay::Game;

void TestLevel::Init() {
  m_pEventBus->Subscribe<EntityMovementEvent>([this](const EntityMovementEvent& e) {

    Entity* entity = m_EntityManager.Lookup(playerId);
    if(entity == nullptr) {
      throw 1;
    }

    entity->SetPosition({e.x, entity->GetPosition().y});
    auto pos = entity->GetPosition();
    Vector2 drawPos = { pos.x, pos.y };
    DrawCircleV(drawPos, static_cast<const RadiusModel&>(entity->GetModel()).radius, RED);
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

  m_pEventBus->Publish(EntityMovementEvent{playerId, x, 10.0f});
}
  
void TestLevel::End(bool status) {

}
