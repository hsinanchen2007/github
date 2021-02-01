#include "stdafx.h"
#include <time.h>
#include <math.h>
#include "calendar_const.h"
#include "calendar_func.h"
#include "sun.h"
#include "moon.h"
#include "support.h"

double GetInitialEstimateSolarTerms(int year, int angle)
{
    int STMonth = int(ceil(double((angle + 90.0) / 30.0)));
    STMonth = STMonth > 12 ? STMonth - 12 : STMonth;

    /* 每月第一個節氣發生日期基本都4-9日之間，第二個節氣的發生日期都在16－24日之間 */
    if((angle % 15 == 0) && (angle % 30 != 0))
    {
    	return CalculateJulianDay(year, STMonth, 6, 12, 0, 0.00);
    }
    else
    {
    	return CalculateJulianDay(year, STMonth, 20, 12, 0, 0.00);
    }
}

// 計算指定年份的任意節氣，angle是節氣在黃道上的讀數
// 返回指定節氣的儒略日時間(力學時)
double CalculateSolarTerms(int year, int angle)
{
    double JD0, JD1,stDegree,stDegreep;

	JD1 = GetInitialEstimateSolarTerms(year, angle);
    do
    {
    	JD0 = JD1;
        stDegree = GetSunEclipticLongitudeEC(JD0);
        /*
			對黃經0度反覆運算逼近時，由於角度360度圓周性，估算黃經值可能在(345,360]和[0,15)兩個區間，
            如果值落入前一個區間，需要進行修正
        */
        stDegree = ((angle == 0) && (stDegree > 345.0)) ? stDegree - 360.0 : stDegree;
		stDegreep = (GetSunEclipticLongitudeEC(JD0 + 0.000005)
                      - GetSunEclipticLongitudeEC(JD0 - 0.000005)) / 0.00001;
		JD1 = JD0 - (stDegree - angle) / stDegreep;
    }while((fabs(JD1 - JD0) > 0.0000001));

    return JD1;
}

/*
得到給定的時間後面第一個日月合朔的時間，平均誤差小於3秒
輸入參數是指定時間的力學時儒略日數
返回值是日月合朔的力學時儒略日數
*/
double CalculateMoonShuoJD(double tdJD)
{
    double JD0, JD1,stDegree,stDegreep;

	JD1 = tdJD;
    do
    {
    	JD0 = JD1;
		double moonLongitude = GetMoonEclipticLongitudeEC(JD0);
		double sunLongitude = GetSunEclipticLongitudeEC(JD0);
        if((moonLongitude > 330.0) && (sunLongitude < 30.0))
        {
            sunLongitude = 360.0 + sunLongitude;
        }
        if((sunLongitude > 330.0) && (moonLongitude < 30.0))
        {
            moonLongitude = 60.0 + moonLongitude;
        }

		stDegree = moonLongitude - sunLongitude;
		if(stDegree >= 360.0)
			stDegree -= 360.0;

		if(stDegree < -360.0)
			stDegree += 360.0;

        stDegreep = (GetMoonEclipticLongitudeEC(JD0 + 0.000005) - GetSunEclipticLongitudeEC(JD0 + 0.000005) - GetMoonEclipticLongitudeEC(JD0 - 0.000005) + GetSunEclipticLongitudeEC(JD0 - 0.000005)) / 0.00001;
		JD1 = JD0 - stDegree / stDegreep;
    }while((fabs(JD1 - JD0) > 0.00000001));

    return JD1;
}

void CalculateStemsBranches(int year, int *stems, int *branches)
{
    int sc = year - 2000;
    *stems = (7 + sc) % 10;
    *branches = (5 + sc) % 12;

    if(*stems < 0)
        *stems += 10;
    if(*branches < 0)
        *branches += 12;
}
