/*
 * CSP library
 * Copyright (C) 2017, Cosmed s.r.l. <http://www.cosmed.com/>
 * Author: Gabriele Filosofi <gabrielef@cosmed.it>
 */

#ifndef NMEA_GENERATE_H
#define NMEA_GENERATE_H

#include "sentence.h"

#ifdef  __cplusplus
extern "C" {
#endif

int     nmea_generate(
        char *buff, int buff_sz,    /* buffer */
        const nmeaINFO *info,       /* source info */
        int generate_mask           /* mask of sentence`s (e.g. GPGGA | GPGSA) */
        );

int     nmea_gen_GPGGA(char *buff, int buff_sz, nmeaGPGGA *pack);
int     nmea_gen_GPGSA(char *buff, int buff_sz, nmeaGPGSA *pack);
int     nmea_gen_GPGSV(char *buff, int buff_sz, nmeaGPGSV *pack);
int     nmea_gen_GPRMC(char *buff, int buff_sz, nmeaGPRMC *pack);
int     nmea_gen_GPVTG(char *buff, int buff_sz, nmeaGPVTG *pack);

void    nmea_info2GPGGA(const nmeaINFO *info, nmeaGPGGA *pack);
void    nmea_info2GPGSA(const nmeaINFO *info, nmeaGPGSA *pack);
void    nmea_info2GPRMC(const nmeaINFO *info, nmeaGPRMC *pack);
void    nmea_info2GPVTG(const nmeaINFO *info, nmeaGPVTG *pack);

int     nmea_gsv_npack(int sat_count);
void    nmea_info2GPGSV(const nmeaINFO *info, nmeaGPGSV *pack, int pack_idx);

#ifdef  __cplusplus
}
#endif

#endif /* NMEA_GENERATE_H */
