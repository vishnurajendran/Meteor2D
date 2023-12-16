#pragma once
#include<application/Application.h>
class TestGame : public Application {
public:
	std::string getName() override;
	void onStart() override;
	void onUpdate(float deltaTime) override;
	void onQuit() override;
};