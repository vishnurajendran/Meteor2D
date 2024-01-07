#pragma once
#include <iostream>
#include<vector>
#include <meteorutils/typehelpers.h>
#include<meteorutils/vector2d.h>
#include<entities/entity.h>
#include <SDL.h>

namespace meteor {
	class SpatialEntity : public Entity {
	public:
		inline SpatialEntity() : SpatialEntity(NULL) {};
		SpatialEntity(SpatialEntity* parent);
		~SpatialEntity();

		//local position
		inline Vector2 getPosition() { return position; }
		inline Vector2 getLocalPosition() { return localPosition; }
		inline void setLocalPosition(float x, float y) { localPosition.x = x; localPosition.y = y; updatePositions(); }
		inline void setLocalPosition(Vector2 pos) { localPosition.x = pos.x; localPosition.y = pos.y; updatePositions(); }

		//local rotation
		inline float getRotation() { return rotation; }
		inline float getLocalRotation() { return localRotation; }
		inline void setLocalRotation(float localRotation) { this->localRotation = localRotation; }
		//local scale
		Vector2 getLocalScale() { return localScale; };
		inline void setLocalScale(float x, float y) { localScale.x = x; localScale.y = y; }
		inline void setLocalScale(Vector2 scale) { localScale.x = scale.x; localScale.y = scale.y; }

		// hierarchy
		inline SpatialEntity* getParent() { return parent; }
		inline std::vector<SpatialEntity*>* getChildren() { return children; }

		void setChild(SpatialEntity* entity);
		void removeChild(SpatialEntity* entity);

		// query
		template<typename T>
		T* find(std::string name) {

			// is this node called 'name'
			if (this->name == name)
				return (T*)this;

			// if no more children return NULL
			if (children->size() <= 0)
				return NULL;

			// check recursively for each child
			for (auto child : *children) {
				if (child == NULL)
					continue;

				auto res = child->find<T>(name);
				if (res == NULL)
					continue;

				auto isValidInstance = instanceof<T>((T*)res);
				//if we found it, return
				if (res != NULL && isValidInstance)
					return (T*)res;
			}

			// if everything fails, return NULL
			return NULL;
		}

		// overrides
		virtual void onStart();
		virtual void onUpdate(float deltaTime);
		virtual void onExit();

	protected:
		Vector2 localPosition;
		Vector2 localScale;
		Vector2 position;
		float rotation;
		float localRotation;
		SpatialEntity* parent = NULL;
		std::vector<SpatialEntity*>* children = NULL;

		void updatePositions();
		void updateRotations();
		void updateScale();

		void updateChildren(float deltaTime);
	private:
		void setParent(SpatialEntity* entity) { parent = entity; };
	};
}