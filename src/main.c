#include <stdio.h>
#include <time.h>
#include <string.h>

#include "config.h"
#include "logger.h"
#include "screen.h"
#include "parser.h"
#include "map.h"
#include "timer.h"

int stat, sim, ela, nc;
int mx, my, ms, ks;
int map[GS][GS], back[GS][GS], init[GS][GS];

int sb[2][9];

char *rs;

void input(){
	ms = screenCheckMouse();
	if (!sim && ms > 0 && ms < 3){
		screenGetMouse(&mx, &my);
		map[(int)(my / (H / GS))][(int)(mx / (W / GS))] = -ms + 2;
	}else if (!sim && ms == 3){
		mapClear(&map);
	}
	ks = screenCheckKey();
	if (ks == 1 && !sim){
		mapCopy(&init, &map);
		sim = 1;
	}else if (ks == 2 && sim){
		mapCopy(&map, &init);
		sim = 0;
	}else if (ks == 3 && !sim){
		mapRand(&map);
		sim = 1;
	}
	if (ks > 0)
		screenSetTitle(sim, rs);
}

void simulate(){
	for (int y = 0; y < GS; y++){
		for (int x = 0; x < GS; x++){
			back[y][x] = 0;
			nc = mapCountN(x, y, map);
			if ((map[y][x] == 1 && sb[0][nc]) || (map[y][x] == 0 && sb[1][nc])){
				back[y][x] = 1;
			}
		}
	}
	mapCopy(&map, &back);
}

void update(){
	screenClear();
	for (int y = 0; y < GS; y++){
		for (int x = 0; x < GS; x++){
			if (map[y][x] == 1){
				screenDraw(x, y);
			}
		}
	}
	screenRender();
}

int main(int argc, char *argv[]){
	loggerInit();
	loggerPushLog(0, "Logger init");
	loggerPushLog(0, "Start ticel");

	if (argc > 1){
		rs = argv[1];
	}else{
		rs = "B3/S23";
	}

	parserParse(rs, &sb);
	loggerPushLog(0, "Parsed the rulestring");

	screenInit(rs);
	loggerPushLog(0, "Screen init");

	stat = 1;
	while (stat){
		timerSetStart();

		stat = screenCheckQuit();
		ela = 0;

		input();
		if (sim){
			simulate();
		}
		update();
		timerAddTicks(ela);
		screenDelay(TICKS - ela);
	}

	screenDestroy();
	loggerPushLog(0, "Screen destroyed");
	loggerPushLog(0, "Exit ticel");
	return 0;
}