#include "BadGuy.h"
BadGuy::~BadGuy()
{
	al_destroy_bitmap(image);
}
BadGuy::BadGuy()
{
	image = al_create_bitmap(64,64);   
	if(!image) {
		exit(1);
	}

	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	x = 0;
	y = 0;

	al_draw_filled_rectangle(25,10,39,54,al_map_rgb(100, 100, 120));
	al_draw_filled_ellipse(32,32,32,16,al_map_rgb(255, 0, 255));
	al_draw_filled_circle(32,32,4,al_map_rgb(255, 255, 255));
	al_draw_filled_circle(16,32,4,al_map_rgb(120, 255, 255));
	al_draw_filled_circle(48,32,4,al_map_rgb(255, 255, 120));
	boundx = al_get_bitmap_width(image);
	boundy = al_get_bitmap_height(image);
	live = false;

}
void BadGuy::DrawBadGuy()
{


	if(live)
	{
		al_draw_bitmap(image,x,y,0);
	}

}
void BadGuy::StartBadGuy(int WIDTH, int HEIGHT, BadGuy BadGuys[], int cSize, int playerX, int playerY, int playerBoundryX, int playerBoundryY)
{
	bool noCollisions = false;
	int exitCounter = 0;
	if(!live)
	{
		if(rand() % 500 == 0)
		{
			//Keep generating x and y until it doesn't collide with a player or enemy if can't find spot after 10 attempts stops
			while (!noCollisions) {
				if (exitCounter == 10) {
					return;
				}
				randX(WIDTH);
				randY(HEIGHT);

				noCollisions = true;

				for (int j = 0; j < cSize; j++)
				{
					if (BadGuys[j].getLive())
					{
						if (x > (BadGuys[j].getX() - BadGuys[j].getBoundX()) &&
							x < (BadGuys[j].getX() + BadGuys[j].getBoundX()) &&
							y >(BadGuys[j].getY() - BadGuys[j].getBoundY()) &&
							y < (BadGuys[j].getY() + BadGuys[j].getBoundY()))
						{
							noCollisions = false;
						}
					}
				}

				if (x > (playerX - playerBoundryX) &&
					x < (playerX + playerBoundryX) &&
					y >(playerY - playerBoundryY) &&
					y < (playerY + playerBoundryY))
				{
					noCollisions = false;
				}

				exitCounter++;
			}

			live = true;
		}
	}
}

void BadGuy::randX(int WIDTH) {
	do {
		x = rand() % (WIDTH - boundx);
	} while (x < 100);
}

void BadGuy::randY(int HEIGHT) {
	do {
		y = rand() % (HEIGHT - boundy);
	} while (y < 100);
}

