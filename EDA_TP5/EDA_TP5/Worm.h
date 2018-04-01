#pragma once
#include "bitinit.h"
#include <math.h>
#define GRAV 0.24

typedef struct {
	float x, y;
}Point;
 
typedef enum Direction{
	LEFT = -1, NONE = 0, RIGHT = 1
};

typedef enum State{
	STILL, MOVE, JUMP
};

class Worm
{
public:
	Worm( info * data);
	~Worm();

	Point getCoord();

	void move(Direction a);
	void jump();
	void doMove();
	void doJump();

	void draw();
	void update();
private:
	bool rising = true;
	Direction direction;
	Point coord;
	State state;
	int ticks;
	info * data;
};

