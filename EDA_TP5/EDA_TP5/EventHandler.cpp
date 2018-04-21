#include <ctype.h>
#include <vector>
#include "EventHandler.h"
#include <iostream>

using namespace std;
Evnt trasformAllegroEvents(int key);


void EventHandler::dispatchEvent(Evnt ev, Stage& stage, int wormID = 0)
{
	switch (ev)
	{
	case LEFT_EV: if (stage.worms[wormID].state == STILL) stage.worms[wormID].move(LEFT); break;
	case RIGHT_EV:if (stage.worms[wormID].state == STILL)stage.worms[wormID].move(RIGHT); break;
	case JUMP_EV:if (stage.worms[wormID].state == STILL)stage.worms[wormID].jump(); break;
	case FLIP_LEFT_EV: if (stage.worms[wormID].state == STILL) stage.worms[wormID].flipLeft(); break;
	case FLIP_RIGHT_EV: if (stage.worms[wormID].state == STILL) stage.worms[wormID].flipRight(); break;
	case TIMER_EV:
		stage.draw();
		for (Worm& worm : stage.worms)
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
	case ALLEGRO_KEY_LEFT:
	case ALLEGRO_KEY_A:
		ev = LEFT_EV;
		break;
	case ALLEGRO_KEY_RIGHT:
	case ALLEGRO_KEY_D:
		ev = RIGHT_EV;
		break;
	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_W:
		ev = JUMP_EV;
		break;
	case ALLEGRO_KEY_ESCAPE:
		ev = QUIT_EV;
		break;
	}
	return ev;
}

EventHandler::EventHandler()
{
	for (Ev_t& ev : events)
	{
		ev.deactivate();
		ev.time = NULL;
	}
}

using namespace std;

bool EventHandler::getEvent(ALLEGRO_EVENT_QUEUE * eq)
{
	ALLEGRO_EVENT ev;
	bool quit = false;

	al_get_next_event(eq, &ev);


	switch (ev.type)
	{
	case ALLEGRO_EVENT_KEY_DOWN:

		if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			quit = true;
		else
			for (int i = 0; i < 2; ++i)			
				if (!this->events[i].active && moveWorm(ev.keyboard.keycode, i) && !this->events[i].timerExist())
					setEvent(trasformAllegroEvents(ev.keyboard.keycode), i);

		break;
	case ALLEGRO_EVENT_KEY_UP:

		for (int i = 0; i < 2; ++i)
			if (this->events[i].timerExist() && this->events[i].Event == trasformAllegroEvents(ev.keyboard.keycode)) {
				if (!this->events[i].timerGreaterThan(100))
				{
					if (trasformAllegroEvents(ev.keyboard.keycode) == RIGHT_EV) {
						this->events[i].Event = FLIP_RIGHT_EV;
						this->events[i].activate();
					}
					else if (trasformAllegroEvents(ev.keyboard.keycode) == LEFT_EV) {
						this->events[i].Event = FLIP_LEFT_EV;
						this->events[i].activate();
					}
					
				}
			}
					
		break;
	case ALLEGRO_EVENT_TIMER:
		this->setEvent(TIMER_EV, 2);
		this->events[2].activate();


		for (int i = 0; i < 2; ++i)
			if (!this->events[i].active && this->events[i].timerExist())
			{
				this->events[i].time->stop();
				float time_ = this->events[i].time->getTime();
				if ( time_ >= 100)
				{
					this->events[i].activate();
					this->events[i].time->start();
				}
				else if (time_ < 100)		// Aca hay que ver bien por que da cancer
				{ 
					bool a = moveWorm(ev.keyboard.keycode,i);
					if (a && !this->events[i].keyPressed)
					{
						//this->events[i].Event = FLIP_EV;
						//this->events[i].activate();
						//this->events[i].time->start();
						//this->events[i].keyPressed = true;
					}
				}
			}


		
		break;
	case ALLEGRO_EVENT_DISPLAY_CLOSE:
		quit = true;
		break;
	}

	if (quit)
		for (int i = 0; i < 2; i++)
			if (this->events[i].timerExist())
				this->events[i].killTimer();
	
	return !quit;

}

bool EventHandler::isThereEvent()
{
	return this->events[0].active || this->events[1].active || this->events[2].active;
}

void EventHandler::handleEventDispatcher(Stage& stage)
{
		for (int i =0 ; i <3 ; i++)
		{
			if (this->events[i].active)
			{
				dispatchEvent(this->events[i].Event, stage,i);
				this->events[i].deactivate();
			}
		}
}

void EventHandler::setEvent(Evnt ev, int worm)
{

	this->events[worm].Event = ev;

	if (ev != TIMER_EV)
		this->events[worm].newTimer();
}

bool EventHandler::moveWorm(int ev, int worm)
{
	bool retValue = false;

	switch (worm)
	{
	case 0: retValue = moveWorm1(ev);
		break;
	case 1: retValue = moveWorm2(ev);
		break;
	}
	return retValue;
}

bool EventHandler::moveWorm1(int ev)
{
	return ((ev == ALLEGRO_KEY_LEFT) || (ev == ALLEGRO_KEY_RIGHT) || (ev == ALLEGRO_KEY_UP));
}

bool EventHandler::moveWorm2(int ev)
{
	return ((ev == ALLEGRO_KEY_W) || (ev == ALLEGRO_KEY_A) || (ev == ALLEGRO_KEY_D));
}
