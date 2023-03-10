/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_HAL_H
#define _MOCK_HAL_H

#include "unity.h"
#include "hal.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_hal_Init(void);
void mock_hal_Destroy(void);
void mock_hal_Verify(void);




#define hal_init_Ignore() hal_init_CMockIgnore()
void hal_init_CMockIgnore(void);
#define hal_init_StopIgnore() hal_init_CMockStopIgnore()
void hal_init_CMockStopIgnore(void);
#define hal_init_Expect() hal_init_CMockExpect(__LINE__)
void hal_init_CMockExpect(UNITY_LINE_TYPE cmock_line);
typedef void (* CMOCK_hal_init_CALLBACK)(int cmock_num_calls);
void hal_init_AddCallback(CMOCK_hal_init_CALLBACK Callback);
void hal_init_Stub(CMOCK_hal_init_CALLBACK Callback);
#define hal_init_StubWithCallback hal_init_Stub
#define hal_get_ticks_IgnoreAndReturn(cmock_retval) hal_get_ticks_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void hal_get_ticks_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t cmock_to_return);
#define hal_get_ticks_StopIgnore() hal_get_ticks_CMockStopIgnore()
void hal_get_ticks_CMockStopIgnore(void);
#define hal_get_ticks_ExpectAndReturn(cmock_retval) hal_get_ticks_CMockExpectAndReturn(__LINE__, cmock_retval)
void hal_get_ticks_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t cmock_to_return);
typedef uint32_t (* CMOCK_hal_get_ticks_CALLBACK)(int cmock_num_calls);
void hal_get_ticks_AddCallback(CMOCK_hal_get_ticks_CALLBACK Callback);
void hal_get_ticks_Stub(CMOCK_hal_get_ticks_CALLBACK Callback);
#define hal_get_ticks_StubWithCallback hal_get_ticks_Stub

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
