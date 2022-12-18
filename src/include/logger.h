const char *types[] = {"INFO", "WARNING", "ERROR"};

FILE *fp;
int *ntime;

time_t t;
struct tm *currtime;
int h, m, s;
int ret[3];

static int *getTime(){
	t = time(NULL);
	currtime = localtime(&t);
	ret[0] = currtime->tm_hour;
	ret[1] = currtime->tm_min;
	ret[2] = currtime->tm_sec;
	return ret;
}

void loggerInit(){
	fp = fopen("log.txt", "w");
	fputs("", fp);
	fclose(fp);
}

void loggerPushLog(int type, char *content){
	ntime = getTime();
	fp = fopen("log.txt", "a");
	fprintf(fp, "%s [%d:%d:%d]: %s\n", types[type], ntime[0], ntime[1], ntime[2], content);
	fclose(fp);
}

void loggerPushNum(int type, int num){
	ntime = getTime();
	fp = fopen("log.txt", "a");
	fprintf(fp, "%s [%d:%d:%d]: %d\n", types[type], ntime[0], ntime[1], ntime[2], num);
	fclose(fp);
}