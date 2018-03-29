#pragma once
#include <allegro5\allegro.h>
#include<allegro5\allegro_image.h>

typedef struct
{
	int  range = 511; //range of the coordinates   701px>X>1212px
	ALLEGRO_BITMAP ** walk;
	ALLEGRO_BITMAP ** jump;
	void load (char ** walkAnimation,int size1,int size2, char ** jumpAnimation);
	void unload();
}info;