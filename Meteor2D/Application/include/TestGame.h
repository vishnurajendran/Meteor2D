#pragma once
#include <meteor.h>

class TestGame : public meteor::Application {
public:
	std::string getName() override;
	void onStart() override;
	void onUpdate(float deltaTime) override;
	void onQuit() override;
private:
	float myTime=0;
	meteor::SpatialEntity* scp;
	meteor::Sprite2D* sprite;
	meteor::Animation* anim;
	meteor::Camera* gameCamera;
};