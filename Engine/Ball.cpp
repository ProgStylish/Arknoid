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
