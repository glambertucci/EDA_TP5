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

	void activate() {
		active = true;
	}
	void deactivate() {
		active = false;
	}
}Ev_t;

class EventHandler {
public:
	
	bool getEvent(ALLEGRO_EVENT_QUEUE *  eq);
	bool isThereEvent();
	void handleEventDispatcher();
private:
	void setEvent1(Evnt ev);
	void setEvent2(Evnt ev);
	void dispatchEvent(Evnt ev, Stage& stage);
	Evnt trasformAllegroEvents(int key);
	bool moveWorms1(int ev);
	bool moveWorms2(int ev);

	array<Ev_t, 2>events;
};

