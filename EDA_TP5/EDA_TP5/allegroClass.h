#pragma once
#include <allegro5/allegro5.h> 
#include <allegro5/allegro_color.h> 
#include <allegro5/allegro_primitives.h> 
#include <allegro5/allegro_image.h> 
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

#define FPS 50
#define SCREEN_W 1920 
#define SCREEN_H 696
class allegro_c
{
public:
	allegro_c();
	~allegro_c();
	ALLEGRO_EVENT_QUEUE * getEventQueue();
	bool load_music(char * music_file);
	ALLEGRO_BITMAP * getStage();
	ALLEGRO_BITMAP * getBackground();
	ALLEGRO_TIMER * getTimer();
private:
	ALLEGRO_DISPLAY * display;
	ALLEGRO_EVENT_QUEUE * ev_queue;
	ALLEGRO_SAMPLE * music;
	ALLEGRO_BITMAP * background;
	ALLEGRO_BITMAP * stage;
	ALLEGRO_TIMER * timer;
};