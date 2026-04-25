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

  m_pEventQueue->emplace(EntityMovementEvent{x, 10.0f});

}
  
void TestLevel::End(bool status) {

}
