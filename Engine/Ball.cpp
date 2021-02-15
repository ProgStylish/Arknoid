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
}

void Ball::resetSpeed()
{
	speed.x = xSpeed;
	speed.y = ySpeed;
}

void Ball::paddleCollide(Vec2& brick_position, float width, float height) {
	if (position.y + radius <= brick_position.y + height &&
		position.y + radius >= brick_position.y &&
		position.x >= brick_position.x &&
		position.x <= brick_position.x + width) {
		resetSpeed();
		const float xBrickCollisionPoint = position.x - brick_position.x;
		if (xBrickCollisionPoint - position.x < 3.0f * width / 8.0f) {
			speed.x = xBrickCollisionPoint * ((2.5f * speed.y) / (3.0f * float(width) / 8.0f)) - 3.5f * speed.y;
			speed.y *= -2.0f;
		}
		else if (xBrickCollisionPoint - position.x > 5.0f * width / 8.0f) {
			speed.x = xBrickCollisionPoint * ((3.5f * speed.y) / (3.0f * float(width) / 8.0f)) + (9.5f * speed.y / 3.0f);
			speed.y *= -2.0f;
		}
		else {
			speed.x = 3*speed.y/2;
			speed.y *= -2.5f;
		}
	}
	if (position.x - radius <= brick_position.x + width &&
		position.x - radius >= brick_position.x &&
		position.y >= brick_position.y &&
		position.y <= brick_position.y + height) {
		speed.x *= -1.0f;
	}
	if (position.x + radius < brick_position.x + width &&
		position.x + radius > brick_position.x &&
		position.y >= brick_position.y &&
		position.y <= brick_position.y + height) {
		speed.x *= -1.0f;
	}
	if (position.y - radius <= brick_position.y + height &&
		position.y - radius >= brick_position.y &&
		position.x >= brick_position.x &&
		position.x <= brick_position.x + width) {
		speed.y *= -1.0f;
	}
}

void Ball::brickCollide(Vec2& brick_position, float width, float height) {
	if (position.y + radius <= brick_position.y + height &&
		position.y + radius >= brick_position.y &&
		position.x >= brick_position.x &&
		position.x <= brick_position.x + width) {
		speed.y *= -1.0f;
	}
	 else if (position.y - radius <= brick_position.y + height &&
		position.y - radius >= brick_position.y &&
		position.x >= brick_position.x &&
		position.x <= brick_position.x + width) {
		speed.y *= -1.0f;
	}
	 else if (position.x - radius <= brick_position.x + width &&
		position.x - radius >= brick_position.x &&
		position.y >= brick_position.y &&
		position.y <= brick_position.y + height) {
		speed.x *= -1.0f;
	}
	 else if (position.x + radius < brick_position.x + width &&
		position.x + radius > brick_position.x &&
		position.y >= brick_position.y &&
		position.y <= brick_position.y + height) {
		speed.x *= -1.0f;
	}

	 else if ((position - Vec2(brick_position.x, brick_position.y)).GetLength() <= radius) {
		if (speed.y > 0) {
			if (speed.x < 0) {
				speed.y *= -1.0f;
			}
			else {
				if (((position.x + radius) - brick_position.x) >= ((position.y + radius) - brick_position.y)) {
					speed.y *= -1.0f;
				}
				else {
					speed.x *= -1.0f;
				}
			}
		}
		else {
			speed.x *= -1.0f;
		}
	}
	 else if ((position - Vec2(brick_position.x + width, brick_position.y)).GetLength() <= radius) {
		if (speed.y > 0) {
			if (speed.x > 0) {
				speed.y *= -1.0f;
			}
			else {
				if (((brick_position.x + width) - (position.x - radius)) >= ((position.y + radius) - brick_position.y)) {
					speed.y *= -1.0f;
				}
				else {
					speed.x *= -1.0f;
				}
			}
		}
		else {
			speed.x *= -1.0f;
		}
	}
	else if ((position - Vec2(brick_position.x, brick_position.y + height)).GetLength() <= radius) {
		if (speed.y > 0) {
			speed.x *= -1.0f;
		}
		else {
			if (speed.x < 0) {
				speed.y *= -1.0f;
			}
			else {
				if (((brick_position.y + height) - (position.y - radius)) >= ((position.x + radius) - (brick_position.x))) {
					speed.x *= -1.0f;
				}
				else {
					speed.y *= -1.0f;
				}
			}
		}
	}
	else if ((position - Vec2(brick_position.x + width, brick_position.y + height)).GetLength() <= radius) {
		if (speed.y > 0) {
			speed.x *= -1.0f;
		}
		else {
			if (speed.x < 0) {
				if (((brick_position.y + height) - (position.y - radius)) >= ((brick_position.x + width) - (position.x - radius))) {
					speed.x *= -1.0f;
				}
				else {
					speed.y *= -1.0f;
				}
			}
			else {
				speed.y *= -1.0f;
			}
		}
	}
}

bool Ball::isColliding(Vec2& brick_position, float width, float height)
{
	if ((position - Vec2(brick_position.x, brick_position.y)).GetLength() <= radius) {
		return true;
	}
	if ((position - Vec2(brick_position.x + width, brick_position.y)).GetLength() <= radius) {
		return true;
	}
	if ((position - Vec2(brick_position.x, brick_position.y + height)).GetLength() <= radius) {
		return true;
	}
	if ((position - Vec2(brick_position.x + width, brick_position.y + height)).GetLength() <= radius) {
		return true;
	}
	if (position.y + radius < brick_position.y + height &&
		position.y + radius > brick_position.y &&
		position.x > brick_position.x &&
		position.x < brick_position.x + width) {
		return true;
	}
	if (position.x - radius < brick_position.x + width &&
		position.x - radius > brick_position.x &&
		position.y > brick_position.y &&
		position.y < brick_position.y + height) {
		return true;
	}
	if (position.x + radius < brick_position.x + width &&
		position.x + radius > brick_position.x &&
		position.y > brick_position.y &&
		position.y < brick_position.y + height) {
		return true;
	}
	if (position.y - radius < brick_position.y + height &&
		position.y - radius > brick_position.y &&
		position.x > brick_position.x &&
		position.x < brick_position.x + width) {
		return true;
	}
	return false;
}

void Ball::clamp(bool& paddleCooldown)
{
	if (position.x + radius >= Graphics::ScreenWidth) {
		position.x = Graphics::ScreenWidth - radius;
		speed.x *= -1;
		paddleCooldown = false;
	}
	if (position.x - radius <= 0) {
		position.x = radius;
		speed.x *= -1;
		paddleCooldown = false;
	}
	if (position.y + radius >= Graphics::ScreenHeight) {
		position.y = Graphics::ScreenHeight - radius;
		speed.y *= -1;
		paddleCooldown = false;
	}
	if (position.y - radius <= 0) {
		position.y = radius;
		speed.y *= -1;
		paddleCooldown = false;
	}
}

Vec2 Ball::getPosition() const
{
	return position;
}
