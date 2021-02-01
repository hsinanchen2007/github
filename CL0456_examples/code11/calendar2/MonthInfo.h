#pragma once

#include "DayInfo.h"

typedef struct tagMonthInfo
{
    int month;           //西曆月序號
    int days;            //西曆月天數
    int first_week;      //本月1號的星期
    double jieqiJD;        //本月節氣的JD，本地時間
    SOLAR_TERMS jieqi;     //本月節氣序號
    double zhongqiJD;      //本月中氣的JD，本地時間
    SOLAR_TERMS zhongqi;   //本月中氣的序號
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
