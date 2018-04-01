#include "allegroClass.h"
#include "EventHandler.h"
#include "bitinit.h"
#include "init_arr.h"
#include "Stage.h"
#include <array>
#include <iostream> //DEBUG
using namespace std;

int main() {

	srand(time(NULL));
	array<char *, 15> walkFiles;
	array<char *, 10> jumpFiles;

	fillJump(jumpFiles);
	fillWalk(walkFiles);


	allegro_c allegro;
	Stage stage;
	info data;

	data.load(walkFiles, jumpFiles);
	stage.createWorms(&data);
	stage.loadImages("Scenario.png", "background.png");

	stage.draw();
	al_flip_display();

	Evnt ev;
	while ((ev = getEvent(allegro.getEventQueue())) != QUIT)
	{
		if (ev != NOEVENT)
		{
			dispatchEvent(ev, stage.worms);
			al_flip_display();
		}

	}
	//cout << "sali" << endl;// debug
	data.unload(15,10);
	return 0;
}
