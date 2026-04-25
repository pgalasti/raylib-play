#ifndef FRAME_TIMER_H
#define FRAME_TIMER_H

#include <raylib.h>

namespace GPlay::Core {

class FrameTimer {
  
public:
  virtual ~FrameTimer() {}

  virtual double GetFrameTime() = 0;
  virtual void   Tick()         = 0;
};

// Raylib implementation

class RLFrameTimer : public FrameTimer {

  float m_LastTime {0.0f};

public:
  void Tick() {
    m_LastTime = ::GetFrameTime();
  }

  double GetFrameTime() override {
    return static_cast<double>(m_LastTime);    
  }
};

}
#endif //FRAME_TIMER_H guard
