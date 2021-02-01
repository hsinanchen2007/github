#pragma once

#include "calendar_const.h"

typedef struct tagDayInfo
{
    int dayNo;         //���뤺����Ǹ�
    int week;          //���骺�P��
    int mdayNo;        //����������A��뤺��Ǹ�
    int mmonth;        //����Ҧb���A���Ǹ�
    SOLAR_TERMS st;    //����������`��A-1 ��ܤ��O�`��
}DAY_INFO;

class CDayInfo
{
public:
    CDayInfo(const DAY_INFO *info);
    ~CDayInfo(void);

    void SetDayInfo(const DAY_INFO *info);
    void GetDayInfo(DAY_INFO *info);
    int GetDayDate() const { return m_Info.dayNo; };
    int GetDayChnDate() const { return m_Info.mdayNo; };
    int GetDayChnMonth() const { return m_Info.mmonth; };
    SOLAR_TERMS GetDaySolarTerm() const { return m_Info.st; };
    int GetDayWeek() const { return m_Info.week; };
protected:
    DAY_INFO m_Info;
};
