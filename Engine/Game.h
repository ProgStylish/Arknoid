/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "FrameTimer.h"
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "Border.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void CheckBricksCollision();
	void UpdateModel(float dt);
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	FrameTimer frameTimer;
	static int constexpr bricksAmountHorizontally = 14;
	static int constexpr bricksAmountVertically = 12;
	static int constexpr nBricks = bricksAmountHorizontally * bricksAmountVertically;
	static float constexpr bricketsDistance = 2.0f;
	static float constexpr brickWidth = Graphics::ScreenWidth / 15;
	static float constexpr brickHeight = Graphics::ScreenHeight / 30;
	static float constexpr xStartPoint = (Graphics::ScreenWidth - bricksAmountHorizontally*(brickWidth+bricketsDistance))/2;
	static float constexpr yStartPoint = 0;
	Brick bricks[nBricks];
	Ball ball;
	Paddle paddle;
	Border border;
	/********************************/
	/*  User Variables              */
	/********************************/
};