#pragma once
struct Vector2 {
public:
	float x = 0;
	float y = 0;
	static float distance(Vector2 other);
	static float cross(Vector2 other);
	static float dot(Vector2 other);
	static Vector2 scale(Vector2 other);
};