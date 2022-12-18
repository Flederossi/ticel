const int d[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
int n;

void mapClear(int (*map)[GS]){
	for (int y = 0; y < GS; y++){
		for (int x = 0; x < GS; x++){
			map[y][x] = 0;
		}
	}
}

void mapRand(int (*map)[GS]){
	for (int y = 0; y < GS; y++){
		for (int x = 0; x < GS; x++){
			map[y][x] = rand() % 2;
		}
	}
}

void mapCopy(int (*mapd)[GS], int (*maps)[GS]){
	for (int y = 0; y < GS; y++){
		for (int x = 0; x < GS; x++){
			mapd[y][x] = maps[y][x];
		}
	}
}

int mapCountN(int x, int y, int map[GS][GS]){
	n = 0;
	for (int i = 0; i < 8; i++){
		if (x + d[i][0] >= 0 && x + d[i][0] < GS && y + d[i][1] >= 0 && y + d[i][1] < GS){
			if (map[y + d[i][1]][x + d[i][0]] == 1){
				n++;
			}
		}
	}
	return n;
}