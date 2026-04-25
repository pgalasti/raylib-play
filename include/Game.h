#ifndef GAME_H
#define GAME_H

namespace GPlay::Core {

class Game {

  bool m_IsRunning  {false};

public:
  void Initialize();

  void Run();
  void PollInput();
  void UpdateState(double deltaTime);
  void RenderScreen();

  
  inline bool IsRunning() const     { return m_IsRunning; }

};

} // GPlay::Core


#endif // GAME_H Guard
