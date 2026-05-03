#include "game/TestLevel.h"

#include <cmath>
#include <random>

using namespace GPlay::Game;
using namespace GPlay::Core;

void TestLevel::Init() {
}

void TestLevel::Load() {
  constexpr float pi = 3.14159265f;

  std::mt19937 gen(std::random_device{}());
  std::uniform_real_distribution<float> dist(-pi / 4.0f, pi / 4.0f);
  float angle = pi + dist(gen); // left-facing (180°) ± 45°

  m_pEventBus->Publish(BallCreateEvent{2, EntityPos{800.0f, 400.0f}, 20.0f,
                                       std::cos(angle), std::sin(angle), 200.0f});
}

bool TestLevel::IsReady() const {
  return true;
}

void TestLevel::UpdateState(double deltaTime) {
}
  
void TestLevel::End(bool status) {

}
