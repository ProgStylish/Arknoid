#include "Brick.h"

Brick::Brick(Vec2& in_position)
{
	position = in_position;
}

Vec2 Brick::getCenter() const
{
	return Vec2(position.x + width / 2, position.y + height / 2);
}

void Brick::draw(Graphics& gfx, Color& c) const
{
	gfx.DrawRect(int(position.x) + 1, int(position.y) + 1,
		int(position.x + width) - 1, int(position.y + height) - 1, c);
}
