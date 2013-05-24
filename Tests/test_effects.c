#include <acknex.h>
#include <default.c>

#include "..\\Source\\effects.h"

TEXT* txtHeadline = {
	pos_x = 10;
	pos_y = 10;
	string(
		"1 - Fountain",
		"2 - Dense Smoke",
		"3 - Star rain",
		"4 - Fire place"
	);
	flags = SHOW | OUTLINE;
	font = "Arial#24";
}

void main() {
	level_load("..\\Ressources\\Terrains\\small.hmp");
	random_seed(0);
	vec_set(camera.x, vector(-150, 0, 50));
	while(1) {
	
		// Press 1 for fountain
		if (key_1) {
			vec_set(camera.x, vector(-150, 100, 50));
			effect(pFountain,maxv(1,40*time_step),vector(0,100,0),vector(0,0,5));
		}
		
		// Press 2 for smoke
		if (key_2) {
			vec_set(camera.x, vector(-150, -100, 50));
			effect(pDenseSmoke,maxv(1,10*time_step),vector(0,-100,0),vector(0,0,3));
		}

		// Press 3 for star rain
		if (key_3) {
			vec_set(camera.x, vector(50, 100, 50));
			effect(pStars,maxv(1,10*time_step),vector(200,100,100),vector(2-random(4),2-random(4),3));
		}

		// Press 4 for fire place
		if (key_4) {
			vec_set(camera.x, vector(50, -100, 50));
			effect(pFlame,maxv(1,20*time_frame),vector(200,-100,0),vector(0,0,3));
			effect(pSmokeFlames,maxv(1,20*time_frame),vector(200,-100,5),vector(0,0,3));
		}
		
		// Press 5 for rain
		if (key_5) {
			effect(pRain,maxv(30,10*time_step),vector(camera.x, camera.y, camera.z + 200),nullvector);
		}
		
		// Press 6 for snow
		if (key_6) {
			effect(pSnow,maxv(30,10*time_step),vector(camera.x, camera.y, camera.z + 200),nullvector);
		}

		wait(1);
	}
}