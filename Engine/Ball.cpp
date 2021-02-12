#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2& in_position, Vec2& in_speed) :
	position(in_position),
	speed(in_speed)
{
}

void Ball::draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(position, gfx);
}

void Ball::move(float dt)
{
	position += speed * dt;
	clamp();
}

boolean Ball::isColliding(Vec2& brick_position, float width, float height)
{
	if (position.x - radius < brick_position.x + width &&
		position.x - radius > brick_position.x &&
		position.y > brick_position.y &&
		position.y < brick_position.y + height) {
		speed.x *= -1;
		return true;
	}
	if (position.x + radius < brick_position.x + width &&
		position.x + radius > brick_position.x &&
		position.y > brick_position.y &&
		position.y < brick_position.y + height) {
		speed.x *= -1;
		return true;
	}
	if (position.y - radius < brick_position.y + height &&
		position.y - radius > brick_position.y &&
		position.x > brick_position.x &&
		position.x < brick_position.x + width) {
		speed.y *= -1;
		return true;
	}
	
	if (position.y + radius < brick_position.y + height &&
		position.y + radius > brick_position.y &&
		position.x > brick_position.x &&
		position.x < brick_position.x + width) {
		speed.y *= -1;
		return true;
	}
	return false;
}

void Ball::clamp()
{
	if (position.x + radius >= Graphics::ScreenWidth) {
		position.x = Graphics::ScreenWidth - radius;
		speed.x *= -1;
	}
	if (position.x - radius <= 0) {
		position.x = radius;
		speed.x *= -1;
	}
	if (position.y + radius >= Graphics::ScreenHeight) {
		position.y = Graphics::ScreenHeight - radius;
		speed.y *= -1;
	}
	if (position.y - radius <= 0) {
		position.y = radius;
		speed.y *= -1;
	}
}
