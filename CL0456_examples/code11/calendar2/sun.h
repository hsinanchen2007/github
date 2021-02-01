#ifndef __SUN_CALENDAR_H__
#define __SUN_CALENDAR_H__


/*�p��Ӷ����a�߶��g(��)�Adt�O�����d�~��*/
double CalcSunEclipticLongitudeEC(double dt);

/*�p��Ӷ����a�߶��n(��)�Adt�O�����d�~��*/
double CalcSunEclipticLatitudeEC(double dt);

/*�ץ��Ӷ����a�߶��g�Alongitude, latitude �O�ץ��e����߶��g�M��߶��n(��)�Adt�O�����d�~�ơA��^�ȳ���*/
double AdjustSunEclipticLongitudeEC(double dt, double longitude, double latitude);

/*�ץ��Ӷ����a�߶��n�Alongitude�O�ץ��e���Ӷ��a�߶��g(��)�Adt�O�����d�~�ơA��^�ȳ���*/
double AdjustSunEclipticLatitudeEC(double dt, double longitude);

/*�p��*/
double CalcSunEarthRadius(double dt);

/*�o��Y�Ӯɶ����Ӷ��a�߶��g(�����g)�A���סAdt�O�����@����*/
double GetSunEclipticLongitudeEC2(double dt);

/*�o��Y�Ӿ����骺�Ӷ��a�߶��g(�����g)�A����*/
double GetSunEclipticLongitudeEC(double jde);

/*�o��Y�Ӿ����骺�Ӷ��a�߶��n(�����n)�A����*/
double GetSunEclipticLatitudeEC(double jde);

#endif //__SUN_CALENDAR_H__

