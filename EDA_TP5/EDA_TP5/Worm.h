#pragma once
#include "bitinit.h"
#include <math.h>

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
	Worm();
	~Worm();

	Point getCoord();

	void move(Direction a);
	void jump(Direction a);
	void doMove();
	void doJump();

	void draw();
	void update();
private:
	Direction direction;
	Point coord;
	State state;
	int ticks;
	info * data;
};

