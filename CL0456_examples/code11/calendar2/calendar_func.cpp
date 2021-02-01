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

    /* �C��Ĥ@�Ӹ`��o�ͤ���򥻳�4-9�餧���A�ĤG�Ӹ`�𪺵o�ͤ�����b16��24�餧�� */
    if((angle % 15 == 0) && (angle % 30 != 0))
    {
    	return CalculateJulianDay(year, STMonth, 6, 12, 0, 0.00);
    }
    else
    {
    	return CalculateJulianDay(year, STMonth, 20, 12, 0, 0.00);
    }
}

// �p����w�~�������N�`��Aangle�O�`��b���D�W��Ū��
// ��^���w�`�𪺾�����ɶ�(�O�Ǯ�)
double CalculateSolarTerms(int year, int angle)
{
    double JD0, JD1,stDegree,stDegreep;

	JD1 = GetInitialEstimateSolarTerms(year, angle);
    do
    {
    	JD0 = JD1;
        stDegree = GetSunEclipticLongitudeEC(JD0);
        /*
			����g0�פ��йB��G��ɡA�ѩ󨤫�360�׶�P�ʡA������g�ȥi��b(345,360]�M[0,15)��Ӱ϶��A
            �p�G�ȸ��J�e�@�Ӱ϶��A�ݭn�i��ץ�
        */
        stDegree = ((angle == 0) && (stDegree > 345.0)) ? stDegree - 360.0 : stDegree;
		stDegreep = (GetSunEclipticLongitudeEC(JD0 + 0.000005)
                      - GetSunEclipticLongitudeEC(JD0 - 0.000005)) / 0.00001;
		JD1 = JD0 - (stDegree - angle) / stDegreep;
    }while((fabs(JD1 - JD0) > 0.0000001));

    return JD1;
}

/*
�o�쵹�w���ɶ��᭱�Ĥ@�Ӥ��X�Ҫ��ɶ��A�����~�t�p��3��
��J�ѼƬO���w�ɶ����O�Ǯɾ������
��^�ȬO���X�Ҫ��O�Ǯɾ������
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
