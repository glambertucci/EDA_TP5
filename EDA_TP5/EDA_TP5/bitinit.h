#pragma once
#include <allegro5\allegro.h>
#include<allegro5\allegro_image.h>
#include <array>

using namespace std;


#define WARMUP 3
#define AIRTIME 36
#define LANDING 43
#define WALKTICKS 45 
#define JUMPTICKS 43
#define WALKPICS 15
#define JUMPPICS 10
typedef struct
{

	const float maxX = 1212.0;
	const float minX = 701.0;
	const float minY = 616.0;
	const float maxY = (616 - 33.0);
	array<ALLEGRO_BITMAP *, WALKTICKS> walk;
	array<ALLEGRO_BITMAP *, JUMPTICKS> jump;

	void load( array< char [14], WALKPICS>& walkAnimation, array< char[14], 10>& jumpAnimation)  //Loading the animations
	{
		int sizeWalk = walkAnimation.size();
		//Moving 
		for (int i = 0; i < sizeWalk; i++)
		{
			this->walk[i] = al_load_bitmap(walkAnimation[i]); //Loading first walk
		}
		for (int i = 1; i < 3; i++)
		{								
			for (int a = 0; a < (sizeWalk ); a++)
			{
				walk[sizeWalk*i + a ] = walk[(a > 11 ? a - 1 : a)]; //Repeating for full movement
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