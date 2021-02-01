#pragma once

#include "DayInfo.h"

typedef struct tagMonthInfo
{
    int month;           //����Ǹ�
    int days;            //����Ѽ�
    int first_week;      //����1�����P��
    double jieqiJD;        //����`��JD�A���a�ɶ�
    SOLAR_TERMS jieqi;     //����`��Ǹ�
    double zhongqiJD;      //���뤤��JD�A���a�ɶ�
    SOLAR_TERMS zhongqi;   //���뤤�𪺧Ǹ�
}MONTH_INFO;

class CChineseCalendar;

class CMonthInfo
{
    friend class CChineseCalendar;
protected:
    CMonthInfo(const MONTH_INFO *info);
public:
    ~CMonthInfo(void);
    void SetMonthInfo(const MONTH_INFO *info);
    void GetMonthInfo(MONTH_INFO *info);
    const CDayInfo& GetDayInfo(int day) const;
    void AddSingleDay(CDayInfo& info);
    int GetMonthIndex() const { return m_Info.month; };
    int GetDaysCount() const { return m_Info.days; };
    int GetFirstDayWeek() const { return m_Info.first_week; };
    bool CheckValidDayCount();
    void ClearInfo();
protected:
    MONTH_INFO m_Info;

    std::vector<CDayInfo> m_DayInfo;
};
