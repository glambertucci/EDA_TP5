#include <ctype.h>
#include <vector>
#include "EventHandler.h"


using namespace std;
Evnt trasformAllegroEvents(int key);


void dispatchEvent(Evnt ev, vector<Worm> worms)
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

Evnt trasformAllegroEvents(int key) 
{
	Evnt ev = NOEVENT;

	switch (key)
	{
	case ALLEGRO_KEY_A:
		ev = LEFT2;
		break;
	case ALLEGRO_KEY_D:
		ev = RIGHT2;
		break;
	case ALLEGRO_KEY_W:
		ev = JUMP2;
		break;
	case ALLEGRO_KEY_LEFT:
		ev = LEFT1;
		break;
	case ALLEGRO_KEY_RIGHT:
		ev = RIGHT1;
		break;
	case ALLEGRO_KEY_UP:
		ev = JUMP1;
		break;
	}
	return ev;
}

Evnt getEvent(ALLEGRO_EVENT_QUEUE * eq)
{
	ALLEGRO_EVENT ev;
	Evnt retEv = NOEVENT;
	int key = NOEVENT;

	Timer timer();

	al_get_next_event(eq, &ev);

	switch (ev.type)
	{
	case ALLEGRO_EVENT_KEY_DOWN:
		timer.start();
		key = ev.keyboard.keycode;
		break;
	case ALLEGRO_EVENT_KEY_UP:
		timer.stop();
		if (timer.getTime() >= 100)
			retEv = trasformAllegroEvents(key);
		break;
	case ALLEGRO_EVENT_TIMER:
		retEv = TIMER;
		break;
	}
	return retEv;

}