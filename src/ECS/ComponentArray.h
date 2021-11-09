#pragma once

#include "Types.h"
#include <array>
#include <cassert>
#include <unordered_map>

using namespace std;

namespace ECS
{
	class IComponentArray
	{
	public:
		virtual ~IComponentArray() = default;
		virtual void entityDestroyed(Entity entity) = 0;
	};

	template<typename T>
	class ComponentArray : public IComponentArray
	{
	public:
		void insertData(Entity entity, T component);
		void removeData(Entity entity);
		T& getData(Entity entity);
		void entityDestroyed(Entity entity) override;

	private:
		array<T, MAX_ENTITIES> mComponentArray{};
		unordered_map<Entity, size_t> mEntityToIndexMap{};
		unordered_map<size_t, Entity> mIndexToEntityMap{};
		size_t mSize{};
	};

	template<typename T>
	inline void ComponentArray<T>::insertData(Entity entity, T component)
	{
		assert(mEntityToIndexMap.find(entity) == mEntityToIndexMap.end() && "Component added to same entity more than once.");

		// Put new entry at the end
		size_t newIndex = mSize;
		mEntityToIndexMap[entity] = newIndex;
		mIndexToEntityMap[newIndex] = entity;
		mComponentArray[newIndex] = component;
		mSize++;
	}

	template<typename T>
	inline void ComponentArray<T>::removeData(Entity entity)
	{
		assert(mEntityToIndexMap.find(entity) != mEntityToIndexMap.end() && "Removing non-existent component.");

		// Copy element at end into deleted element's place to maintain density
		size_t indexOfRemovedEntity = mEntityToIndexMap[entity];
		size_t indexOfLastElement = mSize - 1;
		mComponentArray[indexOfRemovedEntity] = mComponentArray[indexOfLastElement];

		// Update map to point to moved spot
		Entity entityOfLastElement = mIndexToEntityMap[indexOfLastElement];
		mEntityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
		mIndexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

		mEntityToIndexMap.erase(entity);
		mIndexToEntityMap.erase(indexOfLastElement);

		mSize--;
	}

	template<typename T>
	inline T& ComponentArray<T>::getData(Entity entity)
	{
		assert(mEntityToIndexMap.find(entity) != mEntityToIndexMap.end() && "Retrieving non-existent component.");
		return mComponentArray[mEntityToIndexMap[entity]];
	}

	template<typename T>
	inline void ComponentArray<T>::entityDestroyed(Entity entity)
	{
		if (mEntityToIndexMap.find(entity) != mEntityToIndexMap.end())
		{
			removeData(entity);
		}
	}

}

