#ifndef __MOON_CALENDAR_H__
#define __MOON_CALENDAR_H__

/*獲取月亮地心黃經，單位度*/
double GetMoonEclipticLongitudeEC(double dbJD);

double GetMoonEclipticLatitudeEC(double dbJD);
double GetMoonEarthDistance(double dbJD);

#endif //__MOON_CALENDAR_H__
