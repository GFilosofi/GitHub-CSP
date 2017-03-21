//
//  CSP.m
//  CSP
//
//  Created by Gabriele Filosofi on 08/03/2017.
//  Copyright © 2017 Gabriele Filosofi. All rights reserved.
//

#import "CSP.h"
//#import "CSPInfo.h"

@implementation CSP

/* generate 10 nmea msgs from initial info */
static int generate(void)
{

//    CSPInfo_t info;
    char buff[2048];
    int gen_sz;
    int it;
#if 0
    csp_zero_INFO(&info);

    info.sig = 3;
    info.fix = 3;
    info.lat = 5000.0;
    info.lon = 3600.0;
    info.speed = 2.14 * NMEA_TUS_MS;
    info.elv = 10.86;
    info.satinfo.inuse = 1;
    info.satinfo.inview = 1;
    
    for(it = 0; it < 10; ++it)
    {
        gen_sz = nmea_generate(
                               &buff[0], 2048, &info,
                               GPGGA | GPGSA | GPGSV | GPRMC | GPVTG
                               );
        
        buff[gen_sz] = 0;
        printf("%s\n", &buff[0]);
        
        usleep(500000);
        info.speed += .1;
    }
#endif
    return 0;
}

@end
