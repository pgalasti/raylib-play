#include "core/EntityManager.h"

using namespace GPlay::Core;

EntityManager::EntityManager() {}

EntityManager::~EntityManager() {
  m_EntityMap.clear();
}


