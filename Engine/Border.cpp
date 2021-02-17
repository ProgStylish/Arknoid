#include "Border.h"

Border::Border(Vec2& in_position, float in_width, float in_height) :
	position(in_position),
	width(in_width),
	height(in_height)
{
}

void Border::draw(Graphics& gfx) const
{
	drawLeftBorder(gfx);
	drawRightBorder(gfx);
	drawUpperBorder(gfx);
	drawBottomBorder(gfx);
}

void Border::drawUpperBorder(Graphics& gfx) const
{
	const int inBorderWidth = 10;
	const int inBorderHeight = 10;
	gfx.DrawRect(position.x, position.y, position.x + width, position.y + inBorderHeight, Color(1, 46, 200));
	gfx.DrawRect(position.x, position.y + inBorderHeight, position.x + width, position.y + inBorderHeight * 2, Color(0, 37, 170));
	gfx.DrawTriangle(position.x, position.y,
		position.x, position.y + inBorderHeight*2,
		position.x + inBorderWidth*2, position.y + inBorderHeight*2, Color(10, 58, 236));
	gfx.DrawTriangle(position.x + inBorderWidth, position.y + inBorderHeight,
		position.x + inBorderWidth, position.y + inBorderHeight*2,
		position.x + inBorderWidth*2, position.y + inBorderHeight * 2, Color(0, 27, 135));
	gfx.DrawTriangle(position.x + width , position.y + inBorderHeight*2,
		position.x + width - inBorderWidth * 2, position.y + inBorderHeight*2,
		position.x + width, position.y, Color(0, 25, 130));
	gfx.DrawTriangle(position.x + width - inBorderWidth, position.y + inBorderHeight,
		position.x + width - inBorderWidth, position.y + inBorderHeight*2,
		position.x + width - inBorderWidth*2, position.y + inBorderHeight*2, Color(10, 58, 232));

}

void Border::drawBottomBorder(Graphics& gfx) const
{
	const int inBorderWidth = 10;
	const int inBorderHeight = 10;
	gfx.DrawRect(position.x, Graphics::ScreenHeight - inBorderHeight, position.x + width, Graphics::ScreenHeight, Color(0,38,171));
	gfx.DrawRect(position.x, Graphics::ScreenHeight - inBorderHeight*2, position.x + width, Graphics::ScreenHeight - inBorderHeight, Color(1,47,208));
	gfx.DrawTriangle(position.x, Graphics::ScreenHeight,
		position.x, Graphics::ScreenHeight - inBorderHeight*2,
		position.x + inBorderWidth * 2, Graphics::ScreenHeight - inBorderHeight * 2, Color(10, 58, 236));
	gfx.DrawTriangle(position.x + inBorderWidth, Graphics::ScreenHeight - inBorderHeight,
		position.x + inBorderWidth, Graphics::ScreenHeight - inBorderHeight*2,
		position.x + inBorderWidth*2, Graphics::ScreenHeight - inBorderHeight * 2, Color(0, 27, 135));
	gfx.DrawTriangle(width + position.x, Graphics::ScreenHeight,
		width + position.x - inBorderWidth*2, Graphics::ScreenHeight - inBorderHeight*2,
		width + position.x, Graphics::ScreenHeight - inBorderHeight * 2, Color(0, 27, 135));
	gfx.DrawTriangle(width + position.x - inBorderWidth, Graphics::ScreenHeight - inBorderHeight*2,
		width + position.x - inBorderWidth * 2, Graphics::ScreenHeight - inBorderHeight*2,
		width + position.x - inBorderWidth, Graphics::ScreenHeight - inBorderHeight, Color(10, 58, 232));

}

void Border::drawRightBorder(Graphics& gfx) const
{
	const int inBorderWidth = 10;
	const int inBorderHeight = 10;
	gfx.DrawRect(position.x + width - inBorderWidth*2, position.y, position.x + width - inBorderWidth, Graphics::ScreenHeight, Color(10, 58, 232));
	gfx.DrawRect(position.x + width - inBorderWidth, position.y, position.x + width, Graphics::ScreenHeight, Color(0, 25, 130));
}

void Border::drawLeftBorder(Graphics& gfx) const
{
	const int inBorderWidth = 10;
	const int inBorderHeight = 10;
	gfx.DrawRect(position.x, position.y, position.x + inBorderWidth, Graphics::ScreenHeight, Color(10, 58, 236));
	gfx.DrawRect(position.x + inBorderWidth, position.y, position.x + inBorderWidth*2, Graphics::ScreenHeight, Color(0, 27, 135));
}

float Border::getWidth() const
{
	return width;
}

float Border::getHeight() const
{
	return height;
}
