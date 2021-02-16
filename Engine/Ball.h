#pragma once
#include "Vec2.h"
#include "Graphics.h"
class Ball {
public:
	Ball(Vec2& position, Vec2& speed);
	void draw(Graphics& gfx) const;
	void move(float dt);
	void resetSpeed();
	void paddleCollide(Vec2& brick_position, float width, float height);
	void brickCollide(Vec2& brick_position, float width, float height);
	bool isColliding(Vec2& position, float width, float height);
	void clamp(bool& paddleCooldown);
	Vec2 getPosition() const;
private:
	static constexpr float radius = 7.0f;
	Vec2 position;
	Vec2 speed;
	float const xSpeed = 180.0f;
	float const ySpeed = 180.0;
};