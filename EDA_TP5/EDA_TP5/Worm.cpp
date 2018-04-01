#include "Worm.h"
#include <iostream>


Worm::Worm(info * data_)
{
	this->data = data_;
	this->coord.x = this->data->minX + (rand() % (int)(this->data->maxX - this->data->minX)); // Hay que restarle el ancho del strpite
	this->coord.y = this->data->minY; // Hay que restarle la altura del sprite
	this->direction = RIGHT;
	this->state = STILL;
	this->ticks = 0;
}


Worm::~Worm()
{
}

Point Worm::getCoord()
{
	return this->coord;
}

void Worm::move(Direction a)
{
	this->direction = a;
	this->state = MOVE;
}

void Worm::jump()
{
	this->state = JUMP;
}

void Worm::doMove()
{
	this->ticks++;
	if (!(abs(this->ticks - 3) % 14))
		if ((coord.x + 9 <= data->maxX) && (coord.x - 9) >= data->minX)
			this->coord.x += this->direction * 9;
//	printf("X coord= %f, Y coord = %f\n", coord.x, coord.y); //debug
}

void Worm::doJump()
{
	this->ticks++;

	if (this->ticks >= 3 && this->ticks <= 33 + 3)
	{
		if ((coord.x + cos(ALLEGRO_PI/3.0)*4.5 <= data->maxX) && (coord.x - cos(ALLEGRO_PI / 3.0)*4.5) >= data->minX)
			this->coord.x += this->direction * cos(ALLEGRO_PI / 3.0)*4.5;
		if (this->coord.y <= this->data->minY)
			this->coord.y += this->direction * sin(ALLEGRO_PI / 3.0)*4.5 - GRAV /2.0;
	}
}

void Worm::draw()
{
	switch (this->state)
	{
	case MOVE:
		//for (ALLEGRO_BITMAP * bitmap : this->data->walk)
		//{
			al_draw_bitmap(this->data->walk[this->ticks -1], this->coord.x, this->coord.y, (this->direction == RIGHT ? ALLEGRO_FLIP_HORIZONTAL : 0));
		//}
		break;
	case JUMP:
		//for (ALLEGRO_BITMAP * bitmap : this->data->jump)
		//{
			al_draw_bitmap(this->data->jump[this->ticks - 1], this->coord.x, this->coord.y, (this->direction == RIGHT ? ALLEGRO_FLIP_HORIZONTAL : 0));
		//}
		break;
	case STILL:
		al_draw_bitmap(data->walk[7], (this->coord).x, (this->coord).y,((this->direction) == RIGHT ? ALLEGRO_FLIP_HORIZONTAL : 0));

		break;
	}


}

void Worm::update()
{
	switch (this->state)
	{
	case MOVE: 
		if (this->ticks <= WALKTICKS)
			this->doMove();
		else
			this->state = STILL;
		break;
	case JUMP:
		if (this->ticks <= JUMPTICKS)
			this->doJump();
		else
			this->state = STILL;
	case STILL:
		break;
	}
}
