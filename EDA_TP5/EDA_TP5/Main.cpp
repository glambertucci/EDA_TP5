#include "allegroClass.h"
#include "EventHandler.h"
#include "bitinit.h"
#include "init_arr.h"
#include <iostream> //DEBUG
using namespace std;

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
	al_draw_bitmap((allegro->getBackground()),0,0,0);
	al_draw_bitmap(allegro->getStage(),0,0,0);
	al_flip_display();
	al_start_timer(allegro->getTimer());
	data.load(walkFiles, 15, jumpFiles, 10);
	worms.push_back(&data);
	worms.push_back(&data);
	
	while ((ev = getEvent(allegro->getEventQueue())) != QUIT)
	{
		if (ev != NOEVENT)
		{
			dispatchEvent(ev, worms);
			al_flip_display();
		}

	}
	cout << "sali" << endl;// debug
	data.unload(3,3);
	delete allegro;
}
