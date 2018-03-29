#include <vector>

using namespace std;


typedef enum {
	LEFT1, LEFT2, RIGHT1, RIGHT2, JUMP1, JUMP2, TIMER
}evnt;
typedef class Worm;

void dispatchEvent(evnt ev, vector<Worm> worms);

void dispatchEvent(evnt ev, vector<Worm> worms)
{
	switch (ev)
	{
	case LEFT1: worms[0].moveLeft(); break;
	case LEFT2: worms[1].moveLeft(); break;
	case RIGHT1:worms[0].moveRight(); break;
	case RIGHT2:worms[1].moveRight(); break;
	case JUMP1:worms[0].jump(); break;
	case JUMP2:worms[1].jump(); break;
	case TIMER:
		for (Worm& worm : worms)
		{
			worm.update();
			worm.draw();
		}
	}
}

evnt getEvent()