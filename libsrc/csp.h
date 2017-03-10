/*
 * CSP library
 * Copyright (C) 2017, Cosmed s.r.l. <http://www.cosmed.com/>
 * Author: Gabriele Filosofi <gabrielef@cosmed.it>
 */

#ifndef CSP_H
#define CSP_H

#include "csp/CSPConfig.h"

/* non so bene a cosa serve */
#if defined(PLATFORM_MACOSX) || defined(PLATFORM_LINUX)
 #define EXPORT __attribute__((visibility("default")))
#endif

#include "csp/units.h"
#include "csp/gmath.h"
#include "csp/info.h"
#include "csp/sentence.h"
#include "csp/generate.h"
#include "csp/generator.h"
#include "csp/parse.h"
#include "csp/parser.h"
#include "csp/context.h"

#endif /* CSP_H */
