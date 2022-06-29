#ifndef _DYNAMIC_LOGGING_H_
#define _DYNAMIC_LOGGING_H_
#include "../Container/DArray.h"
#include "../Container/DStr.h"
#include "../System/DTypes.h"

#define COL_RESET       "\033[0m"
#define COL_BLACK       "\033[30m"             /* Black */
#define COL_RED         "\033[31m"             /* Red */
#define COL_GREEN       "\033[32m"             /* Green */
#define COL_YELLOW      "\033[33m"             /* Yellow */
#define COL_BLUE        "\033[34m"             /* Blue */
#define COL_MAGENTA     "\033[35m"             /* Magenta */
#define COL_CYAN        "\033[36m"             /* Cyan */
#define COL_WHITE       "\033[37m"             /* White */
#define COL_BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define COL_BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define COL_BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define COL_BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define COL_BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define COL_BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define COL_BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define COL_BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define DPRINT_INF_FLAG    (unsigned char)1 << 1
#define DPRINT_DBG_FLAG    (unsigned char)1 << 2
#define DPRINT_WRN_FLAG    (unsigned char)1 << 3
#define DPRINT_ERR_FLAG    (unsigned char)1 << 4
#define DPRINT_ALL_FLAG \
    DPRINT_INF_FLAG | \
    DPRINT_DBG_FLAG | \
    DPRINT_WRN_FLAG | \
    DPRINT_ERR_FLAG

typedef unsigned char DPrint_flag;
extern DPrint_flag g_DPrint_level;

// Set the level of logging
void DPrint_set_level(DPrint_flag in_flag);

// Prints using normal formatting
int32_t DPrint(const char* in_format, ...);

// Prints with stack trace
int32_t DPrint_t(const char* in_format, ...);

#define DPrint_inf(...) \
if ((g_DPrint_level & DPRINT_INF_FLAG) != 0) { DPrint(COL_CYAN "Inf;" COL_WHITE " %s:%d: " COL_RESET, __FILE__, __LINE__); DPrint(__VA_ARGS__); DPrint("\n"); }
#define DPrint_dbg(...) \
if ((g_DPrint_level & DPRINT_DBG_FLAG) != 0) { DPrint(COL_GREEN "Dbg;" COL_WHITE " %s:%d: " COL_RESET, __FILE__, __LINE__); DPrint(__VA_ARGS__); DPrint("\n"); }
#define DPrint_wrn(...) \
if ((g_DPrint_level & DPRINT_WRN_FLAG) != 0) { DPrint(COL_YELLOW "Wrn;" COL_WHITE " %s:%d: " COL_RESET, __FILE__, __LINE__); DPrint(__VA_ARGS__); DPrint("\n"); }
#define DPrint_err(...) \
if ((g_DPrint_level & DPRINT_ERR_FLAG) != 0) { DPrint(COL_RED "Err;" COL_WHITE " %s:%d: " COL_RESET, __FILE__, __LINE__); DPrint(__VA_ARGS__); DPrint("\n"); }

// Print out a new line char
void DPrint_nl();

// Get the current time
uint64_t DPrint_get_time();

#endif
