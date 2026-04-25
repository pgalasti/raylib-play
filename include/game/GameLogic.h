#ifndef G_LOGIG_H
#define G_LOGIG_H

#include "GDefines.h"

#include <string>

class GameLogic {

  std::string name;
  
public:
  GameLogic(const std::string& name) : name{name} {

  }
  ~GameLogic() {}



};

#endif // G_LOGIC_H guard

