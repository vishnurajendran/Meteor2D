#pragma once
#include <meteor.h>
class TestGame : public Application {
public:
	std::string getName() override;
	void onStart() override;
	void onUpdate(float deltaTime) override;
	void onQuit() override;
private:
	Sprite2D* sprite;
};