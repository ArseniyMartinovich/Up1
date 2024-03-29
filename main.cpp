#include "settings.h"
#include "functions.h"
#include "bat.h"
#include "ball.h"

using namespace sf;
int main()
{
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE
	);
	Bat bat;
	batInit(bat);


	batControl(bat);

	Ball ball;
	ballInit(ball);


	ball.shape.move(speedX, speedY);


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

	while (window.isOpen()) {
		checkEvents(window);
		updateGame(bat);
		checkCollisions();
		drawGame(window, bat, ball);	
	
	}


	return 0;
}
