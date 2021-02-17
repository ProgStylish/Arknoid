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
#include <cmath>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(Graphics::ScreenWidth / 2, Graphics::ScreenHeight - Graphics::ScreenHeight / 10), Vec2(100.0f, 100.0f)),
	paddle(Vec2(Graphics::ScreenWidth / 2, Graphics::ScreenHeight - Graphics::ScreenHeight / 10),
		Vec2(350.0f, 0)),
	border(Vec2(Graphics::ScreenWidth / 8, 0), 4 * Graphics::ScreenWidth / 5, Graphics::ScreenHeight)
{
	int k = 0;
	for (int i = 0; i < bricksAmountHorizontally; i++) {
		for (int j = 2; j < bricksAmountVertically + 2; j++) {
			bricks[k] = Brick(Vec2(xStartPoint + i * (brickWidth + bricketsDistance), j * (brickHeight + bricketsDistance)));
			if (i % 2 == 0) {
				bricks[k].destroyed = true;
			}
			k++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsedTime = frameTimer.Mark();
	while (elapsedTime > 0.0f) {
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	ball.move(dt);
	ball.clamp(paddle.cooldown);
	paddle.move(wnd.kbd, dt);
	if (!paddle.cooldown) {
		if (paddle.cooldown = ball.isColliding(paddle.position, paddle.width, paddle.height)) {
			ball.paddleCollide(paddle.position, paddle.width, paddle.height);
		}
	}
	CheckBricksCollision();
}

void Game::ComposeFrame()
{
	for (Brick& b : bricks) {
		if (!b.destroyed) {
			b.draw(gfx, Color(Colors::Green));
		}
	}
	ball.draw(gfx);
	paddle.draw(gfx, Color(Colors::Red));
	border.draw(gfx);
}

void Game::CheckBricksCollision() {
	int index = 0;
	bool collisionHappened = false;
	for (int i = 0; i < nBricks; i++) {
		if (!bricks[i].destroyed) {
			float bestDistance = 10000000.0f;
			float currentDistance;
			if (ball.isColliding(bricks[i].position, bricks[i].width, bricks[i].height)) {
				currentDistance = (ball.getPosition() - bricks[i].getCenter()).GetLengthSq();
				if (currentDistance < bestDistance) {
					bestDistance = currentDistance;
					index = i;
				}
				collisionHappened = true;
				paddle.cooldown = false;
			}
		}
	}

	if (collisionHappened) {
		ball.brickCollide(bricks[index].position, bricks[index].width, bricks[index].height);
		bricks[index].destroyed = true;
	}
}
