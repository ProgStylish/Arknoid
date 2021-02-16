#pragma once
#include "Vec2.h"
#include "Graphics.h"
class Border {
public:
	Border(Vec2& position, float width, float height);
	float getWidth() const;
	float getHeight() const;
	void draw(Graphics& gfx);
private:
	Vec2& position;
	float const width;
	float const height;
};