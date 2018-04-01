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

	allegro_c allegro;
	Stage stage;
	info data;
	
	array< char[14], 15> walk = fillWalk("wwalk-F");
	array<char [14], 10> jump = fillJump("wjump-F");

	data.load(walk, jump);
	stage.createWorms(&data);
	stage.loadImages("Scenario.png", "background.png");

	stage.draw();
	al_flip_display();

	Evnt ev;

	while ((ev = getEvent(allegro.getEventQueue())) != QUIT)
	{
		if (ev != NOEVENT)
		{
			dispatchEvent(ev, stage);
			al_flip_display();
		}

	}
	data.unload(15,10);
	return 0;
}