#include "Worm.h"
#include <iostream>

using namespace std;
Worm::Worm(info * data_)
{
	this->data = data_;
	this->coord.x = this->data->minX + (rand() % (int)(this->data->maxX - this->data->minX - al_get_bitmap_width(this->data->walk[0]))) ; 
	this->coord.y = this->data->minY; 
	this->direction = RIGHT;
	this->state = STILL;
	this->prev_state = STILL;
	this->ticks = 0;
}


Worm::~Worm()
{
	
}

void Worm::move(Direction a)
{
	if (prev_state != JUMP)
	{
	this->direction = a;
	prev_state = state;
	this->state = MOVE;
	}
}

void Worm::jump()
{
	if (prev_state != MOVE )
	{
		prev_state = state;
		this->state = JUMP;
	}
}

void Worm::doMove()
{
	this->ticks++;
	if (!(abs(this->ticks - 3) % 14))
		if (isXValid())
			this->coord.x += this->direction * 9;
}

void Worm::doJump()
{
	this->ticks++;
	if (this->ticks >= 0 && this->ticks < JUMPTICKS)
	{
		if (ticks == 1)
			y0 = coord.y;

		if (isXValid())
		{
			this->coord.x += this->direction * cos(ALLEGRO_PI / 3.0)*4.5;
		}
		if ((this->coord.y <= this->data->minY))
		{
			coord.y =( y0 - 4.5 * ticks *sin(ALLEGRO_PI / 3.0) + GRAV * ticks*ticks /2);
		}
		if (ticks == JUMPTICKS - 1)
			coord.y = y0;
	
	}

}

bool Worm::isXValid()
{
	bool retValue = false;

	if ((this->direction == LEFT) && ((coord.x + 9) > data->minX))
		retValue = true;
	else if ((this->direction == RIGHT) && (coord.x + 49< data->maxX))
		retValue = true;

	return retValue;
}

void Worm::draw()
{
	int flag = (this->direction == RIGHT ? ALLEGRO_FLIP_HORIZONTAL : 0);
	switch (this->state)
	{
	case MOVE:
			al_draw_bitmap(this->data->walk[this->ticks -1], this->coord.x, this->coord.y,flag );
		break;
	case JUMP:
			al_draw_bitmap(this->data->jump[this->ticks - 1], this->coord.x, this->coord.y, flag);
		break;
	case STILL:
		al_draw_bitmap(this->data->walk[3], (this->coord).x, (this->coord).y, flag);
		break;
	}


}

void Worm::update()
{

	switch (this->state)
	{
		
	case MOVE: 
		if (prev_state != JUMP)
		{
			if (this->ticks < WALKTICKS)
			{
				this->doMove();
				prev_state = MOVE;
			}
			else
			{
				this->state = STILL;
				prev_state = STILL;
				this->ticks = 0;
			}

		}
		
		break;
	case JUMP:
		if (prev_state != MOVE)
		{
			if (this->ticks < JUMPTICKS)
			{
				this->doJump();
				prev_state = JUMP;
			}
			else
			{
				this->state = STILL;
				prev_state = STILL;
				this->ticks = 0;
			}
		}
		break;
	case STILL:
		this->ticks = 0;
		break;
	}
}
