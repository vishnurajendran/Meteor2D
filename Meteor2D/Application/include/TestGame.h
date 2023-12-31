#pragma once
#include <meteor.h>

class TestGame : public meteor::Application {
public:
	std::string getName() override;
	void onStart() override;
	void onUpdate(float deltaTime) override;
	void onQuit() override;
private:
	meteor::Sprite2D* sprite;
	meteor::Camera* gameCamera;
};