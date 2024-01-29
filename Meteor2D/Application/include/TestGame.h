#pragma once
#include <meteor.h>

class ATestGame : public meteor::MApplication {
public:
	std::string getName() override;
	void onStart() override;
	void onUpdate(float deltaTime) override;
	void onQuit() override;
private:
	float myTime=0;
	meteor::MSpatialEntity* scp;
	meteor::MSprite2D* sprite;
	meteor::MAnimation* anim;
	meteor::MCamera* gameCamera;
};