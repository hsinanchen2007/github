#include "stdafx.h"
#include <math.h>
#include "calendar_const.h"
#include "sun.h"
#include "vsop87_data.h"
#include "support.h"
#include "nutation.h"

double CalcPeriodicTerm(const VSOP87_COEFFICIENT *coff, int count, double dt)
{
    double val = 0.0;

    for(int i = 0; i < count; i++)
        val += (coff[i].A * cos((coff[i].B + coff[i].C * dt)));

    return val;
}

double CalcSunEclipticLongitudeEC(double dt)
{
    
    double L0 = CalcPeriodicTerm(Earth_L0, COUNT_OF(Earth_L0), dt);
    double L1 = CalcPeriodicTerm(Earth_L1, COUNT_OF(Earth_L1), dt);
    double L2 = CalcPeriodicTerm(Earth_L2, COUNT_OF(Earth_L2), dt);
    double L3 = CalcPeriodicTerm(Earth_L3, COUNT_OF(Earth_L3), dt);
    double L4 = CalcPeriodicTerm(Earth_L4, COUNT_OF(Earth_L4), dt);
    double L5 = CalcPeriodicTerm(Earth_L5, COUNT_OF(Earth_L5), dt);

    double L = (((((L5 * dt + L4) * dt + L3) * dt + L2) * dt + L1) * dt + L0) / 100000000.0;

    /*�a�߶��g = ��߶��g + 180��*/
    return (Mod360Degree(Mod360Degree(L / RADIAN_PER_ANGLE) + 180.0));
}

double CalcSunEclipticLatitudeEC(double dt)
{
    double B0 = CalcPeriodicTerm(Earth_B0, COUNT_OF(Earth_B0), dt);
    double B1 = CalcPeriodicTerm(Earth_B1, COUNT_OF(Earth_B1), dt);
    double B2 = CalcPeriodicTerm(Earth_B2, COUNT_OF(Earth_B2), dt);
    double B3 = CalcPeriodicTerm(Earth_B3, COUNT_OF(Earth_B3), dt);
    double B4 = CalcPeriodicTerm(Earth_B4, COUNT_OF(Earth_B4), dt);

	double B = (((((B4 * dt) + B3) * dt + B2) * dt + B1) * dt + B0) / 100000000.0;

   /*�a�߶��n = �Ф�߶��n*/
   return -(B / RADIAN_PER_ANGLE);
}

/*�ץ��Ӷ����a�߶��g�Alongitude, latitude �O�ץ��e���Ӷ��a�߶��g�M�a�߶��n(��)�Adt�O�����d�~�ơA��^�ȳ���*/
double AdjustSunEclipticLongitudeEC(double dt, double longitude, double latitude)
{
    double T = dt * 10; //T�O�����@����

    double dbLdash = longitude - 1.397 * T - 0.00031 * T * T;

    // �ഫ������
    dbLdash *= RADIAN_PER_ANGLE;

    return (-0.09033 + 0.03916 * (cos(dbLdash) + sin(dbLdash)) * tan(latitude * RADIAN_PER_ANGLE)) / 3600.0;
}

/*�ץ��Ӷ����a�߶��n�Alongitude�O�ץ��e���Ӷ��a�߶��g(��)�Adt�O�����d�~�ơA��^�ȳ���*/
double AdjustSunEclipticLatitudeEC(double dt, double longitude)
{
    double T = dt * 10; //T�O�����@����
    double dLdash = longitude - 1.397 * T - 0.00031 * T * T ;

    // �ഫ������
    dLdash  *= RADIAN_PER_ANGLE ;

    return (0.03916 * (cos(dLdash) - sin(dLdash))) / 3600.0 ;
}


double CalcSunEarthRadius(double dt)
{
    double R0 = CalcPeriodicTerm(Earth_R0, COUNT_OF(Earth_R0), dt);
    double R1 = CalcPeriodicTerm(Earth_R1, COUNT_OF(Earth_R1), dt);
    double R2 = CalcPeriodicTerm(Earth_R2, COUNT_OF(Earth_R2), dt);
    double R3 = CalcPeriodicTerm(Earth_R3, COUNT_OF(Earth_R3), dt);
    double R4 = CalcPeriodicTerm(Earth_R4, COUNT_OF(Earth_R4), dt);

    double R = (((((R4 * dt) + R3) * dt + R2) * dt + R1) * dt + R0) / 100000000.0;

    return R;
}

/*�o��Y�Ӿ����骺�Ӷ��a�߶��g(�����g)�A����*/
double GetSunEclipticLongitudeEC(double jde)
{
    double dt = (jde - JD2000) / 365250.0; /*�����d�~��*/

    // �p��Ӷ����a�߶��g
    double longitude = CalcSunEclipticLongitudeEC(dt);

    // �p��Ӷ����a�߶��n
    double latitude = CalcSunEclipticLatitudeEC(dt) * 3600.0;

    // �ץ����
    longitude += AdjustSunEclipticLongitudeEC(dt, longitude, latitude);

    // �ץ����鳹��
    longitude += CalcEarthLongitudeNutation(dt);

    // �ץ�����t
    /*�Ӷ��a�߶��g����t�ץ����O: -20".4898/R*/
    longitude -= (20.4898 / CalcSunEarthRadius(dt)) / 3600.0;

    return longitude;
}

/*�o��Y�Ӿ����骺�Ӷ��a�߶��n(�����n)�A����*/
double GetSunEclipticLatitudeEC(double jde)
{
    double dt = (jde - JD2000) / 365250.0; /*�����d�~��*/

    // �p��Ӷ����a�߶��g
    double longitude = CalcSunEclipticLongitudeEC(dt);
    // �p��Ӷ����a�߶��n
    double latitude = CalcSunEclipticLatitudeEC(dt) * 3600.0;

    // �ץ����
    double delta = AdjustSunEclipticLatitudeEC(dt, longitude);
    latitude += delta * 3600.0;

    return latitude;
}
