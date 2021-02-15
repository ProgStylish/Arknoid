#pragma once
#include "Vec2.h"
#include "Keyboard.h"
#include "Graphics.h"
#include "Colors.h"
class Paddle {
private: 
public:
	Paddle(Vec2& posiiton, Vec2& speed);
	void move(Keyboard& kbd, float dt);
	void draw(Graphics& gfx, Color&) const;
	static constexpr float width = Graphics::ScreenWidth / 8;
	static constexpr float height = Graphics::ScreenHeight / 25;
	Vec2 position;
	Vec2 speed;
	bool cooldown = false;
};