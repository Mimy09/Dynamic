#include "DLog.h"
#include <stdarg.h>
#include <string.h>
#include <execinfo.h>
#include <stdio.h>
#include <time.h>

DPrint_flag g_DPrint_level = 0;

void DPrint_set_level(DPrint_flag in_flag) {
    g_DPrint_level = in_flag;
}

int32_t DPrint(const char* in_format, ...) {
    int32_t done; va_list arg;
    va_start(arg, in_format);
    done = vfprintf(stdout, in_format, arg);
    va_end(arg);
    return done;
}

int32_t DPrint_t(const char* in_format, ...) {
    int32_t done; va_list arg;
    va_start(arg, in_format);
    done = vfprintf(stdout, in_format, arg);
    va_end(arg);
	DStr* trace = DStr_create(NULL);
	DPrint_get_trace(trace, true);
    printf("\n\t%s\n", DStr_cstr(trace));
	DStr_free(trace);
	return done;
}

int32_t _DPrint_inf_(DTrace in_trace, const char* in_format, ...) {
    fprintf(stdout, COL_CYAN "Inf;" COL_WHITE " %s:%d: " COL_RESET, in_trace._file, in_trace._line);
    int32_t done; va_list arg;
    va_start(arg, in_format);
    done = vfprintf(stdout, in_format, arg);
    va_end(arg);
    puts("");
    return done;
}
int32_t _DPrint_dbg_(DTrace in_trace, const char* in_format, ...) {
    fprintf(stdout, COL_GREEN "Dbg;" COL_WHITE " %s:%d: " COL_RESET, in_trace._file, in_trace._line);
    int32_t done; va_list arg;
    va_start(arg, in_format);
    done = vfprintf(stdout, in_format, arg);
    va_end(arg);
    puts("");
    return done;
}
int32_t _DPrint_wrn_(DTrace in_trace, const char* in_format, ...) {
    fprintf(stdout, COL_YELLOW "Wrn;" COL_WHITE " %s:%d: " COL_RESET, in_trace._file, in_trace._line);
    int32_t done; va_list arg;
    va_start(arg, in_format);
    done = vfprintf(stdout, in_format, arg);
    va_end(arg);
    puts("");
    return done;
}
int32_t _DPrint_err_(DTrace in_trace, const char* in_format, ...) {
    fprintf(stdout, COL_RED "Err;" COL_WHITE " %s:%d: " COL_RESET, in_trace._file, in_trace._line);
    int32_t done; va_list arg;
    va_start(arg, in_format);
    done = vfprintf(stdout, in_format, arg);
    va_end(arg);
    puts("");
    return done;
}

void DPrint_nl() { printf("\n"); }

void DPrint_get_trace(DStr* io_str, bool in_color) {
    void *array[10];
    char **strings;

    int size = backtrace (array, 10);
    strings = backtrace_symbols (array, size);
    if (strings != NULL) {
        for (int i = size - 4; i > 1; i--) {
            char* tok_trace[8];
            char* tok, *rstp, *rst = rstp = strdup(strings[i]);

            for (int i = 0; (tok = strtok_r(rst, "()+", &rst)); i++) {
                tok_trace[i] = tok;
            }
			if (in_color) {
				if (i != 2) {
					char tmp[256]; sprintf(tmp, COL_BOLDBLUE "%s" COL_RESET " -> ", tok_trace[1]);
					DStr_append(io_str, tmp);
				}
				else {
					char tmp[256]; sprintf(tmp, COL_BOLDBLUE "%s" COL_RESET, tok_trace[1]);
					DStr_append(io_str, tmp);
				}
			} else {
				if (i != 2) {
					char tmp[256]; sprintf(tmp, "%s -> ", tok_trace[1]);
					DStr_append(io_str, tmp);
				}
				else {
					char tmp[256]; sprintf(tmp, "%s", tok_trace[1]);
					DStr_append(io_str, tmp);
				}
			}

			free(rstp);
        }
    }
    free (strings);
}

uint64_t DPrint_get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (long long)(ts.tv_sec) * 1000000000LL + (long long)(ts.tv_nsec);
}
