#include "game/TestLevel.h"
#include "game/Ball.h"

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
  if (m_ballId == -1) return;

  Ball*   ball   = static_cast<Ball*>(m_pEntityManager->Lookup(m_ballId));
  Entity* player = m_pEntityManager->Lookup(playerId);
  if (!ball || !player) return;

  EntityPos ballPos   = ball->GetPosition();
  auto      dir       = ball->GetDirection();
  float     speed     = ball->GetSpeed();

  constexpr float ballRadius    = 20.0f;
  constexpr float paddleWidth   = 20.0f;
  constexpr float paddleHeight  = 100.0f;

  float newDirX = dir.x;
  float newDirY = dir.y;
  bool  bounced = false;

  // Top and bottom walls
  if (ballPos.y - ballRadius <= 0.0f && dir.y < 0.0f) {
    newDirY = -newDirY;
    bounced = true;
  } else if (ballPos.y + ballRadius >= m_screenHeight && dir.y > 0.0f) {
    newDirY = -newDirY;
    bounced = true;
  }

  // Right wall
  if (ballPos.x + ballRadius >= m_screenWidth && dir.x > 0.0f) {
    newDirX = -newDirX;
    bounced = true;
  }

  // Player paddle (left side)
  EntityPos paddlePos = player->GetPosition();
  if (dir.x < 0.0f &&
      ballPos.x - ballRadius <= paddlePos.x + paddleWidth &&
      ballPos.y + ballRadius >= paddlePos.y &&
      ballPos.y - ballRadius <= paddlePos.y + paddleHeight) {
    newDirX = -newDirX;
    bounced = true;
  }

  if (bounced) {
    m_pEventBus->Publish(BallBounceEvent{newDirX, newDirY, speed});
  }
}
  
void TestLevel::End(bool status) {

}
