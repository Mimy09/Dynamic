#include "DLog.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#include "DMemory.h"
#endif

#ifdef _WIN32
void nix_to_win(char* _nix) {
#ifdef DEBUG
    bool logging = DMemory_is_logging();
    if (logging) DMemory_logging(false);
#endif

    if (strstr(_nix, "\033") == 0) { printf(_nix); return; }
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	DStr* str = DStr_create(_nix);
	DArray* strarr = DStr_split(str, "\033[");

	bool is_bold = false;
	for (int i = 0; i < DArray_size(strarr); i++) {

		char colbuff[8]; char* p = *DArray_get_cstr(strarr, i); int j = 0;
		for (; j < 8; j++) {
			colbuff[j] = *p; p++;
			if (*p == 'm') {
				colbuff[j + 1] = '\0';
				break;
			}
		}

		if (strcmp(colbuff, "1") == 0) { is_bold = true; }
		if (strcmp(colbuff, "0") == 0) {
			SetConsoleTextAttribute(hCon, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
			if (i == DArray_size(strarr)) { break; }
		}
		else if (strcmp(colbuff, "30") == 0) {
			if (is_bold) SetConsoleTextAttribute(hCon, 0 | FOREGROUND_INTENSITY);
			else SetConsoleTextAttribute(hCon, 0); is_bold = false;
		}
		else if (strcmp(colbuff, "31") == 0) {
			if (is_bold) SetConsoleTextAttribute(hCon, FOREGROUND_INTENSITY | FOREGROUND_RED);
			else SetConsoleTextAttribute(hCon, FOREGROUND_RED); is_bold = false;
		}
		else if (strcmp(colbuff, "32") == 0) {
			if (is_bold) SetConsoleTextAttribute(hCon, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			else SetConsoleTextAttribute(hCon, FOREGROUND_GREEN); is_bold = false;
		}
		else if (strcmp(colbuff, "33") == 0) {
			if (is_bold) SetConsoleTextAttribute(hCon, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			else SetConsoleTextAttribute(hCon, FOREGROUND_RED | FOREGROUND_GREEN); is_bold = false;
		}
		else if (strcmp(colbuff, "34") == 0) {
			if (is_bold) SetConsoleTextAttribute(hCon, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			else SetConsoleTextAttribute(hCon, FOREGROUND_BLUE); is_bold = false;
		}
		else if (strcmp(colbuff, "35") == 0) {
			if (is_bold) SetConsoleTextAttribute(hCon, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			else SetConsoleTextAttribute(hCon, FOREGROUND_BLUE | FOREGROUND_RED); is_bold = false;
		}
		else if (strcmp(colbuff, "36") == 0) {
			if (is_bold) SetConsoleTextAttribute(hCon, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			else SetConsoleTextAttribute(hCon, FOREGROUND_BLUE | FOREGROUND_GREEN); is_bold = false;
		}
		else if (strcmp(colbuff, "37") == 0) {
			if (is_bold) SetConsoleTextAttribute(hCon, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			else SetConsoleTextAttribute(hCon, FOREGROUND_GREEN | FOREGROUND_RED); is_bold = false;
		}
		else if (strcmp(colbuff, "38") == 0) {
			if (is_bold) SetConsoleTextAttribute(hCon, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			else SetConsoleTextAttribute(hCon, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); is_bold = false;
		}
		
		char buff[strlen(*DArray_get_cstr(strarr, i))];
		strcpy(buff, ((*DArray_get_cstr(strarr, i)) + (sizeof(char) * j + 2)));
		printf("%s", buff);
	}

	DStr_split_free(strarr);
	DStr_free(str);
#ifdef DEBUG
    if (logging) DMemory_logging(true);
#endif
}
#endif

DPrint_flag g_DPrint_level = 0;

void DPrint_set_level(DPrint_flag in_flag) {
    g_DPrint_level = in_flag;
}

int32_t DPrint(const char* in_format, ...) {
    int32_t done; va_list arg;
    va_start(arg, in_format);
    #ifdef _WIN32
    char buffer[4096];
    done = vsprintf(buffer, in_format, arg);
    nix_to_win(buffer);
    #else
    done = vfprintf(stdout, in_format, arg);
    #endif
    va_end(arg);
    return done;
}

void DPrint_nl() { printf("\n"); }

uint64_t DPrint_get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (long long)(ts.tv_sec) * 1000000000LL + (long long)(ts.tv_nsec);
}

