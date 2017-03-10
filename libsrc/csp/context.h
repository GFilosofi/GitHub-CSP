/*
 * CSP library
 * Copyright (C) 2017, Cosmed s.r.l. <http://www.cosmed.com/>
 * Author: Gabriele Filosofi <gabrielef@cosmed.it>
 */

#ifndef NMEA_CONTEXT_H
#define NMEA_CONTEXT_H

#include "CSPConfig.h"

#define NMEA_DEF_PARSEBUFF  (1024)
#define NMEA_MIN_PARSEBUFF  (256)

#ifdef  __cplusplus
extern "C" {
#endif

typedef void (*nmeaTraceFunc)(const char *str, int str_size);
typedef void (*nmeaErrorFunc)(const char *str, int str_size);

#pragma pack(push,1)
typedef struct _nmeaPROPERTY
{
    nmeaTraceFunc   trace_func;
    nmeaErrorFunc   error_func;
    int             parse_buff_size;

} nmeaPROPERTY;
#pragma pack(pop)

nmeaPROPERTY * nmea_property();

void nmea_trace(const char *str, ...);
void nmea_trace_buff(const char *buff, int buff_size);
void nmea_error(const char *str, ...);

#ifdef  __cplusplus
}
#endif

#endif /* _NMEA_CONTEXT_H_ */
