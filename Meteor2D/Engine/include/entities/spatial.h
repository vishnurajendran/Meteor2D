#pragma once
#include <iostream>
#include<vector>
#include <meteorutils/typehelpers.h>
#include<meteorutils/vector2d.h>
#include<entities/entity.h>
#include <SDL.h>

namespace meteor {
	/**
	 * @brief Spatial Entity is the base entity for all types present in scene. This entity
	 * keeps track of spatial data within a scene. new instance when not given a parent, will
	 * sit at the root of the active scene.
	*/
	class MSpatialEntity : public MEntity {
	public:
		/**
		 * @brief Default constructor, instantiates at root level.
		*/
		inline MSpatialEntity() : MSpatialEntity(NULL) {};
		/**
		 * @brief Parameterised constructor.
		 * @param parent Parent entity for this child.
		*/
		MSpatialEntity(MSpatialEntity* parent);
		~MSpatialEntity();

		/**
		 * @return World position of this entity 
		*/
		inline SVector2 getPosition() { return position; }
		/**
		 * @return Local position of this entity.
		*/
		inline SVector2 getLocalPosition() { return localPosition; }
		/**
		 * @brief Sets local position of the entity
		 * @param x x-component of the position
		 * @param y y-component of the position
		*/
		inline void setLocalPosition(float x, float y) { localPosition.x = x; localPosition.y = y; updatePositions(); }
		/**
		 * @brief Sets local position of the entity
		 * @param pos position as a Vector2
		 */
		inline void setLocalPosition(SVector2 pos) { localPosition.x = pos.x; localPosition.y = pos.y; updatePositions(); }

		/**
		 * @return World rotation of this entity in x-axis
		*/
		inline float getRotation() { return rotation; }
		/**
		 * @return Local rotation of this entity in x-axis
		*/
		inline float getLocalRotation() { return localRotation; }
		/**
		 * @brief Sets local rotation of the entity in x-axis
		 * @param localRotation rotation in x-axis (0-360);
		*/
		inline void setLocalRotation(float localRotation) { this->localRotation = localRotation; }
		/**
		 * @return Local scale of this entity
		*/
		SVector2 getLocalScale() { return localScale; };
		/**
		 * @brief Sets local scale
		 * @param x  x-component of the scale
		 * @param y  y-component of the scale
		*/
		inline void setLocalScale(float x, float y) { localScale.x = x; localScale.y = y; }
		/**
		 * @brief brief Sets local scale
		 * @param scale Scale as a Vector2
		*/
		inline void setLocalScale(SVector2 scale) { localScale.x = scale.x; localScale.y = scale.y; }

		/**
		 * @return Immediate parent of this entity
		*/
		inline MSpatialEntity* getParent() { return parent; }
		/**
		 * @return List of children of the entity. 
		*/
		inline std::vector<MSpatialEntity*>* getChildren() { return children; }

		/**
		 * @brief Adds a child to this entity
		 * @param entity Child to add.
		*/
		void addChild(MSpatialEntity* entity);
		/**
		 * @brief Remove a child from this entity
		 * @param entity Child to remove.
		*/
		void removeChild(MSpatialEntity* entity);

		/**
		 * @brief Recursively searches for a SpatialEntity within this sub-tree
		 * @tparam T type of Entity to return, needs to be child of SpatialEntity.
		 * @param name Name of entity to search for.
		 * @return Reference to SpatialEntity.
		*/
		template<typename T>
		T* find(std::string name) {
			static_assert(std::is_base_of<MSpatialEntity, T>::value, "T must inherit from MSpatialEntity");
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

		virtual void onStart();
		virtual void onUpdate(float deltaTime);
		virtual void onExit();

	protected:
		SVector2 localPosition;
		SVector2 localScale;
		SVector2 position;
		float rotation;
		float localRotation;
		MSpatialEntity* parent = NULL;
		std::vector<MSpatialEntity*>* children = NULL;

		void updatePositions();
		void updateRotations();
		void updateScale();

		void updateChildren(float deltaTime);
	private:
		void setParent(MSpatialEntity* entity) { parent = entity; };
	};
}