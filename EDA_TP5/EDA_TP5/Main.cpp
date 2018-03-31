#include "allegroClass.h"
#include "EventHandler.h"
#include "bitinit.h"
#include "init_arr.h"


int main() {

	srand(time(NULL));
	char * walkFiles[15];
	char * jumpFiles[10];
	fillJump(jumpFiles);
	fillWalk(walkFiles);
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
