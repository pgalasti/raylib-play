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
  m_pEventBus->Publish(EntityMovementEvent{playerId, 10.0f, 266.0f});

}
  
void TestLevel::End(bool status) {

}
