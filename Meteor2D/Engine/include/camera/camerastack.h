#pragma once
#include <vector>
#include <camera/camera.h>
namespace meteor {
	/**
	 * @brief A Stack maintining all Cameras currently avaialble in scene.
	 * CameraStack sorts all Cameras in ascending order.
	*/
	class CameraStack {
	public:
		/**
		 * @return true if atleast one active camera is present 
		*/
		static bool hasActiveCamera();
		/*
		 * @return Top-most active camera; 
		*/
		static Camera* getActiveCamera();
		/**
		 * @brief Register a camera to the stack 
		*/
		static void registerToStack(Camera* camera);
		/**
		 * @brief Remove a Camera from the stack.
		*/
		static void removeFromStack(Camera* camera);
	private:
		static std::vector<Camera*> cameraStack;
		static Camera* activeCamera;

		static void updateStack();
	};
}