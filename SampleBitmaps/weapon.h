#ifndef WEAPONH
#define WEAPONH
#include "BadGuy.h"
#include "player.h"
class weapon
{
public:
	weapon();
	~weapon();
	void Drawweapon();
	void Fireweapon(player &Player);
	void Updateweapon(int WIDTH, int HEIGHT);
	void Collideweapon(BadGuy BadGuys[], int cSize);
	bool getLive() { return live; }
private:
	int x;
	int y;
	int boundx;
	int boundy;
	bool live;
	int speed;
	float angle;
	int direction;
	ALLEGRO_BITMAP *image;
};
#endif
