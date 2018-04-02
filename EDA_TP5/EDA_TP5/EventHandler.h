#include <allegro5\allegro.h>
#include <vector>
#include "Timer.h"
#include "Stage.h"

using namespace std;



typedef enum Evnt {
	NOEVENT, LEFT1, LEFT2, RIGHT1, RIGHT2, JUMP1, JUMP2, TIMER, QUIT
};

typedef struct {
	Evnt Event;
	Timer * time;
	bool active;
	int keycode;

	void activate() {
		active = true;
	}
	void deactivate() {
		active = false;
		Event = NOEVENT;
	}
}Ev_t;

class EventHandler {
public:
	EventHandler();
	
	bool getEvent(ALLEGRO_EVENT_QUEUE *  eq);
	bool isThereEvent();
	void handleEventDispatcher(Stage& stage);
private:

	void setEvent(Evnt ev, int worm);
	void dispatchEvent(Evnt ev, Stage& stage);
	bool moveWorm(int ev, int worm);
	bool moveWorm1(int ev);
	bool moveWorm2(int ev);

	array<Ev_t, 3>events;
};

