#pragma once
#include "Vec2.h"
#include "Colors.h"
#include "Graphics.h"
class Brick {
public:
	Brick() = default;
	Brick(Vec2& position);
	Vec2 getCenter() const;
	void draw(Graphics& gfx, Color& c) const;
	bool destroyed = false;
	float width = Graphics::ScreenWidth / 15;
	float height = Graphics::ScreenHeight / 30;
	Vec2 position;
};