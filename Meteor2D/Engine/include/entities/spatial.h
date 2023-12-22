#pragma once
#include<vector>
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
		inline Vector2 getRotation() { return rotation; }
		inline Vector2 getLocalRotation() { return localRotation; }
		inline void setLocalRotation(float x, float y) { localRotation.x = x; localRotation.y = y; }
		inline void setLocalRotation(Vector2 rot) { localRotation.x = rot.x; localRotation.y = rot.y; }

		//local scale
		Vector2 getLocalScale() { return localScale; };
		inline void setLocalScale(float x, float y) { localScale.x = x; localScale.y = y; }
		inline void setLocalScale(Vector2 scale) { localScale.x = scale.x; localScale.y = scale.y; }

		// hierarchy
		inline SpatialEntity* getParent() { return parent; }
		inline std::vector<SpatialEntity*>* getChildren() { return children; }

		void setChild(SpatialEntity* entity);
		void removeChild(SpatialEntity* entity);

		// overrides
		virtual void onStart() override;
		virtual void onUpdate(float deltaTime) override;
		virtual void onExit() override;

	protected:
		Vector2 localPosition;
		Vector2 localRotation;
		Vector2 localScale;
		Vector2 position;
		Vector2 rotation;
		SpatialEntity* parent = NULL;
		std::vector<SpatialEntity*>* children = NULL;

	private:
		void setParent(SpatialEntity* entity) { parent = entity; }
		void updatePositions();
		void updateRotations() {};
		void updateScale() {};
	};
}