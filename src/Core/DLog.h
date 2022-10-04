#ifndef _DYNAMIC_LOGGING_H_
#define _DYNAMIC_LOGGING_H_
#include "../Container/DArray.h"
#include "../Container/DStr.h"
#include "../System/DTypes.h"

#define COL_NRM "\033[0m"
#define COL_BLK "\033[30m"             /* Black */
#define COL_RED "\033[31m"             /* Red */
#define COL_GRN "\033[32m"             /* Green */
#define COL_YEL "\033[33m"             /* Yellow */
#define COL_BLU "\033[34m"             /* Blue */
#define COL_MAG "\033[35m"             /* Magenta */
#define COL_CYN "\033[36m"             /* Cyan */
#define COL_WHT "\033[37m"             /* White */
#define COL_BBLK "\033[1m\033[30m"      /* Bold Black */
#define COL_BRED "\033[1m\033[31m"      /* Bold Red */
#define COL_BGRN "\033[1m\033[32m"      /* Bold Green */
#define COL_BYEL "\033[1m\033[33m"      /* Bold Yellow */
#define COL_BBLU "\033[1m\033[34m"      /* Bold Blue */
#define COL_BMAG "\033[1m\033[35m"      /* Bold Magenta */
#define COL_BCYN "\033[1m\033[36m"      /* Bold Cyan */
#define COL_BWHT "\033[1m\033[37m"      /* Bold White */

#define DPRINT_INF_FLAG    (unsigned char)1 << 1
#define DPRINT_DBG_FLAG    (unsigned char)1 << 2
#define DPRINT_WRN_FLAG    (unsigned char)1 << 3
#define DPRINT_ERR_FLAG    (unsigned char)1 << 4
#define DPRINT_SYS_FLAG    (unsigned char)1 << 5
#define DPRINT_ALL_FLAG \
    DPRINT_INF_FLAG | \
    DPRINT_DBG_FLAG | \
    DPRINT_WRN_FLAG | \
    DPRINT_ERR_FLAG | \
    DPRINT_SYS_FLAG

typedef unsigned char DPrint_flag;
extern DPrint_flag g_DPrint_level;

// Set the level of logging
void DPrint_set_level(DPrint_flag in_flag);

// Prints using normal formatting
int32_t DPrint(const char* in_format, ...);

// Prints with stack trace
int32_t DPrint_t(const char* in_format, ...);

#define DPrint_inf(...) \
if ((g_DPrint_level & DPRINT_INF_FLAG) != 0) { DPrint(COL_CYN "Inf;" COL_WHT " %s:%d: " COL_NRM, __FILE__, __LINE__); DPrint(__VA_ARGS__); DPrint("\n"); }
#define DPrint_dbg(...) \
if ((g_DPrint_level & DPRINT_DBG_FLAG) != 0) { DPrint(COL_GRN "Dbg;" COL_WHT " %s:%d: " COL_NRM, __FILE__, __LINE__); DPrint(__VA_ARGS__); DPrint("\n"); }
#define DPrint_wrn(...) \
if ((g_DPrint_level & DPRINT_WRN_FLAG) != 0) { DPrint(COL_YEL "Wrn;" COL_WHT " %s:%d: " COL_NRM, __FILE__, __LINE__); DPrint(__VA_ARGS__); DPrint("\n"); }
#define DPrint_err(...) \
if ((g_DPrint_level & DPRINT_ERR_FLAG) != 0) { DPrint(COL_RED "Err;" COL_WHT " %s:%d: " COL_NRM, __FILE__, __LINE__); DPrint(__VA_ARGS__); DPrint("\n"); }
#define DPrint_sys(...) \
if ((g_DPrint_level & DPRINT_SYS_FLAG) != 0) { DPrint(COL_BLK "Sys;" COL_WHT " " COL_NRM, __FILE__, __LINE__); DPrint(__VA_ARGS__); DPrint("\n"); }
#define DPrint_sys_wrn(...) \
if ((g_DPrint_level & DPRINT_SYS_FLAG) != 0) { DPrint(COL_YEL "Sys;" COL_WHT " " COL_NRM, __FILE__, __LINE__); DPrint(__VA_ARGS__); DPrint("\n"); }
#define DPrint_sys_err(...) \
if ((g_DPrint_level & DPRINT_SYS_FLAG) != 0) { DPrint(COL_RED "Sys;" COL_WHT " " COL_NRM, __FILE__, __LINE__); DPrint(__VA_ARGS__); DPrint("\n"); }


// Print out a new line char
void DPrint_nl();

// Get the current time
uint64_t DPrint_get_time();

#endif
