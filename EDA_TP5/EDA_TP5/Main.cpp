#include "allegroClass.h"
#include "EventHandler.h"
#include "bitinit.h"





int main() {

	srand(time(NULL));

	allegro_c * allegro = new allegro_c();
	vector<Worm> worms;
	info data;
	Evnt ev;

	data.load(NULL, 3, NULL, 3);
	worms.push_back(&data);
	worms.push_back(&data);
	
	while ((ev = getEvent(allegro->getEventQueue())) != QUIT)
		if (ev != NOEVENT)
			dispatchEvent(ev, worms);


	data.unload(3,3);
	delete allegro;
}