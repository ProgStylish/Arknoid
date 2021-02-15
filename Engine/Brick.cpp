#include "Brick.h"

Brick::Brick(Vec2& in_position) :
	position(in_position)
{
}

Vec2 Brick::getCenter() const
{
	return Vec2(position.x + width / 2, position.y + height / 2);
}

void Brick::draw(Graphics& gfx, Color& c) const
{
	gfx.DrawRect(int(position.x), int(position.y),
		int(position.x + width), int(position.y + height), c);
}
