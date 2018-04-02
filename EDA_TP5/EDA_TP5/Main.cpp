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
	EventHandler eventHandler;
	Stage stage;
	info data;
	
	array< char[14], WALKPICS> walk = fillWalk("wwalk-F",".png");
	array<char [14], JUMPPICS> jump = fillJump("wjump-F",".png");

	data.load(walk, jump);
	stage.createWorms(&data);
	stage.loadImages("Scenario.png", "background.png");
	allegro.load_music( "master_race.wav");
	allegro.play_music();
	
	
	while (eventHandler.getEvent(allegro.getEventQueue()))
	{
		if (eventHandler.isThereEvent())
		{
			eventHandler.handleEventDispatcher(stage);
			allegro.updateDisplay();
		}

	}
	data.unload(WALKPICS, JUMPPICS);
	return 0;
}