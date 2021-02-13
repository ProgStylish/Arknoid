#pragma once
#include "Vec2.h"
#include "Graphics.h"
class Ball {
public:
	Ball(Vec2& position, Vec2& speed);
	void draw(Graphics& gfx) const;
	void move(float dt);
	bool isColliding(Vec2& position, float width, float height);
	void clamp(bool& paddleCooldown);
private:
	static constexpr float radius = 7.0f;
	Vec2 position;
	Vec2 speed;
};