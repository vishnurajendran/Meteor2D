#pragma once
#include <vector>
#include <camera/camera.h>
namespace meteor {
	/**
	 * @brief A Stack maintining all Cameras currently avaialble in scene.
	 * CameraStack sorts all Cameras in ascending order.
	*/
	class MCameraStack : public MEntity {
	public:
		/**
		 * @return true if atleast one active camera is present 
		*/
		static bool hasActiveCamera();
		/*
		 * @return Top-most active camera; 
		*/
		static MCamera* getActiveCamera();
		/**
		 * @brief Register a camera to the stack 
		*/
		static void registerToStack(MCamera* camera);
		/**
		 * @brief Remove a Camera from the stack.
		*/
		static void removeFromStack(MCamera* camera);
	private:
		static std::vector<MCamera*> cameraStack;
		static MCamera* activeCamera;

		static void updateStack();
	};
}