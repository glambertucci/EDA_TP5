#pragma once
#include <allegro5\allegro.h>
#include<allegro5\allegro_image.h>


#define WARMUP 3
#define AIRTIME 36
#define LANDING 43
#define WALKTICKS 45
#define JUMPTICKS 43

typedef struct
{

	const float maxX = 1212;
	const float minX = 701;
	const float minY = 616;
	ALLEGRO_BITMAP * walk[WALKTICKS];
	ALLEGRO_BITMAP * jump[JUMPTICKS];
	void load(char ** walkAnimation, int sizeWalk, char ** jumpAnimation, int sizeJump)
	{
		//Moving 
		for (int i = 0; i < sizeWalk; i++)
		{
			this->walk[i] = al_load_bitmap(walkAnimation[i]); //Loading first walk
		}
		for (int i = 1; i < WARMUP; i++)
		{
			for (int a = 0; a < (sizeWalk - 3); a++)
			{
				walk[sizeWalk*i + a] = walk[(a > 11 ? a - 1 : a)]; //Repeating for full movement
			}
		}
		//Jumping
		for (int i = 0; i < (LANDING); i++)
		{
			if (i < WARMUP)
			{
				jump[i] = al_load_bitmap(jumpAnimation[i]);
			}
			else if (i < AIRTIME)
			{
				jump[i] = jump[2];
			}
			else if (i < LANDING)
			{
				jump[i] = al_load_bitmap(jumpAnimation[i - 33]);
			}
		}
	}
	void unload(int sizeWalk, int sizeJump)
	{
		for (int i = 0; i < sizeJump; i++)
		{
			al_destroy_bitmap(walk[i]);
		}
		for (int i = 0; i < WARMUP; i++)
		{
			al_destroy_bitmap(jump[i]);
		}
		for (int i = AIRTIME; i < LANDING; i++)
		{
			al_destroy_bitmap(jump[i]);
		}
	}
}info;