#pragma once
#include "settings.h"

struct Ball {
	sf::CircleShape shape;
	float speedX, speedY;
};

void ballInit(Ball& ball)
{
	ball.shape.setRadius(BALL_RADIUS);
	ball.shape.setFillColor(BALL_COLOR);
	ball.shape.setPosition(BALL_START_POS);
	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	ball.speedX = arr_speed[index];
	index = rand() % 10;
	ball.speedY = arr_speed[index];
}

void ballUpdate(Ball& ball, const int speedX, const int speedY)
{
	if (ball.shape.getPosition().x <= 0)
	{
		ballInit(ball);
		ball.speedX = -ball.speedX;
	}
	if (ball.shape.getPosition().x >=
		WINDOW_WIDTH - 2 * BALL_RADIUS)
	{
		ballInit(ball);
		ball.speedX = -ball.speedX;
	}

	if (ball.shape.getPosition().y <= 0)
	{
		ball.speedY = -ball.speedY;
	}
	if (ball.shape.getPosition().y >=
		(WINDOW_HEIGHT - 2 * BALL_RADIUS)
		)
		ball.shape.setPosition(BALL_START_POS);
}

void ballDraw(sf::RenderWindow& window, Ball& ball) {
	window.draw(ball.shape);
}
