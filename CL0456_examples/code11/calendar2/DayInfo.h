#pragma once

#include "calendar_const.h"

typedef struct tagDayInfo
{
    int dayNo;         //本月內的日序號
    int week;          //本日的星期
    int mdayNo;        //本日對應的農曆月內日序號
    int mmonth;        //本日所在的農曆月序號
    SOLAR_TERMS st;    //本日對應的節氣，-1 表示不是節氣
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
