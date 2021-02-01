#ifndef __SUN_CALENDAR_H__
#define __SUN_CALENDAR_H__


/*計算太陽的地心黃經(度)，dt是儒略千年數*/
double CalcSunEclipticLongitudeEC(double dt);

/*計算太陽的地心黃緯(度)，dt是儒略千年數*/
double CalcSunEclipticLatitudeEC(double dt);

/*修正太陽的地心黃經，longitude, latitude 是修正前的日心黃經和日心黃緯(度)，dt是儒略千年數，返回值單位度*/
double AdjustSunEclipticLongitudeEC(double dt, double longitude, double latitude);

/*修正太陽的地心黃緯，longitude是修正前的太陽地心黃經(度)，dt是儒略千年數，返回值單位度*/
double AdjustSunEclipticLatitudeEC(double dt, double longitude);

/*計算*/
double CalcSunEarthRadius(double dt);

/*得到某個時間的太陽地心黃經(視黃經)，單位度，dt是儒略世紀數*/
double GetSunEclipticLongitudeEC2(double dt);

/*得到某個儒略日的太陽地心黃經(視黃經)，單位度*/
double GetSunEclipticLongitudeEC(double jde);

/*得到某個儒略日的太陽地心黃緯(視黃緯)，單位度*/
double GetSunEclipticLatitudeEC(double jde);

#endif //__SUN_CALENDAR_H__

