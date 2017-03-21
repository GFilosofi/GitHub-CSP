/*
 * CSP library
 * Copyright (C) 2017, Cosmed s.r.l. <http://www.cosmed.com/>
 * Author: Gabriele Filosofi <gabrielef@cosmed.it>
 */

#ifndef PRODUCT_SAMPLE_H
#define PRODUCT_SAMPLE_H

#include "csp/CSPMessage.h"

static const CSPParam_t ergoStepParams [] = {
{ 18,	"N",		"U2",	"",	0,	0,	16383 },	/* Step count. Resets on REC start. Rollover at 16384 */
{ 4097,	"Time",		"TIM",	"",	0,	0,	40000 },	/* Elapsed time from start. Resets on REC start */
{ 17,	"Marker",	"U1",	"",	0,	0,	1 },		/* Marker indicator */
{ 30,	"StepInfo",	"X2",	"",	0,	0,	1 },		/* Step information */
{ 12,	"TAmb",		"I2",	"°C",	1,	-400,	500 },		/* Ambient temperature */
{ 34,	"RHAmb",	"U1",	"%",	0,	0,	100 },		/* Ambient relative humidity */
{ 15,	"PB",		"U2",	"mmHg",	0,	300,	900 },		/* Barometric pressure */
{ 9,	"FiO2",		"U2",	"%",	2,	1000,	2093 },		/* O2 inspiratory fraction */
{ 10,	"FiCO2",	"U2",	"%",	2,	4,	1500 },		/* CO2 inspiratory fraction */
{ 42,	"O2Delay",	"U2",	"ms",	0,	0,	1000 },		/* O2 delay time */
{ 43,	"CO2Delay",	"U2",	"ms",	0,	0,	1000 },		/* CO2 delay time */
{ 13,	"TDev",		"U2",	"°C",	1,	0,	500 },		/* Device Temperature */
{ 14,	"PAn",		"U2",	"mmHg",	0,	300,	900 },		/* Analyzer pressure */
{ 36,	"Battery",	"U1",	"%",	0,	4,	100 },		/* Battery charger level */
{ 35,	"RHSampl",	"U1",	"%",	0,	0,	100 },		/* Sampling line relative humidity */
{ 40,	"BarAlt",	"I2",	"m",	0,	-200,	8000 },		/* Barometric pressure based altitude */
{ 41,	"MagHead",	"U2",	"°",	0,	0,	359 },		/* Magnetometer true heading */
{ 46,	"Pacing",	"U2",	"km/h",	1,	0,	3000 },		/* Target speed */
{ 47,	"Cad",		"U1",	"1/min",0,	0,	150 },		/* Accelerometer step cadence */
{ 48,	"StrLen",	"U2",	"cm",	0,	0,	1000 },		/* Stride length */
{ 4098,	"GpsLoD",	"I2",	"°",	0,	-180,	180 },		/* Longitude of position (degrees) */
{ 4099,	"GpsLoM",	"U4",	"'",	5,	0,	5999999 },	/* Longitude of position (minutes) */
{ 4100,	"GpsLaD",	"I2",	"°",	0,	-90,	90 },		/* Latitude of position (degrees) */
{ 4101,	"GpsLaM",	"U4",	"'",	5,	0,	5999999 },	/* Latitude of position (minutes) */
{ 38,	"GpsHead",	"U2",	"°",	0,	0,	359 },		/* GPS true heading */
{ 4102,	"GpsSnr",	"U1",	"dBHz",	0,	25,	32 },		/* GPS Carrier-to-Noise ratio */
{ 4103,	"GpsSvn",	"U1",	"",	0,	0,	20 },		/* GPS Total number of satellites in view */
{ 4104,	"GpsSts",	"U1",	"",	0,	0,	1 },		/* GPS Status */
{ 24,	"GpsSpd",	"U2",	"km/h",	1,	0,	3000 },		/* GPS speed over ground (SOG) */
{ 25,	"GpsAlt",	"I2",	"m",	0,	-200,	8000 },		/* GPS based altitude */
{ 49,	"BkSpd",	"U2",	"km/h",	1,	0,	1000 },		/* ANT bike speed */
{ 50,	"BkWlCad",	"U1",	"rpm",	0,	0,	250 },		/* ANT bike wheel revolutions */
{ 51,	"BkCkCad",	"U1",	"rpm",	0,	0,	250 },		/* ANT bike crank revolutions */
{ 52,	"BkPowWl",	"U2",	"W",	0,	0,	1200 },		/* ANT bike power */
{ 56,	"BkTrqCk",	"U2",	"Nm",	1,	0,	300 },		/* ANT bike torque at crank */
{ 57,	"BkTrqLe",	"U1",	"%",	0,	0,	100 },		/* ANT bike torque at left crank */
{ 58,	"BkTrqRi",	"U1",	"%",	0,	0,	100},		/* ANT bike torque at right crank */
{ 59,	"StrDist",	"U2",	"m",	0,	0,	16384},		/* ANT stride distance */
{ 60,	"StrSpd",	"U2",	"km/h",	1,	0,	560},		/* ANT stride speed */
{ 61,	"StrCad",	"U1",	"1/min",0,	0,	150},		/* ANT stride cadence */
{ 85,	"StrCnt",	"U2",	"",	0,	0,	16384},		/* ANT stride count */
{ 62,	"THb1",		"U1",	"g/dL",	2,	5,	30},		/* ANT total Hb concentration (sensor #1) */
{ 63,	"SmO21",	"U1",	"%",	0,	70,	100},		/* ANT muscolar O2 saturation (sensor #1) */
{ 89,	"THb2",		"U1",	"g/dL",	2,	5,	30},		/* ANT toalHb  */
{ 90,	"SmO22",	"U1",	"%",	0,	70,	100},		/*  */
{ 91,	"THb3",		"U1",	"g/dL",	2,	5,	30},		/*  */
{ 92,	"SmO23",	"U1",	"%",	0,	70,	100},		/*  */
{ 93,	"THb4",		"U1",	"g/dL",	2,	5,	30},		/*  */
{ 94,	"SmO24",	"U1",	"%",	0,	70,	100},		/*  */
{ 11,	"HR",		"U1",	"bpm",	0,	30,	220},		/*  */
{ 4105,	"Rf",		"U2",	"bpm",	1,	20,	1000},		/*  */
{ 4106,	"VE",		"U2",	"L/min",1,	0,	3000},		/*  */
{ 81,	"VO2",		"U2",	"mL/min",0,	0,	8000},		/*  */
{ 82,	"VCO2",		"U2",	"mL/min",0,	0,	8000},		/*  */
{ 83,	"RQ",		"U1",	"",	2,	50,	200},		/*  */
{ 4108,	"FeO2",		"U2",	"%",	2,	1000,	2093},		/*  */
{ 4109,	"FeCO2",	"U2",	"%",	2,	4,	1500},		/*  */
{ 26,	"SpO2",		"U1",	"%",	0,	70,	100},		/*  */
{ 72,	"Th",		"U2",	"°C",	1,	0,	500},		/*  */
{ 1,	"Ti",		"U2",	"ms",	0,	0,	15000},		/*  */
{ 2,	"Te",		"U2",	"ms",	0,	0,	15000},		/*  */
{ 3,	"IV",		"U2",	"mL",	0,	0,	8000},		/*  */
{ 4107,	"Vt",		"U2",	"mL",	0,	0,	8000},		/*  */
{ 5,	"O2exp",	"U2",	"mL",	1,	0,	10000},		/*  */
{ 6,	"CO2exp",	"U2",	"mL",	1,	0,	3000},		/*  */
{ 7,	"FetO2",	"U2",	"%",	2,	1000,	2100},		/*  */
{ 8,	"FetCO2",	"U2",	"%",	2,	0,	1500}		/*  */
};

