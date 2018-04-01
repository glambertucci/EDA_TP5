#include "allegroClass.h"
#include "EventHandler.h"
#include "bitinit.h"
#include "init_arr.h"
#include "Stage.h"
#include <array>

using namespace std;

int main() {

	srand(time(NULL));

	allegro_c allegro;
	Stage stage;
	info data;
	
	array< char[14], 15> walk = fillWalk("wwalk-F",".png");
	array<char [14], 10> jump = fillJump("wjump-F",".png");

	data.load(walk, jump);
	stage.createWorms(&data);
	stage.loadImages("Scenario.png", "background.png");
	allegro.load_music( "master_race.wav");
	allegro.play_music();
	
	Evnt ev;

	while ((ev = getEvent(allegro.getEventQueue())) != QUIT)
	{
		if (ev != NOEVENT)
		{
			dispatchEvent(ev, stage);
			allegro.updateDisplay();
		}

	}
	data.unload(15,10);
	return 0;
}