// chinese_num.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <cassert>

//using namespace std;

const int CHN_NUM_CHAR_COUNT = 10;
const int CHN_CHAR_LENGTH = 2;

const char *chnNumChar[CHN_NUM_CHAR_COUNT] = { "箂", "", "", "", "", "き", "せ", "", "", "" };
const char *chnUnitChar[] = { "", "", "κ", "" };
const char *chnUnitSection[] = { "", "窾", "货", "窾货" };

typedef struct 
{
    const char *name; //いゅ舦嘿
    int value; //10计
    bool secUnit; //琌琌竊舦
}CHN_NAME_VALUE;

CHN_NAME_VALUE chnValuePair[] = 
{
    { "", 10, false }, { "κ", 100, false }, { "", 1000, false }, 
    { "窾", 10000, true }, { "货", 100000000, true }
};



void SectionToChinese(unsigned int section, std::string& chnStr)
{
    chnStr.clear();
    std::string strIns;
    int unitPos = 0;
    bool zero = true;
    while(section > 0)
    {
        int v = section % 10;
        if(v == 0)
        {
            if( (section == 0) || !zero )
            {
                zero = true; /*惠璶干0zeroノ琌絋玂癸硈尿0干いゅ箂*/
                chnStr.insert(0, chnNumChar[v]);
            }
        }
        else
        {
            zero = false; //ぶΤ计ぃ琌0
            strIns = chnNumChar[v]; //じ癸莱いゅ计
            strIns += chnUnitChar[unitPos]; //癸莱いゅ舦
            chnStr.insert(0, strIns); 
        }
        unitPos++; //簿
        section = section / 10;
    }
}

//num == 0惠璶疭矪瞶钡"箂"
void NumberToChinese(unsigned int num, std::string& chnStr)
{
    chnStr.clear();
    int unitPos = 0;
    std::string strIns;
    bool needZero = false;

    if(num == 0)
    {
        chnStr = chnNumChar[0];
        return;
    }

    while(num > 0)
    {
        unsigned int section = num % 10000;
        if(needZero)
        {
            chnStr.insert(0, chnNumChar[0]);
        }
        SectionToChinese(section, strIns);
        /*琌惠璶竊舦*/
        strIns += (section != 0) ? chnUnitSection[unitPos] : chnUnitSection[0]; 
        chnStr.insert(0, strIns);
        /*琌0惠璶section干箂*/
        needZero = (section < 1000) && (section > 0); 
        num = num / 10000;
        unitPos++;
    }
}

int ChineseToValue(const std::string& chnStr)
{
    for(int val = 0; val < sizeof(chnNumChar) / sizeof(chnNumChar[0]); val++)
    {
        if(chnStr.compare(chnNumChar[val]) == 0)
        {
            return val;
        }
    }

    return -1;
}

int ChineseToUnit(const std::string& chnStr, bool& secUnit)
{
    for(int unit = 0; unit < sizeof(chnValuePair) / sizeof(chnValuePair[0]); unit++)
    {
        if(chnStr.compare(chnValuePair[unit].name) == 0)
        {
            secUnit = chnValuePair[unit].secUnit;
            return chnValuePair[unit].value;
        }
    }

    return 1;
}

unsigned int ChineseToNumber(const std::string& chnString)
{
    unsigned int rtn = 0;
    unsigned int section = 0;
    int number = 0;
    bool secUnit = false;
    std::string::size_type pos = 0;
    
    while(pos < chnString.length())
    {
        int num = ChineseToValue(chnString.substr(pos, CHN_CHAR_LENGTH));
        if(num >= 0) /*计临琌虫*/
        {
            number = num;
            pos += CHN_CHAR_LENGTH;
            if(pos >= chnString.length())//狦琌程计钡挡
            {
                section += number;
                rtn += section;
                break;
            }
        }
        else
        {
            int unit = ChineseToUnit(chnString.substr(pos, CHN_CHAR_LENGTH), secUnit);
            if(secUnit)//琌竊舦弧竊竒挡
            {
                section = (section + number) * unit;
                rtn += section;
                section = 0;
            }
            else
            {
                section += (number * unit);
            }
            number = 0;
            pos += CHN_CHAR_LENGTH;
            if(pos >= chnString.length())
            {
                rtn += section;
                break;
            }
        }
    }

    return rtn;
}

typedef struct 
{
    int num;
    const char *chnNumStr;
}TEST_DATA;

TEST_DATA testPair[] = 
{
    {0, "箂"},
    {1, ""},
    {2, ""},
    {3, ""},
    {4, ""},
    {5, "き"},
    {6, "せ"},
    {7, ""},
    {8, ""},
    {9, ""},
    {10, ""},
    {11, ""},
    {110, "κ"},
    {111, "κ"},
    {100, "κ"},
    {102, "κ箂"},
    {1020, "箂"},
    {1001, "箂"},
    {1015, "箂き"},
    {1000, ""},
    {10000, "窾"},
    {20010, "窾箂"},
    {20001, "窾箂"},
    {100000, "窾"},
    {1000000, "κ窾"},
    {10000000, "窾"},
    {100000000, "货"},
    {1000000000, "货"},
    {1000001000, "货"},
    {1000000100, "货箂κ"},
    {200010, "窾箂"},
    {2000105, "κ窾箂κ箂き"},
    {20001007, "窾箂"},
    {2000100190, "货箂窾箂κ"},
    {1040010000, "货箂窾"},
    {200012301, "货箂窾κ箂"},
    {2005010010, "货箂きκ箂窾箂"},
    {4009060200, "货箂κ箂せ窾箂κ"},
    {4294967295, "货κせ窾κき"}
};

void testNumberToChinese()
{
    std::string chnNum;

    for(int i = 0; i < sizeof(testPair)/sizeof(testPair[0]); i++)
    {
        NumberToChinese(testPair[i].num, chnNum);
        assert(strcmp(chnNum.c_str(), testPair[i].chnNumStr) == 0);
    }
}

void testChineseToNumber()
{
    for(int i = 0; i < sizeof(testPair)/sizeof(testPair[0]); i++)
    {
        unsigned int num = ChineseToNumber(testPair[i].chnNumStr);
        assert(num == testPair[i].num);
    }
}

int main(int argc, char* argv[])
{
    testNumberToChinese();
    testChineseToNumber();
	return 0;
}

