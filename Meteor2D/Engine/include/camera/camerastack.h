#pragma once
#include <vector>
#include <camera/camera.h>
namespace meteor {
	class CameraStack {
	public:
		static bool hasActiveCamera();
		static Camera* getActiveCamera();
		static void registerToStack(Camera* camera);
		static void removeFromStack(Camera* camera);
	private:
		static std::vector<Camera*> cameraStack;
		static Camera* activeCamera;

		static void updateStack();
	};
}