/*
 * CSP library
 * Copyright (C) 2017, Cosmed s.r.l. <http://www.cosmed.com/>
 * Author: Gabriele Filosofi <gabrielef@cosmed.it>
 */

#include <string.h>

#include "csp/info.h"
#include "csp/CSPInfo.h"

void nmea_zero_INFO(nmeaINFO *info)
{
    memset(info, 0, sizeof(nmeaINFO));
    csp_time_now(&info->utc);
    info->sig = NMEA_SIG_BAD;
    info->fix = NMEA_FIX_BAD;
}

/* /////////////////////////////////////// */

void csp_zero_info(CSPInfo_t *info)
{
	memset(info, 0, sizeof(CSPInfo_t));
	csp_time_now(&info->utc);
#if (CSP_FOR_PRODUCT == 1)
	info->type = kCSPTypeProduct;
#else
	info->type = kCSPTypeDevice;
#endif
}
