#include "Worm.h"



Worm::Worm()
{
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

void Worm::jump(Direction a)
{
	this->direction = a;
	this->state = JUMP;
}

void Worm::doMove()
{
	this->ticks++;
	if(!(abs(this->ticks - 3)%14))
		if(coord.x + 9 <= data->maxX)
}