static const CSPParam_t calibParams [] = {
{ 5120,	"GasCDat",	"DAT",	"",	0,	19700101,21000101 },	/* UTC date of gas calibration */
{ 5121,	"GasCTim",	"TIM",	"",	0,	0,	235959 },	/* UTC time of gas calibration */
{ 5122,	"FlwmCDat",	"DAT",	"",	0,	19700101,21000101 },	/* UTC date of flowmeter calibration */
{ 5123,	"FlwmCTim",	"TIM",	"",	0,	0,	235959 },	/* UTC time of flowmeter calibration */
{ 5124,	"DelayCDat",	"DAT",	"",	0,	19700101,21000101 },	/* UTC date of delay calibration */
{ 5125,	"DelayCTim",	"TIM",	"",	0,	0,	235959 },	/* UTC time of delay calibration */
{ 5126,	"O2Trim",	"U2",	"",	0,	200,	950 },		/* O2 trimmer value */
{ 5127,	"O2Gain",	"U2",	"",	0,	900,	1100 },		/* O2 gain */
{ 5128,	"O2BL",		"I2",	"mV",	0,	-300,	300 },		/* O2 baseline */
{ 5129,	"O2Delay",	"U2",	"ms",	0,	600,	900 },		/* O2 delay time */
{ 5130,	"O2RT",		"U2",	"ms",	0,	90,	190 },		/* O2 response time 10-90% */
{ 5131,	"O2Air",	"U2",	"%",	2,	1000,	2093 },		/* O2 fraction in air (measured) */
{ 5132,	"O2Cyl",	"U2",	"%",	2,	1000,	2100 },		/* O2 fraction in cylinder (measured) */
{ 5133,	"O2AirRef",	"U2",	"%",	2,	1000,	2093 },		/* O2 fraction in air (target ref.) */
{ 5134,	"O2CylRef",	"U2",	"%",	2,	1000,	2100 },		/* O2 fraction in cylinder (target ref.) */
{ 5135,	"CO2Trim",	"U2",	"",	0,	300,	900 },		/* CO2 trimmer value */
{ 5136,	"CO2Gain",	"U2",	"",	0,	800,	1200 },		/* CO2 gain */
{ 5137,	"CO2BL",	"U2",	"mV",	0,	3700,	3900 },		/* CO2 baseline */
{ 5138,	"CO2Delay",	"U2",	"ms",	0,	400,	700 },		/* CO2 delay time */
{ 5139,	"CO2RT",	"U2",	"ms",	0,	90,	120 },		/* CO2 response time 10-90 % */
{ 5140,	"CO2Air",	"U2",	"%",	2,	4,	1500 },		/* CO2 fraction in air (measured) */
{ 5141,	"CO2Cyl",	"U2",	"%",	2,	0,	1500 },		/* CO2 fraction in cylinder (measured) */
{ 5142,	"CO2AirRef",	"U2",	"%",	2,	4,	1500 },		/* CO2 fraction in air (target ref.) */
{ 5143,	"CO2CylRef",	"U2",	"%",	2,	0,	1500 },		/* CO2 fraction in cylinder (target ref.) */
{ 5144,	"FlwmGainE",	"U2",	"",	0,	950,	1080 },		/* Turbine flowmeter expiratory gain */
{ 5145,	"FlwmGainI",	"U2",	"",	0,	950,	1080 },		/* Turbine flowmeter inspiratory gain */
{ 5146,	"VolSyr",	"U2",	"mL",	0,	2995,	3005 },		/* Volume of calibration syringe */
{ 5147,	"TAmb",		"I2",	"°C",	1,	-400,	500 },		/* Ambient temperature during gas calibration */
{ 5148,	"RHAmb",	"U1",	"%",	0,	5,	90 },		/* Ambient relative humidity during gas calibration */
{ 5149,	"PB",		"U2",	"mmHg",	0,	300,	900 },		/* Barometric pressure during gas calibration */
{ 5150,	"TDev",		"U2",	"°C",	1,	0,	450 },		/* Device temperature during gas calibration */
{ 5151,	"PAn",		"U2",	"mmHg",	0,	300,	900 },		/* Analyzer pressure during gas calibration */
{ 5152,	"FAn",		"U2",	"mL/s",	0,	190,	210 }		/* Analyzer pressure during gas calibration */
};

#ifdef  __cplusplus
}
#endif
#endif /* PRODUCT_SAMPLE_H */
