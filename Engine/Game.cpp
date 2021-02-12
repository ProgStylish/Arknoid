/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(Graphics::ScreenHeight / 2, Graphics::ScreenHeight / 2), Vec2(300.0f, 300.0f))
{
	int k = 0 ;
	for (int i = 0; i < bricksAmountHorizontally; i++) {
		for (int j = 10; j < bricksAmountVertically + 10; j++) {
			bricks[k] = Brick(Vec2(i*brickWidth, j*brickHeight));
			k++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float const dt = frameTimer.Mark();

	ball.move(dt);
}

void Game::ComposeFrame()
{
	for (Brick& b : bricks) {
		if (!b.destroyed) {
			b.draw(gfx, Color(Colors::Green));
		}
	}
	for (Brick& b : bricks) {
		if (!b.destroyed) {
			b.destroyed = ball.isColliding(b.position, b.width, b.height);
			if (b.destroyed) {
				break;
			}
		}
	}
	ball.draw(gfx);
}
