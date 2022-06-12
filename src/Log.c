#include "Game.h"

char Lower(char c) {
	if (c < 0x5b) { c += 0x20; }
	return c;
}

int Length(const char *str) {
	int result = 0;
	while(str[result]) { result++; }
	return result;
}

int GetType(char *str) {
	switch (Lower(str[0])) {
		case 'i':	return INFO;
		case 'w':	return WARNING;
		case 'e':	return ERROR;
	}
	return HEADER;
}

void Log(int lvl, const char *msg, const char *err) {
	switch (lvl) {
		case INFO:		printf(UTIL_BOLD FG_GREEN "[INFO]\t\t" UTIL_RESET FG_GREEN);	break;
		case WARNING:	printf(UTIL_BOLD FG_YELLOW "[WARNING]\t" UTIL_RESET FG_YELLOW);	break;
		case ERROR:		printf(UTIL_BOLD FG_RED "[ERROR]\t\t" UTIL_RESET FG_RED);		break;
		case HEADER:	printf(UTIL_BOLD "[%s]\n" UTIL_RESET, msg);						return;
		default:		Log(HEADER, msg, err);											return;
	}

	printf("%s%s\n", msg, UTIL_RESET);
	if (err == NULL)		{ return; }
	if (!Length(err))		{ return; }
	printf(UTIL_BOLD "\t\t<%s>\n" UTIL_RESET,err); 
}
