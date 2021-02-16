#include "Border.h"

Border::Border(Vec2& in_position, float in_width, float in_height):
    position(in_position),
    width(in_width),
    height(in_height)
{
}

void Border::draw(Graphics& gfx)
{

}

float Border::getWidth() const
{
    return width;
}

float Border::getHeight() const
{
    return height;
}
