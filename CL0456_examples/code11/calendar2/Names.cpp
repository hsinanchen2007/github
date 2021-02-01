#include "stdafx.h"
#include "Names.h"

TCHAR *nameOfMonth[MONTHES_FOR_YEAR] = { _T("January"), _T("February"), _T("March"), _T("April"), _T("May"), 
                                        _T("June"), _T("July"), _T("August"), _T("September"), _T("October"), 
                                        _T("November"), _T("December") };
TCHAR *nameOfWeek[DAYS_FOR_WEEK] = { _T("�P����"),_T("�P���@"),_T("�P���G"),_T("�P���T"),_T("�P���|"),_T("�P����"),_T("�P����") };

TCHAR *nameOfStems[HEAVENLY_STEMS] = { _T("��"),_T("�A"),_T("��"),_T("�B"),_T("��"),_T("�v"),_T("��"),_T("��"),_T("��"),_T("��") };
TCHAR *nameOfBranches[EARTHLY_BRANCHES] = { _T("�l"),_T("��"),_T("�G"),_T("�f"),_T("��"),_T("�x"),_T("��"),_T("��"),_T("��"),_T("��"),_T("��"),_T("��") };
TCHAR *nameOfShengXiao[CHINESE_SHENGXIAO] = { _T("��"),_T("��"),_T("��"),_T("��"),_T("�s"),_T("�D"),_T("��"),_T("��"),_T("�U"),_T("��"),_T("��"),_T("��") };
TCHAR *nameOfChnDay[MAX_CHINESE_MONTH_DAYS] = { _T("��@"),_T("��G"),_T("��T"),_T("��|"),_T("�줭"),_T("�줻"),_T("��C"),_T("��K"),_T("��E"),_T("��Q"),
                                              _T("�Q�@"),_T("�Q�G"),_T("�Q�T"),_T("�Q�|"),_T("�Q��"),_T("�Q��"),_T("�Q�C"),_T("�Q�K"),_T("�Q�E"),_T("�G�Q"),
                                              _T("�ܤ@"),_T("�ܤG"),_T("�ܤT"),_T("�ܥ|"),_T("�ܤ�"),_T("�ܤ�"),_T("�ܤC"),_T("�ܤK"),_T("�ܤE"),_T("�T�Q")
                                            };
TCHAR *nameOfChnMonth[MONTHES_FOR_YEAR] = { _T("��"),_T("�G"),_T("�T"),_T("�|"),_T("��"),_T("��"),_T("�C"),_T("�K"),_T("�E"),_T("�Q"),_T("�Q�@"),_T("þ") };
TCHAR *nameOfJieQi[SOLAR_TERMS_COUNT] = { _T("�K��"), _T("�M��"), _T("�\�B"), _T("�߮L"), _T("�p��"), _T("�~��"), _T("�L��"), _T("�p��"), 
                                        _T("�j��"), _T("�߬�"), _T("�B��"), _T("���S"), _T("���"), _T("�H�S"), _T("����"), _T("�ߥV"), 
                                        _T("�p��"), _T("�j��"), _T("�V��"), _T("�p�H"), _T("�j�H"), _T("�߬K"), _T("�B��"), _T("���h") };
