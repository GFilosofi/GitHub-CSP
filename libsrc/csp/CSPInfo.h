/*
 * CSP library
 * Copyright (C) 2017, Cosmed s.r.l. <http://www.cosmed.com/>
 * Author: Gabriele Filosofi <gabrielef@cosmed.it>
 */

#ifndef CSP_INFO_H
#define CSP_INFO_H

#include "CSPConfig.h"
#include "CSPMessage.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct CSPInfo_t {
	int	type;			//kCSPTypeProduct or kCSPTypeDevice
	char	manufacturer[10];	//Cosmed"or "Apple"
	char	model[10];		//PN or SKU
} CSPInfo;

void csp_zero_INFO(CSPInfo *info);

#ifdef  __cplusplus
}
#endif

#endif /* CSP_INFO_H */

