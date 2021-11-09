#pragma once

#include "Types.h"
#include <array>
#include <cassert>
#include <queue>

using namespace std;

namespace ECS
{
	class EntityManager
	{
	public:
		EntityManager();
		Entity createEntity();
		void destroyEntity(Entity entity);
		void setSignature(Entity entity, Signature signature);
		Signature getSignature(Entity entity);

	private:
		queue<Entity> mAvailableEntities{};
		array<Signature, MAX_ENTITIES> mSignatures{};
		uint32_t mLivingEntityCount{};
	};
}
