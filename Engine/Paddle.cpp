#include "Paddle.h"

Paddle::Paddle(Vec2& in_position, Vec2& in_speed) :
	position(in_position),
	speed(in_speed)
{
}

void Paddle::move(Keyboard& kbd, float dt) {

	if (kbd.KeyIsPressed('A')) {
		position -= speed * dt;
		if (position.x < 0) {
			position.x = 0;
		}
	}

	if (kbd.KeyIsPressed('D')) {
		position += speed * dt;
		if (position.x + width > Graphics::ScreenWidth) {
			position.x = Graphics::ScreenWidth - width;
		}
	}
}

void Paddle::draw(Graphics& gfx, Color& c) const {
	gfx.DrawPaddle(int(position.x), int(position.y), int(width), int(height));
}
