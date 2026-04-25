#ifndef G_LEVEL_H
#define G_LEVEL_H

#include "GDefines.h"

#include <string>
#include <memory>

namespace GPlay::Game {

class Level {
  std::string name;
 
public:
  Level(const std::string& name) : name{name} {}
  virtual ~Level(){}

  virtual void Init() = 0;
  virtual void Load(/**Maybe some resource?**/) = 0;
  virtual bool IsReady() const = 0;
  virtual void UpdateState(double deltaTime) = 0;
  virtual void End(bool status) = 0; 

  std::string_view GetName() const { return name; }

};

} // GPlay::Game namespace
#endif // G_LEVEL_H guard
