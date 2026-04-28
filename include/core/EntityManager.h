#ifndef GPLAY_ENTITY_MANAGER_H
#define GPLAY_ENTITY_MANAGER_H

#include "GDefines.h"
#include "Entity.h"

#include "g-lib/util/IDGenerator.h"

#include <unordered_map>
#include <memory>

namespace GPlay::Core {

using EntityMap = std::unordered_map<EntityID, std::unique_ptr<Entity>>;

class EntityManager {

 EntityMap m_EntityMap; 
 GLib::Util::IDGenerator<EntityID> m_EntityIDGenerator{1, 1};

public:

  EntityManager();
  ~EntityManager();


  EntityManager(const EntityManager&)             = delete;
  EntityManager(const EntityManager&&)            = delete;
  EntityManager& operator=(const EntityManager&)  = delete;
  EntityManager& operator=(const EntityManager&&) = delete;

  template<typename T, typename... Args>
  EntityID RegisterEntity(Args&&... args) {
    EntityID id = m_EntityIDGenerator.GetNextId();
    m_EntityMap.emplace(id, std::make_unique<T>(std::forward<Args>(args)...));
    GLOG("Registered new entity:")
    GLOG(id)
    return id;
  }

  Entity* Lookup(EntityID id) {
    auto iter{m_EntityMap.find(id)};
    return iter == m_EntityMap.end() ? nullptr : iter->second.get();
  }

};

} // GPlay::Core namespace

#endif // GPLAY_ENTITY_MANAGER_H guard
