/*
 * CSP library
 * Copyright (C) 2017, Cosmed s.r.l. <http://www.cosmed.com/>
 * Author: Gabriele Filosofi <gabrielef@cosmed.it>
 */

#ifndef CSP_TIME_H
#define CSP_TIME_H

#include "CSPConfig.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct CSPTime_st
{
    int     year;	/* years since 1900 */
    int     month;	/* months since January - [0,11] */
    int     day;	/* Day of the month - [1,31] */
    int     hour;	/* Hours since midnight - [0,23] */
    int     min;	/* Minutes after the hour - [0,59] */
    int     sec;	/* Seconds after the minute - [0,59] */
} CSPTime_t;
void csp_time_now(CSPTime_t *t);

#ifdef  __cplusplus
}
#endif

#endif /* CSP_TIME_H */
