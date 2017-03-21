/*
 * CSP library
 * Copyright (C) 2017, Cosmed s.r.l. <http://www.cosmed.com/>
 * Author: Gabriele Filosofi <gabrielef@cosmed.it>
 */

#ifndef CSP_INFO_H
#define CSP_INFO_H

#include "CSPTime.h"
#include "CSPConfig.h"
#include "CSPMessage.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct CSPInfo_st {
	int		type;			//kCSPTypeProduct or kCSPTypeDevice
	char		manufacturer[10];	//Cosmed"or "Apple"
	char		model[10];		//PN or SKU
	CSPTime_t	utc;			//UTC
	int		rssi;			//Rx signal strength
} CSPInfo_t;

void csp_zero_info(CSPInfo_t *info);

#ifdef  __cplusplus
}
#endif

#endif /* CSP_INFO_H */

