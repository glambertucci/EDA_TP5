#include "Worm.h"
#include <iostream>

using namespace std;
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
		if ((coord.x + 9 <= data->maxX) && (coord.x - 9) >= data->minX)
			this->coord.x += this->direction * 9;
}

void Worm::doJump()
{
	this->ticks++;
	printf("X coord= %f, Y coord = %f\n", coord.x, coord.y); //debug		 /// >3
	if (this->ticks >= 0 && this->ticks < JUMPTICKS)
	{
		if ((coord.x + cos(ALLEGRO_PI / 3.0)*4.5 <= data->maxX) && (coord.x - cos(ALLEGRO_PI / 3.0)*4.5) >= data->minX)
		{
			this->coord.x += this->direction * cos(ALLEGRO_PI / 3.0)*4.5;
			this->ticks++;
		}
		if ((this->coord.y <= this->data->minY) && ((this->coord.y) >= this->data->maxY) && rising)//this->data->minY 1000
		{
			this->coord.y += -sin(ALLEGRO_PI / 3.0)*4.5 - GRAV /2.0;
			if ((int)(coord.y) == (int) (data->minY - 34)) //Delicioso magic numbers
				rising = false;
		}
		else if ((this->coord.y <= this->data->minY))
		{
			this->coord.y += sin(ALLEGRO_PI / 3.0)*4.5 - GRAV / 2.0;
			if ((int)coord.y == (int)this->data->minY)
			{
				rising = true;
				coord.y = data->minY;
				ticks = JUMPTICKS;
			}
		}
//			printf("Ticks value is %d \n", ticks);//Debug
	//	printf("Rising value is %d \n",rising);//debug
	}
	//printf("X coord= %f, Y coord = %f\n", coord.x, coord.y); //debug

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
		al_draw_bitmap(this->data->walk[7], (this->coord).x, (this->coord).y, flag);
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
		cout << "state is " << state << endl << "prev state is " << prev_state << endl;
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
