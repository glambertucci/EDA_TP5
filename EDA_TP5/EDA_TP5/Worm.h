#pragma once
#include "bitinit.h"



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
	Worm(info * data);
	~Worm();

	void move(Direction a);
	void jump();

	void draw();
	void update();
private:
	void doMove();		//This functions should not be accesible from outside the object as they are only called from update.
	void doJump();		//To use them ypu should set the state using 'move' and 'jump'
	bool isXValid();

	Direction direction;
	Point coord;
	State prev_state;
	State state;
	int ticks;
	info * data;

	const float gravity = 0.24;
	const float degrees60 = ALLEGRO_PI / 3.0;
	const float speed = 4.5;
};

