/*
 * CSP library
 * Copyright (C) 2017, Cosmed s.r.l. <http://www.cosmed.com/>
 * Author: Gabriele Filosofi <gabrielef@cosmed.it>
 */

#ifndef NMEA_PARSER_H
#define NMEA_PARSER_H

#include "info.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*
 * high level
 */

typedef struct _nmeaPARSER
{
    void *top_node;
    void *end_node;
    unsigned char *buffer;
    int buff_size;
    int buff_use;

} nmeaPARSER;

int     nmea_parser_init(nmeaPARSER *parser);
void    nmea_parser_destroy(nmeaPARSER *parser);

int     nmea_parse(
        nmeaPARSER *parser,
        const char *buff, int buff_sz,
        nmeaINFO *info
        );

/*
 * low level
 */

int     nmea_parser_push(nmeaPARSER *parser, const char *buff, int buff_sz);
int     nmea_parser_top(nmeaPARSER *parser);
int     nmea_parser_pop(nmeaPARSER *parser, void **pack_ptr);
int     nmea_parser_peek(nmeaPARSER *parser, void **pack_ptr);
int     nmea_parser_drop(nmeaPARSER *parser);
int     nmea_parser_buff_clear(nmeaPARSER *parser);
int     nmea_parser_queue_clear(nmeaPARSER *parser);

#ifdef  __cplusplus
}
#endif

#endif /* NMEA_PARSER_H */
